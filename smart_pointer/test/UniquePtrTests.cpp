#include <gtest/gtest.h>
#include "UniquePtr.cpp"

TEST(UniquePtrTest, TestConstructor) {
    UniquePtr<int> ptr1(new int(5));
    EXPECT_EQ(*ptr1, 5);
}

TEST(UniquePtrTest, TestMoveConstructor) {
    UniquePtr<int> ptr1(new int(5));
    UniquePtr<int> ptr2(std::move(ptr1));
    EXPECT_EQ(*ptr2, 5);
    EXPECT_EQ(ptr1.get(), nullptr);
}

TEST(UniquePtrTest, TestMoveAssignment) {
    UniquePtr<int> ptr1(new int(5));
    UniquePtr<int> ptr2;
    ptr2 = std::move(ptr1);
    EXPECT_EQ(*ptr2, 5);
    EXPECT_EQ(ptr1.get(), nullptr);
}

TEST(UniquePtrTest, TestRelease) {
    UniquePtr<int> ptr1(new int(5));
    int* raw_ptr = ptr1.release();
    EXPECT_EQ(*raw_ptr, 5);
    EXPECT_EQ(ptr1.get(), nullptr);
    delete raw_ptr;
}

// 注意：这个测试用例应该在编译时失败，因为 UniquePtr 的拷贝构造函数已被禁用
// TEST(UniquePtrTest, TestCopyConstructor) {
//     UniquePtr<int> ptr1(new int(5));
//     UniquePtr<int> ptr2(ptr1);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}