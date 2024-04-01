cmake_minimum_required(VERSION 3.10)
project(SmartPtrTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 下载并包含 Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
FetchContent_MakeAvailable(googletest)

# 添加子目录
add_subdirectory(src)
add_subdirectory(test)