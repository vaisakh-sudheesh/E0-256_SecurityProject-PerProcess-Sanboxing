# libc-callsite-mod

This module is part of the LLVM project and provides tools for analyzing and modifying libc call sites within the codebase.

## Overview

The `libc-callsite-mod` tool helps developers identify and modify calls to libc functions, enabling better control and optimization of these calls.

## Features

- **Callsite Identification**: Detects all call sites to libc functions.
- **Modification Capabilities**: Allows modification of detected call sites to integrate a dummy-syscall function invocation.

## Build Instructions

To build the `libc-callsite-mod` tool, follow these steps:

1. **Clone the LLVM Project Repository**:
    ```sh
    git clone https://github.com/llvm/llvm-project.git
    cd llvm-project
    ```

2. **Copy the tool source code to the Tool Directory**:
    ```sh
    cp <source-location>/libc-callsite-mod clang-tools-extra/
    ```

3. **Create a Build Directory**:
    ```sh
    mkdir build
    cd build
    ```

4. **Configure the Build with CMake**:
    ```sh
    cmake -G "Ninja" \
            -D LLVM_ENABLE_PROJECTS="clang;clang-tools-extra" \
            -D CMAKE_INSTALL_PREFIX=../install-dir/ \
            -D CMAKE_BUILD_TYPE=Release \
            -D LLVM_PARALLEL_COMPILE_JOBS=16 -D LLVM_PARALLEL_LINK_JOBS=16 \
            -D LLVM_TARGETS_TO_BUILD=X86 \
            ../llvm
    ```

5. **Build the Tool**:
    ```sh
    ninja
    ```

6. **Run the Tool**:
    ```sh
    ./libc-callsite-mod [options] <input-files>
    ```

## Implementation Details


## Design Choices


## References
[1] Clang Tutorial Part II: LibTooling Example.  July 23, 2013.  https://kevinaboos.wordpress.com/2013/07/23/clang-tutorial-part-ii-libtooling-example/ (Viewed on 12 October 2024)
[2] LibTooling. May 8, 2017. https://github.com/peter-can-write/clang-notes/blob/master/libtooling.md (Viewed on 12 October 2024)
[3] Eli Bendersky's website. Modern source-to-source transformation with Clang and libToolin. May 01, 2014.  https://eli.thegreenplace.net/2014/05/01/modern-source-to-source-transformation-with-clang-and-libtooling (Viewed on 12 October 2024)
[4] LibTooling. Clang 18.1.8 documentation. https://releases.llvm.org/18.1.8/tools/clang/docs/LibTooling.html (Viewed on 12 October 2024)
[5] Introduction to the Clang AST. Clang 18.1.8 documentation. https://releases.llvm.org/18.1.8/tools/clang/docs/IntroductionToTheClangAST.html (Viewed on 12 October 2024)
[5] How to write RecursiveASTVisitor based ASTFrontendActions. Clang 18.1.8 documentation.  https://releases.llvm.org/18.1.8/tools/clang/docs/RAVFrontendAction.html (Viewed on 12 October 2024)