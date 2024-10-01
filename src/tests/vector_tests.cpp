#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "../library/vector.h"

TEST(VectorTests, DefaultConstructor) {
    containers::vector<int> s21_vec;
    std::vector<int> std_vec;
    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    EXPECT_EQ(s21_vec.begin(), s21_vec.end());
    EXPECT_EQ(std_vec.begin(), std_vec.end());
}

TEST(VectorTests, SizeConstructor) {
    containers::vector<int> s21_vec(5);
    std::vector<int> std_vec(5);
    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
}

TEST(VectorTests, InitializerListConstructor) {
    containers::vector<int> s21_vec = {1, 2, 3, 4, 5};
    std::vector<int> std_vec = {1, 2, 3, 4, 5};

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

// Тест для конструктора копирования
TEST(VectorTests, CopyConstructor) {
    containers::vector<int> s21_vec1{1, 2, 3, 4, 5};
    containers::vector<int> s21_vec2(s21_vec1);

    std::vector<int> std_vec1{1, 2, 3, 4, 5};
    std::vector<int> std_vec2(std_vec1);

    EXPECT_EQ(s21_vec2.size(), std_vec2.size());
    EXPECT_EQ(s21_vec2.capacity(), std_vec2.capacity());
    for (size_t i = 0; i < s21_vec1.size(); ++i) {
        EXPECT_EQ(s21_vec2[i], std_vec2[i]);
    }

    s21_vec1[0] = 10;
    std_vec1[0] = 10;
    EXPECT_EQ(s21_vec2[0], 1);
    EXPECT_EQ(std_vec2[0], 1);
}

TEST(VectorTests, MoveConstructor) {
    containers::vector<int> s21_vec1{1, 2, 3, 4, 5};
    containers::vector<int> s21_vec2(std::move(s21_vec1));

    std::vector<int> std_vec1{1, 2, 3, 4, 5};
    std::vector<int> std_vec2(std::move(std_vec1));

    EXPECT_EQ(s21_vec2.size(), std_vec2.size());
    EXPECT_EQ(s21_vec2.capacity(), std_vec2.capacity());
    EXPECT_EQ(s21_vec2[0], std_vec2[0]);
    EXPECT_EQ(s21_vec2[4], std_vec2[4]);

    EXPECT_EQ(s21_vec1.size(), std_vec1.size());
    EXPECT_EQ(s21_vec1.capacity(), std_vec1.capacity());
    EXPECT_EQ(s21_vec1.begin(), s21_vec1.end());
    EXPECT_EQ(std_vec1.begin(), std_vec1.end());
}

TEST(VectorTests, CopyAssignment) {
    containers::vector<int> s21_vec1{1, 2, 3, 4, 5};
    containers::vector<int> s21_vec2;
    s21_vec2 = s21_vec1;

    std::vector<int> std_vec1{1, 2, 3, 4, 5};
    std::vector<int> std_vec2;
    std_vec2 = std_vec1;

    EXPECT_EQ(s21_vec2.size(), std_vec2.size());
    EXPECT_EQ(s21_vec2.capacity(), std_vec2.capacity());
    for (size_t i = 0; i < s21_vec1.size(); ++i) {
        EXPECT_EQ(s21_vec2[i], std_vec2[i]);
    }

    s21_vec1[0] = 10;
    std_vec1[0] = 10;
    EXPECT_EQ(s21_vec2[0], std_vec2[0]);
}

TEST(VectorTests, MoveAssignment) {
    containers::vector<int> s21_vec1{1, 2, 3, 4, 5};
    containers::vector<int> s21_vec2;
    s21_vec2 = std::move(s21_vec1);

    std::vector<int> std_vec1{1, 2, 3, 4, 5};
    std::vector<int> std_vec2;
    std_vec2 = std::move(std_vec1);

    EXPECT_EQ(s21_vec2.size(), std_vec2.size());
    EXPECT_EQ(s21_vec2.capacity(), std_vec2.capacity());
    EXPECT_EQ(s21_vec2[0], std_vec2[0]);
    EXPECT_EQ(s21_vec2[4], std_vec2[4]);

    EXPECT_EQ(s21_vec1.size(), std_vec1.size());
    EXPECT_EQ(s21_vec1.capacity(), std_vec1.capacity());
    EXPECT_EQ(s21_vec1.begin(), s21_vec1.end());
    EXPECT_EQ(std_vec1.begin(), std_vec1.end());
}

TEST(VectorTests, AtMethod) {
    containers::vector<int> s21_vec{1, 2, 3, 4, 5};
    std::vector<int> std_vec{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_vec.at(0), std_vec.at(0));
    EXPECT_EQ(s21_vec.at(4), std_vec.at(4));
    EXPECT_THROW(s21_vec.at(5), std::out_of_range);
    EXPECT_THROW(std_vec.at(5), std::out_of_range);
}

TEST(VectorTests, OperatorSquareBrackets) {
    containers::vector<int> s21_vec{1, 2, 3, 4, 5};
    std::vector<int> std_vec{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_vec[0], std_vec[0]);
    EXPECT_EQ(s21_vec[4], std_vec[4]);
}

TEST(VectorTests, PushBack) {
    containers::vector<int> s21_vec;
    std::vector<int> std_vec;

    s21_vec.push_back(1);
    std_vec.push_back(1);
    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    EXPECT_EQ(s21_vec[0], std_vec[0]);

    s21_vec.push_back(2);
    std_vec.push_back(2);
    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    EXPECT_EQ(s21_vec[1], std_vec[1]);
}

TEST(VectorTests, SizeMethod) {
    containers::vector<int> s21_vec{1, 2, 3, 4, 5};
    std::vector<int> std_vec{1, 2, 3, 4, 5};

    EXPECT_EQ(s21_vec.size(), std_vec.size());

    s21_vec.push_back(6);
    std_vec.push_back(6);
    EXPECT_EQ(s21_vec.size(), std_vec.size());

    s21_vec.pop_back();
    std_vec.pop_back();
    EXPECT_EQ(s21_vec.size(), std_vec.size());
}

TEST(VectorTests, CapacityMethod) {
    containers::vector<int> s21_vec{1, 2, 3};
    std::vector<int> std_vec{1, 2, 3};

    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

    s21_vec.reserve(10);
    std_vec.reserve(10);
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

    s21_vec.push_back(4);
    std_vec.push_back(4);
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
}

TEST(VectorTests, MaxSizeMethod) {
    containers::vector<int> s21_vec;
    std::vector<int> std_vec;

    EXPECT_EQ(s21_vec.max_size(), std_vec.max_size());
}

TEST(VectorTests, EmptyMethod) {
    containers::vector<int> s21_vec;
    std::vector<int> std_vec;

    EXPECT_EQ(s21_vec.empty(), std_vec.empty());

    s21_vec.push_back(1);
    std_vec.push_back(1);
    EXPECT_EQ(s21_vec.empty(), std_vec.empty());
    s21_vec.clear();
    std_vec.clear();
    EXPECT_EQ(s21_vec.empty(), std_vec.empty());
}

TEST(VectorTests, ReserveMethod) {
    containers::vector<int> s21_vec{1, 2, 3};
    std::vector<int> std_vec{1, 2, 3};

    s21_vec.reserve(10);
    std_vec.reserve(10);

    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    EXPECT_EQ(s21_vec.size(), std_vec.size());

    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, ShrinkToFitMethod) {
    containers::vector<int> s21_vec{1, 2, 3};
    std::vector<int> std_vec{1, 2, 3};

    s21_vec.reserve(10);
    std_vec.reserve(10);
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

    s21_vec.shrink_to_fit();
    std_vec.shrink_to_fit();
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    EXPECT_EQ(s21_vec.size(), std_vec.size());

    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, ClearMethod) {
    containers::vector<int> s21_vec{1, 2, 3};
    std::vector<int> std_vec{1, 2, 3};

    s21_vec.clear();
    std_vec.clear();

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.empty(), std_vec.empty());
}

