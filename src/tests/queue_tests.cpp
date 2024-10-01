#include <gtest/gtest.h>

#include <queue>

#include "../library/queue.h"

TEST(QueueTests, DefaultConstructor) {
    containers::queue<int> s21_q;
    std::queue<int> std_q;
    EXPECT_TRUE(s21_q.empty());
    EXPECT_EQ(s21_q.size(), std_q.size());
}

TEST(QueueTests, InitializerListConstructor) {
    containers::queue<int> s21_q = {1, 2, 3, 4, 5};
    std::queue<int> std_q;
    for (int i : {1, 2, 3, 4, 5}) {
        std_q.push(i);
    }
    EXPECT_EQ(s21_q.size(), std_q.size());
    EXPECT_EQ(s21_q.front(), std_q.front());
    EXPECT_EQ(s21_q.back(), std_q.back());
}

TEST(QueueTests, CopyConstructor) {
    containers::queue<int> s21_q1 = {1, 2, 3, 4, 5};
    containers::queue<int> s21_q2(s21_q1);

    std::queue<int> std_q1;
    for (int i : {1, 2, 3, 4, 5}) {
        std_q1.push(i);
    }
    std::queue<int> std_q2(std_q1);

    EXPECT_EQ(s21_q2.size(), std_q2.size());
    EXPECT_EQ(s21_q2.front(), std_q2.front());
    EXPECT_EQ(s21_q2.back(), std_q2.back());
}

TEST(QueueTests, MoveConstructor) {
    containers::queue<int> s21_q1 = {1, 2, 3, 4, 5};
    containers::queue<int> s21_q2(std::move(s21_q1));

    std::queue<int> std_q1;
    for (int i : {1, 2, 3, 4, 5}) {
        std_q1.push(i);
    }
    std::queue<int> std_q2(std::move(std_q1));

    EXPECT_EQ(s21_q2.size(), std_q2.size());
    EXPECT_EQ(s21_q2.front(), std_q2.front());
    EXPECT_EQ(s21_q2.back(), std_q2.back());
    EXPECT_TRUE(s21_q1.empty());
    EXPECT_TRUE(std_q1.empty());
}

TEST(QueueTests, MoveAssignment) {
    containers::queue<int> s21_q1 = {1, 2, 3, 4, 5};
    containers::queue<int> s21_q2;
    s21_q2 = std::move(s21_q1);

    std::queue<int> std_q1;
    for (int i : {1, 2, 3, 4, 5}) {
        std_q1.push(i);
    }
    std::queue<int> std_q2;
    std_q2 = std::move(std_q1);

    EXPECT_EQ(s21_q2.size(), std_q2.size());
    EXPECT_EQ(s21_q2.front(), std_q2.front());
    EXPECT_EQ(s21_q2.back(), std_q2.back());
    EXPECT_TRUE(s21_q1.empty());
    EXPECT_TRUE(std_q1.empty());
}

TEST(QueueTests, FrontMethod) {
    containers::queue<int> s21_q = {1, 2, 3, 4, 5};
    std::queue<int> std_q;
    for (int i : {1, 2, 3, 4, 5}) {
        std_q.push(i);
    }

    EXPECT_EQ(s21_q.front(), std_q.front());
    s21_q.pop();
    std_q.pop();
    EXPECT_EQ(s21_q.front(), std_q.front());
}

TEST(QueueTests, BackMethod) {
    containers::queue<int> s21_q = {1, 2, 3, 4, 5};
    std::queue<int> std_q;
    for (int i : {1, 2, 3, 4, 5}) {
        std_q.push(i);
    }

    EXPECT_EQ(s21_q.back(), std_q.back());
    s21_q.pop();
    std_q.pop();
    EXPECT_EQ(s21_q.back(), std_q.back());
}

TEST(QueueTests, EmptyMethod) {
    containers::queue<int> s21_q;
    std::queue<int> std_q;
    EXPECT_EQ(s21_q.empty(), std_q.empty());
    s21_q.push(1);
    std_q.push(1);
    EXPECT_EQ(s21_q.empty(), std_q.empty());
}

TEST(QueueTests, SizeMethod) {
    containers::queue<int> s21_q;
    std::queue<int> std_q;
    EXPECT_EQ(s21_q.size(), std_q.size());
    s21_q.push(1);
    std_q.push(1);
    EXPECT_EQ(s21_q.size(), std_q.size());
    s21_q.push(2);
    std_q.push(2);
    EXPECT_EQ(s21_q.size(), std_q.size());
}

TEST(QueueTests, PushMethod) {
    containers::queue<int> s21_q;
    std::queue<int> std_q;
    s21_q.push(1);
    std_q.push(1);
    EXPECT_EQ(s21_q.size(), std_q.size());
    EXPECT_EQ(s21_q.front(), std_q.front());
    EXPECT_EQ(s21_q.back(), std_q.back());
    s21_q.push(2);
    std_q.push(2);
    EXPECT_EQ(s21_q.size(), std_q.size());
    EXPECT_EQ(s21_q.front(), std_q.front());
    EXPECT_EQ(s21_q.back(), std_q.back());
}

TEST(QueueTests, PopMethod) {
    containers::queue<int> s21_q = {1, 2, 3};
    std::queue<int> std_q;
    for (int i : {1, 2, 3}) {
        std_q.push(i);
    }

    s21_q.pop();
    std_q.pop();
    EXPECT_EQ(s21_q.size(), std_q.size());
    EXPECT_EQ(s21_q.front(), std_q.front());
    s21_q.pop();
    std_q.pop();
    EXPECT_EQ(s21_q.size(), std_q.size());
    EXPECT_EQ(s21_q.front(), std_q.front());
}

TEST(QueueTests, SwapMethod) {
    containers::queue<int> s21_q1 = {1, 2, 3};
    containers::queue<int> s21_q2 = {4, 5, 6};

    std::queue<int> std_q1;
    for (int i : {1, 2, 3}) {
        std_q1.push(i);
    }

    std::queue<int> std_q2;
    for (int i : {4, 5, 6}) {
        std_q2.push(i);
    }

    s21_q1.swap(s21_q2);
    std_q1.swap(std_q2);

    EXPECT_EQ(s21_q1.front(), std_q1.front());
    EXPECT_EQ(s21_q2.front(), std_q2.front());
    EXPECT_EQ(s21_q1.back(), std_q1.back());
    EXPECT_EQ(s21_q2.back(), std_q2.back());
}