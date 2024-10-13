#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Rewrite/Core/Rewriter.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/Signals.h"

using namespace clang;
using namespace clang::tooling;

#include <fstream>
#include <map>
#include <string>


class FileToMapReader {
private:
  std::map<std::string, int> stringMap;

public:
  bool readFileToMap(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
      llvm::errs() << "Error opening file: " << filePath << "\n";
      return false;
    }

    std::string line;
    while (std::getline(file, line)) {
      size_t colonPos = line.find(':');
      if (colonPos != std::string::npos) {
        std::string key = line.substr(colonPos + 1);
        int value = std::stoi(line.substr(0, colonPos));
        stringMap[key] = value;
      } else {
        llvm::errs() << "Invalid line format: " << line << "\n";
      }
    }
    file.close();
    return true;
  }

  bool isStringInMap(const std::string &str) const {
    return stringMap.find(str) != stringMap.end();
  }

  int getValueFromMap(const std::string &str) const {
    auto it = stringMap.find(str);
    if (it != stringMap.end()) {
      return it->second;
    }
    return -1; // or some other sentinel value indicating not found
  }
};

Rewriter rewriter;
FileToMapReader fileToMapReader;

class ExampleVisitor : public RecursiveASTVisitor<ExampleVisitor> {
private:
    ASTContext *astContext; 

public:
    explicit ExampleVisitor(CompilerInstance *CI) 
      : astContext(&(CI->getASTContext())) // initialize private members
    {
        rewriter.setSourceMgr(astContext->getSourceManager(), astContext->getLangOpts());
    }

    virtual bool VisitStmt(Stmt *st) {  
        if (CallExpr *call = dyn_cast<CallExpr>(st)) {
            if (FunctionDecl *func = call->getDirectCallee()) {
              std::string funcName = func->getNameInfo().getName().getAsString();
              if (fileToMapReader.isStringInMap(funcName)) {
                llvm::errs() << "** Encountered libc function call " <<funcName<<"\n";
                SourceLocation startLoc = call->getBeginLoc();
                rewriter.InsertText(startLoc, "dummy_syscall(" + std::to_string(fileToMapReader.getValueFromMap(funcName)) + ");\n", true, true);
              } else {
                // llvm::errs() << "Non-libc Function call " <<funcName<<" not in libc\n";
              }
            }
        }
        return true;
    }
};


/**
 * @brief ASTConsumer to modify the AST
 */
class MyASTConsumer : public ASTConsumer {
private:
    ExampleVisitor *visitor; 
public:
  MyASTConsumer(CompilerInstance *CI) : visitor(new ExampleVisitor(CI)) {
  }

  void HandleTranslationUnit(ASTContext &Context) override {
    visitor->TraverseDecl(Context.getTranslationUnitDecl());
  }
};

/**
 * @brief Frontend action to modify the AST
 */
class MyFrontendAction : public ASTFrontendAction {
public:
  MyFrontendAction() {}

  std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef file) override {
    return std::make_unique<MyASTConsumer>(&CI);
  }

};

static llvm::cl::OptionCategory MyToolCategory("libc-callsite-mod-tool options");

/**
 * @brief Main entry point for the tool
 * 
 */
int main(int argc, const char **argv) {
    int result = 0;
    llvm::sys::PrintStackTraceOnErrorSignal(argv[0]);
    fileToMapReader.readFileToMap("/home/vaisakhps/developer/E0256-Security/Attempt-2/build-dir/llvm-project-llvmorg-18.1.8/libc_functions.txt");

    // if (fileToMapReader.isStringInMap("printf")) {
    //   llvm::errs() << "printf is in map , idx"<< fileToMapReader.getValueFromMap("printf") <<"\n";
    // } else {
    //   llvm::errs() << "printf is not in map\n";
    // }

    // if (fileToMapReader.isStringInMap("noprintf")) {
    //   llvm::errs() << "printf is in map , idx"<< fileToMapReader.getValueFromMap("noprintf") <<"\n";
    // } else {
    //   llvm::errs() << "noprintf is not in map\n";
    // }
    auto ExpectedParser = CommonOptionsParser::create(
        argc, argv, llvm::cl::getGeneralCategory(), llvm::cl::ZeroOrMore,
        "Clang-based library call site modifier tool");
    if (!ExpectedParser) {
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }
    CommonOptionsParser &Options = ExpectedParser.get();

    ClangTool Tool(Options.getCompilations(), Options.getSourcePathList());

    result = Tool.run(newFrontendActionFactory<MyFrontendAction>().get());

    for (const auto &File : Options.getSourcePathList()) {
      auto EntryOrErr = Tool.getFiles().getFile(File);
      if (EntryOrErr) {
        const FileEntry *Entry = *EntryOrErr;
        const RewriteBuffer *RewriteBuf = rewriter.getRewriteBufferFor(rewriter.getSourceMgr().getMainFileID());
        if (RewriteBuf) {
          llvm::errs() << std::string(RewriteBuf->begin(), RewriteBuf->end());
        }
      }
    }
    return result;
}