# 首先，你需要找到 Google Test 的包
find_package(GTest REQUIRED)

# 创建一个测试目标
add_executable(runArrayTests ArrayTests.cpp)
add_executable(runVectorTests VectorTests.cpp)
# ... 添加更多的测试目标 ...

# 链接 Google Test 和你的源文件到测试目标
target_link_libraries(runArrayTests GTest::GTest GTest::Main Array)
target_link_libraries(runVectorTests GTest::GTest GTest::Main Vector)
# ... 链接更多的测试目标 ...

# 添加测试到 CTest
gtest_discover_tests(runArrayTests)
gtest_discover_tests(runVectorTests)
# ... 添加更多的测试到 CTest ...