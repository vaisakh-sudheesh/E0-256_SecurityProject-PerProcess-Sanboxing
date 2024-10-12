include(${CMAKE_CURRENT_LIST_DIR}/Common.cmake)

set(CMAKE_SYSTEM_PROCESSOR "x86_64" CACHE STRING "")
set(CMAKE_ASM_COMPILER_TARGET "x86_64-linux-android21" CACHE STRING "")
set(CMAKE_C_COMPILER_TARGET   "x86_64-linux-android21" CACHE STRING "")
set(CMAKE_CXX_COMPILER_TARGET "x86_64-linux-android21" CACHE STRING "")
set(ANDROID_NATIVE_API_LEVEL 21 CACHE STRING "")