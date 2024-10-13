## This is the CMakeLists.txt file for the libc-callsite-mod tool.
## It is a clang tool that finds callsites to libc functions and modifies them.
set(LLVM_LINK_COMPONENTS
  Support
  )


## Build rule for the libc-callsite-mod tool.
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

## Uility module for the libc-callsite-mod tool.
add_subdirectory(Utils)