TEST(VectorTests, InsertMethod) {
    containers::vector<int> s21_vec{1, 2, 4, 5};
    std::vector<int> std_vec{1, 2, 4, 5};

    s21_vec.insert(s21_vec.begin() + 1, 3);
    std_vec.insert(std_vec.begin() + 1, 3);

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, PushBackCopy) {
    containers::vector<int> s21_vec;
    std::vector<int> std_vec;

    s21_vec.push_back(1);
    s21_vec.push_back(2);
    s21_vec.push_back(3);

    std_vec.push_back(1);
    std_vec.push_back(2);
    std_vec.push_back(3);

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, PushBackMove) {
    containers::vector<int> s21_vec;
    std::vector<int> std_vec;

    int s1 = 2;
    int s2 = 2;
    int s3 = 2;

    s21_vec.push_back(std::move(s1));
    s21_vec.push_back(std::move(s2));
    s21_vec.push_back(std::move(s3));

    std_vec.push_back(2);
    std_vec.push_back(2);
    std_vec.push_back(2);

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, PopBack) {
    containers::vector<int> s21_vec = {1, 2, 3};
    std::vector<int> std_vec = {1, 2, 3};

    s21_vec.pop_back();
    std_vec.pop_back();

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }

    s21_vec.pop_back();
    std_vec.pop_back();

    s21_vec.pop_back();
    std_vec.pop_back();

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
}

TEST(VectorTests, Swap) {
    containers::vector<int> s21_vec1 = {1, 2, 3};
    containers::vector<int> s21_vec2 = {4, 5};

    std::vector<int> std_vec1 = {1, 2, 3};
    std::vector<int> std_vec2 = {4, 5};

    s21_vec1.swap(s21_vec2);
    std_vec1.swap(std_vec2);

    EXPECT_EQ(s21_vec1.size(), std_vec1.size());
    EXPECT_EQ(s21_vec2.size(), std_vec2.size());
    for (size_t i = 0; i < s21_vec1.size(); ++i) {
        EXPECT_EQ(s21_vec1[i], std_vec1[i]);
    }
    for (size_t i = 0; i < s21_vec2.size(); ++i) {
        EXPECT_EQ(s21_vec2[i], std_vec2[i]);
    }
}

TEST(VectorTests, InsertMany) {
    containers::vector<int> s21_vec = {1, 2, 5};
    std::vector<int> std_vec = {1, 2, 5};

    s21_vec.insert_many(s21_vec.begin() + 2, 3, 4);
    std_vec.insert(std_vec.begin() + 2, {3, 4});

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, InsertManyBack) {
    containers::vector<int> s21_vec = {1, 2};
    std::vector<int> std_vec = {1, 2};

    s21_vec.insert_many_back(3, 4, 5);
    std_vec.insert(std_vec.end(), {3, 4, 5});

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}

TEST(VectorTests, InsertManyFront) {
    containers::vector<int> s21_vec = {4, 5};
    std::vector<int> std_vec = {4, 5};

    s21_vec.insert_many_front(1, 2, 3);
    std_vec.insert(std_vec.begin(), {1, 2, 3});

    EXPECT_EQ(s21_vec.size(), std_vec.size());
    for (size_t i = 0; i < s21_vec.size(); ++i) {
        EXPECT_EQ(s21_vec[i], std_vec[i]);
    }
}