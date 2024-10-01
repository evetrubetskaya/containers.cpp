#include <gtest/gtest.h>

#include <array>
#include <iostream>

#include "../library/array.h"

TEST(ArrayTests, DefaultConstructor) {
    containers::array<int, 0> s21_arr;
    std::array<int, 0> std_arr;
    EXPECT_EQ(s21_arr.size(), std_arr.size());
    EXPECT_EQ(s21_arr.begin(), s21_arr.end());
    EXPECT_EQ(std_arr.begin(), std_arr.end());
}

TEST(ArrayTests, SizeConstructor) {
    containers::array<int, 5> s21_arr;
    std::array<int, 5> std_arr = {0};
    EXPECT_EQ(s21_arr.size(), std_arr.size());
}

TEST(ArrayTests, InitializerListConstructor) {
    containers::array<int, 5> s21_arr = {1, 2, 3, 4, 5};
    std::array<int, 5> std_arr = {1, 2, 3, 4, 5};

    EXPECT_EQ(s21_arr.size(), std_arr.size());

    for (size_t i = 0; i < s21_arr.size(); ++i) {
        EXPECT_EQ(s21_arr[i], std_arr[i]);
    }
}

TEST(ArrayTests, CopyConstructor) {
    containers::array<int, 5> s21_arr1{1, 2, 3, 4, 5};
    containers::array<int, 5> s21_arr2(s21_arr1);

    std::array<int, 5> std_arr1{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr2(std_arr1);

    EXPECT_EQ(s21_arr2.size(), std_arr2.size());
    for (size_t i = 0; i < s21_arr1.size(); ++i) {
        EXPECT_EQ(s21_arr2[i], std_arr2[i]);
    }

    s21_arr1[0] = 10;
    std_arr1[0] = 10;
    EXPECT_EQ(s21_arr2[0], std_arr2[0]);
}

TEST(ArrayTests, MoveConstructor) {
    containers::array<int, 5> s21_arr1{1, 2, 3, 4, 5};
    containers::array<int, 5> s21_arr2(std::move(s21_arr1));

    std::array<int, 5> std_arr1{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr2(std::move(std_arr1));

    EXPECT_EQ(s21_arr2.size(), std_arr2.size());
    EXPECT_EQ(s21_arr2[0], std_arr2[0]);
    EXPECT_EQ(s21_arr2[4], std_arr2[4]);
}

TEST(ArrayTests, AtMethod) {
    containers::array<int, 5> s21_arr{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_arr.at(0), std_arr.at(0));
    EXPECT_EQ(s21_arr.at(4), std_arr.at(4));
    EXPECT_THROW(s21_arr.at(5), std::out_of_range);
    EXPECT_THROW(std_arr.at(5), std::out_of_range);
}

TEST(ArrayTests, OperatorSquareBrackets) {
    containers::array<int, 5> s21_arr{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_arr[0], std_arr[0]);
    EXPECT_EQ(s21_arr[4], std_arr[4]);
}

TEST(ArrayTests, SizeMethod) {
    containers::array<int, 5> s21_arr{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_arr.size(), std_arr.size());
}

TEST(ArrayTests, FillMethod) {
    containers::array<int, 5> s21_arr;
    std::array<int, 5> std_arr;

    s21_arr.fill(7);
    std_arr.fill(7);

    for (size_t i = 0; i < s21_arr.size(); ++i) {
        EXPECT_EQ(s21_arr[i], std_arr[i]);
    }
}

TEST(ArrayTests, SwapMethod) {
    containers::array<int, 5> s21_arr1{1, 2, 3, 4, 5};
    containers::array<int, 5> s21_arr2{6, 7, 8, 9, 10};

    std::array<int, 5> std_arr1{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr2{6, 7, 8, 9, 10};

    s21_arr1.swap(s21_arr2);
    std_arr1.swap(std_arr2);

    for (size_t i = 0; i < s21_arr1.size(); ++i) {
        EXPECT_EQ(s21_arr1[i], std_arr1[i]);
        EXPECT_EQ(s21_arr2[i], std_arr2[i]);
    }
}

TEST(ArrayTests, FrontBackMethods) {
    containers::array<int, 5> s21_arr{1, 2, 3, 4, 5};
    std::array<int, 5> std_arr{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_arr.front(), std_arr.front());
    EXPECT_EQ(s21_arr.back(), std_arr.back());
}