# 添加你的源文件
add_library(SharedPtr SharedPtr.cpp)
# ... 添加更多智能指针的源文件 ...
target_include_directories(SharedPtr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})