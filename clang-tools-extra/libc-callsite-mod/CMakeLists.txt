set(LLVM_LINK_COMPONENTS
  Support
  )

add_clang_executable(libc-callsite-mod
  libc_callsite_mod.cpp
  )

clang_target_link_libraries(libc-callsite-mod
  PRIVATE
  clangAST
  clangASTMatchers
  clangBasic
  clangFrontend
  clangTooling
  clangToolingRefactoring
  )

add_subdirectory(Utils)