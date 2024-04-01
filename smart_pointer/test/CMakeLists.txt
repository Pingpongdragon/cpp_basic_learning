# 创建一个测试目标
add_executable(runSharedPtrTests SharedPtrTests.cpp)
# ... 添加更多智能指针的测试目标 ...

# 链接 Google Test 和你的源文件到测试目标
target_link_libraries(runSharedPtrTests gtest gtest_main SharedPtr)
# ... 链接更多智能指针的测试目标 ...