#include <gtest/gtest.h>
#include "Vector.cpp"

TEST(VectorTest, TestPushBack) {
    Vector<int> vec;
    vec.PushBack(5);
    EXPECT_EQ(vec[0], 5);
    EXPECT_EQ(vec.Size(), 1);
}

TEST(VectorTest, TestPopBack) {
    Vector<int> vec;
    vec.PushBack(5);
    vec.PopBack();
    EXPECT_EQ(vec.Size(), 0);
}

TEST(VectorTest, TestEmplaceBack) {
    Vector<std::pair<int, int>> vec;
    vec.EmplaceBack(1, 2);
    EXPECT_EQ(vec[0].first, 1);
    EXPECT_EQ(vec[0].second, 2);
    EXPECT_EQ(vec.Size(), 1);
}

TEST(VectorTest, TestOperatorSquareBrackets) {
    Vector<int> vec;
    vec.PushBack(5);
    EXPECT_EQ(vec[0], 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}