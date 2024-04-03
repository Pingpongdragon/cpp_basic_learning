#include <gtest/gtest.h>
#include "Array.cpp"

TEST(ArrayTest, TestSize) {
    Array<int, 5> arr;
    EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, TestOperatorSquareBrackets) {
    Array<int, 5> arr;
    arr[0] = 5;
    EXPECT_EQ(arr[0], 5);
}

TEST(ArrayTest, TestData) {
    Array<int, 5> arr;
    arr[0] = 5;
    EXPECT_EQ(*arr.data(), 5);
}

TEST(ArrayTest, TestCopyConstructor) {
    Array<int, 5> arr1;
    arr1[0] = 5;
    Array<int, 5> arr2(arr1);
    EXPECT_EQ(arr2[0], 5);
}

TEST(ArrayTest, TestMoveConstructor) {
    Array<int, 5> arr1;
    arr1[0] = 5;
    Array<int, 5> arr2(std::move(arr1));
    EXPECT_EQ(arr2[0], 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}