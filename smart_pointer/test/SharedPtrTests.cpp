#include <gtest/gtest.h>
#include "SharedPtr.cpp"

TEST(SharedPtrTest, TestConstructor) {
    SharedPtr<int> ptr1(new int(5));
    EXPECT_EQ(*ptr1, 5);
    EXPECT_EQ(ptr1.use_count(), 1);
}

TEST(SharedPtrTest, TestCopyConstructor) {
    SharedPtr<int> ptr1(new int(5));
    SharedPtr<int> ptr2(ptr1);
    EXPECT_EQ(*ptr2, 5);
    EXPECT_EQ(ptr2.get(), ptr1.get());
    EXPECT_EQ(ptr1.use_count(), 2);
    EXPECT_EQ(ptr2.use_count(), 2);
}

TEST(SharedPtrTest, TestMoveConstructor) {
    SharedPtr<int> ptr1(new int(5));
    SharedPtr<int> ptr2(ptr1);
    SharedPtr<int> ptr3(std::move(ptr1));
    EXPECT_EQ(*ptr3, 5);
    EXPECT_EQ(ptr3.get(), ptr2.get());
    EXPECT_EQ(ptr1.get(), nullptr);
    EXPECT_EQ(ptr2.use_count(), 2);
    EXPECT_EQ(ptr3.use_count(), 2);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}