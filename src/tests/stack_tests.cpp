#include <gtest/gtest.h>

#include <stack>

#include "../library/stack.h"
#include "../library/vector.h"

TEST(StackTests, DefaultConstructor) {
    containers::stack<int> s21_s;
    std::stack<int> std_s;
    EXPECT_TRUE(s21_s.empty());
    EXPECT_EQ(s21_s.size(), std_s.size());
}

TEST(StackTests, InitializerListConstructor) {
    containers::stack<int> s21_s = {1, 2, 3, 4, 5};
    std::stack<int> std_s;
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        std_s.push(*it);
    }
    EXPECT_EQ(s21_s.size(), std_s.size());
    EXPECT_EQ(s21_s.top(), std_s.top());
}

TEST(StackTests, CopyConstructor) {
    containers::stack<int> s21_s1 = {1, 2, 3, 4, 5};
    containers::stack<int> s21_s2(s21_s1);

    std::stack<int> std_s1;
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        std_s1.push(*it);
    }
    std::stack<int> std_s2(std_s1);

    EXPECT_EQ(s21_s2.size(), std_s2.size());
    EXPECT_EQ(s21_s2.top(), std_s2.top());
}

TEST(StackTests, MoveConstructor) {
    containers::stack<int> s21_s1 = {1, 2, 3, 4, 5};
    containers::stack<int> s21_s2(std::move(s21_s1));

    std::stack<int> std_s1;
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        std_s1.push(*it);
    }
    std::stack<int> std_s2(std::move(std_s1));

    EXPECT_EQ(s21_s2.size(), std_s2.size());
    EXPECT_EQ(s21_s2.top(), std_s2.top());
    EXPECT_TRUE(s21_s1.empty());
    EXPECT_TRUE(std_s1.empty());
}

TEST(StackTests, MoveAssignment) {
    containers::stack<int> s21_s1 = {1, 2, 3, 4, 5};
    containers::stack<int> s21_s2;
    s21_s2 = std::move(s21_s1);

    std::stack<int> std_s1;
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        std_s1.push(*it);
    }
    std::stack<int> std_s2;
    std_s2 = std::move(std_s1);

    EXPECT_EQ(s21_s2.size(), std_s2.size());
    EXPECT_EQ(s21_s2.top(), std_s2.top());
    EXPECT_TRUE(s21_s1.empty());
    EXPECT_TRUE(std_s1.empty());
}

TEST(StackTests, TopMethod) {
    containers::stack<int> s21_s = {1, 2, 3, 4, 5};
    std::stack<int> std_s;
    std::initializer_list<int> init_list = {1, 2, 3, 4, 5};
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        std_s.push(*it);
    }

    EXPECT_EQ(s21_s.top(), std_s.top());
    s21_s.pop();
    std_s.pop();
    EXPECT_EQ(s21_s.top(), std_s.top());
}

TEST(StackTests, EmptyMethod) {
    containers::stack<int> s21_s;
    std::stack<int> std_s;
    EXPECT_EQ(s21_s.empty(), std_s.empty());
    s21_s.push(1);
    std_s.push(1);
    EXPECT_EQ(s21_s.empty(), std_s.empty());
}

TEST(StackTests, SizeMethod) {
    containers::stack<int> s21_s;
    std::stack<int> std_s;
    EXPECT_EQ(s21_s.size(), std_s.size());
    s21_s.push(1);
    std_s.push(1);
    EXPECT_EQ(s21_s.size(), std_s.size());
    s21_s.push(2);
    std_s.push(2);
    EXPECT_EQ(s21_s.size(), std_s.size());
}

TEST(StackTests, PushMethod) {
    containers::stack<int> s21_s;
    std::stack<int> std_s;
    s21_s.push(1);
    std_s.push(1);
    EXPECT_EQ(s21_s.size(), std_s.size());
    EXPECT_EQ(s21_s.top(), std_s.top());
    s21_s.push(2);
    std_s.push(2);
    EXPECT_EQ(s21_s.size(), std_s.size());
    EXPECT_EQ(s21_s.top(), std_s.top());
}

TEST(StackTests, PopMethod) {
    containers::stack<int> s21_s = {1, 2, 3};
    std::stack<int> std_s;
    std::initializer_list<int> init_list = {1, 2, 3};
    for (auto it = init_list.begin(); it != init_list.end(); ++it) {
        std_s.push(*it);
    }

    s21_s.pop();
    std_s.pop();
    EXPECT_EQ(s21_s.size(), std_s.size());
    EXPECT_EQ(s21_s.top(), std_s.top());
    s21_s.pop();
    std_s.pop();
    EXPECT_EQ(s21_s.size(), std_s.size());
    EXPECT_EQ(s21_s.top(), std_s.top());
    s21_s.pop();
    std_s.pop();
    EXPECT_TRUE(s21_s.empty());
    EXPECT_TRUE(std_s.empty());
}

TEST(StackTests, SwapMethod) {
    containers::stack<int> s21_s1 = {1, 2, 3};
    containers::stack<int> s21_s2 = {4, 5, 6};

    std::stack<int> std_s1;
    std::initializer_list<int> init_list1 = {1, 2, 3};
    for (auto it = init_list1.begin(); it != init_list1.end(); ++it) {
        std_s1.push(*it);
    }

    std::stack<int> std_s2;
    std::initializer_list<int> init_list2 = {4, 5, 6};
    for (auto it = init_list2.begin(); it != init_list2.end(); ++it) {
        std_s2.push(*it);
    }

    s21_s1.swap(s21_s2);
    std_s1.swap(std_s2);

    EXPECT_EQ(s21_s1.top(), std_s1.top());
    EXPECT_EQ(s21_s2.top(), std_s2.top());
}