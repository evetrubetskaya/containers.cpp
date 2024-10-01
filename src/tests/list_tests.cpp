#include <gtest/gtest.h>

#include <list>

#include "../library/list.h"

TEST(ListTests, DefaultConstructor) {
    containers::list<int> s21_lst;
    std::list<int> std_lst;
    EXPECT_TRUE(s21_lst.empty());
    EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(ListTests, SizeConstructor) {
    containers::list<int> s21_lst(5);
    std::list<int> std_lst(5);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    auto s21_it = s21_lst.begin();
    auto std_it = std_lst.begin();
    for (; s21_it != s21_lst.end() && std_it != std_lst.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, InitializerListConstructor) {
    containers::list<int> s21_lst = {1, 2, 3, 4, 5};
    std::list<int> std_lst = {1, 2, 3, 4, 5};

    EXPECT_EQ(s21_lst.size(), std_lst.size());
    auto s21_it = s21_lst.begin();
    auto std_it = std_lst.begin();
    for (; s21_it != s21_lst.end() && std_it != std_lst.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, CopyConstructor) {
    containers::list<int> s21_lst1 = {1, 2, 3, 4, 5};
    containers::list<int> s21_lst2(s21_lst1);

    std::list<int> std_lst1 = {1, 2, 3, 4, 5};
    std::list<int> std_lst2(std_lst1);

    EXPECT_EQ(s21_lst2.size(), std_lst2.size());
    auto s21_it = s21_lst2.begin();
    auto std_it = std_lst2.begin();
    for (; s21_it != s21_lst2.end() && std_it != std_lst2.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, MoveConstructor) {
    containers::list<int> s21_lst1 = {1, 2, 3, 4, 5};
    containers::list<int> s21_lst2(std::move(s21_lst1));

    std::list<int> std_lst1 = {1, 2, 3, 4, 5};
    std::list<int> std_lst2(std::move(std_lst1));

    EXPECT_EQ(s21_lst2.size(), std_lst2.size());
    auto s21_it = s21_lst2.begin();
    auto std_it = std_lst2.begin();
    for (; s21_it != s21_lst2.end() && std_it != std_lst2.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
    EXPECT_TRUE(s21_lst1.empty());
    EXPECT_TRUE(std_lst1.empty());
}

TEST(ListTests, MoveAssignment) {
    containers::list<int> s21_lst1 = {1, 2, 3, 4, 5};
    containers::list<int> s21_lst2;
    s21_lst2 = std::move(s21_lst1);

    std::list<int> std_lst1 = {1, 2, 3, 4, 5};
    std::list<int> std_lst2;
    std_lst2 = std::move(std_lst1);

    EXPECT_EQ(s21_lst2.size(), std_lst2.size());
    auto s21_it = s21_lst2.begin();
    auto std_it = std_lst2.begin();
    for (; s21_it != s21_lst2.end() && std_it != std_lst2.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
    EXPECT_TRUE(s21_lst1.empty());
    EXPECT_TRUE(std_lst1.empty());
}

TEST(ListTests, FrontMethod) {
    containers::list<int> s21_lst = {1, 2, 3, 4, 5};
    std::list<int> std_lst = {1, 2, 3, 4, 5};

    EXPECT_EQ(s21_lst.front(), std_lst.front());
}

// Тест для метода back()
TEST(ListTests, BackMethod) {
    containers::list<int> s21_lst = {1, 2, 3, 4, 5};
    std::list<int> std_lst = {1, 2, 3, 4, 5};

    EXPECT_EQ(s21_lst.back(), std_lst.back());
}

// Тест для метода empty()
TEST(ListTests, EmptyMethod) {
    containers::list<int> s21_lst;
    std::list<int> std_lst;
    EXPECT_EQ(s21_lst.empty(), std_lst.empty());
    s21_lst.push_back(1);
    std_lst.push_back(1);
    EXPECT_EQ(s21_lst.empty(), std_lst.empty());
}

TEST(ListTests, SizeMethod) {
    containers::list<int> s21_lst;
    std::list<int> std_lst;
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    s21_lst.push_back(1);
    std_lst.push_back(1);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    s21_lst.push_back(2);
    std_lst.push_back(2);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(ListTests, PushBackMethod) {
    containers::list<int> s21_lst;
    std::list<int> std_lst;
    s21_lst.push_back(1);
    std_lst.push_back(1);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.back(), std_lst.back());
    s21_lst.push_back(2);
    std_lst.push_back(2);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.back(), std_lst.back());
}

TEST(ListTests, PushFrontMethod) {
    containers::list<int> s21_lst;
    std::list<int> std_lst;
    s21_lst.push_front(1);
    std_lst.push_front(1);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.front(), std_lst.front());
    s21_lst.push_front(2);
    std_lst.push_front(2);
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.front(), std_lst.front());
}

TEST(ListTests, PopBackMethod) {
    containers::list<int> s21_lst = {1, 2, 3};
    std::list<int> std_lst = {1, 2, 3};

    s21_lst.pop_back();
    std_lst.pop_back();
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.back(), std_lst.back());

    s21_lst.pop_back();
    std_lst.pop_back();
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.back(), std_lst.back());
}

TEST(ListTests, PopFrontMethod) {
    containers::list<int> s21_lst = {1, 2, 3};
    std::list<int> std_lst = {1, 2, 3};

    s21_lst.pop_front();
    std_lst.pop_front();
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.front(), std_lst.front());

    s21_lst.pop_front();
    std_lst.pop_front();
    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_EQ(s21_lst.front(), std_lst.front());
}

TEST(ListTests, ReverseMethod) {
    containers::list<int> s21_lst = {1, 2, 3, 4, 5};
    std::list<int> std_lst = {1, 2, 3, 4, 5};

    s21_lst.reverse();
    std_lst.reverse();

    EXPECT_EQ(s21_lst.size(), std_lst.size());
    auto s21_it = s21_lst.begin();
    auto std_it = std_lst.begin();
    for (; s21_it != s21_lst.end() && std_it != std_lst.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, InsertMethod) {
    containers::list<int> s21_lst = {1, 2, 4, 5};
    std::list<int> std_lst = {1, 2, 4, 5};

    auto s21_it = s21_lst.insert(++s21_lst.begin(), 3);
    auto std_it = std_lst.insert(++std_lst.begin(), 3);

    EXPECT_EQ(s21_lst.size(), std_lst.size());

    s21_it = s21_lst.begin();
    std_it = std_lst.begin();
    for (; s21_it != s21_lst.end() && std_it != std_lst.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, EraseMethod) {
    containers::list<int> s21_lst = {1, 2, 3, 4, 5};
    std::list<int> std_lst = {1, 2, 3, 4, 5};

    auto s21_it = ++s21_lst.begin();
    auto std_it = ++std_lst.begin();

    s21_lst.erase(s21_it);
    std_lst.erase(std_it);

    EXPECT_EQ(s21_lst.size(), std_lst.size());

    s21_it = s21_lst.begin();
    std_it = std_lst.begin();
    for (; s21_it != s21_lst.end() && std_it != std_lst.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, SwapMethod) {
    containers::list<int> s21_lst1 = {1, 2, 3};
    containers::list<int> s21_lst2 = {4, 5, 6};

    std::list<int> std_lst1 = {1, 2, 3};
    std::list<int> std_lst2 = {4, 5, 6};

    s21_lst1.swap(s21_lst2);
    std_lst1.swap(std_lst2);

    EXPECT_EQ(s21_lst1.size(), std_lst1.size());
    EXPECT_EQ(s21_lst2.size(), std_lst2.size());

    auto s21_it1 = s21_lst1.begin();
    auto std_it1 = std_lst1.begin();
    for (; s21_it1 != s21_lst1.end() && std_it1 != std_lst1.end(); ++s21_it1, ++std_it1) {
        EXPECT_EQ(*s21_it1, *std_it1);
    }

    auto s21_it2 = s21_lst2.begin();
    auto std_it2 = std_lst2.begin();
    for (; s21_it2 != s21_lst2.end() && std_it2 != std_lst2.end(); ++s21_it2, ++std_it2) {
        EXPECT_EQ(*s21_it2, *std_it2);
    }
}

TEST(ListTests, MergeWithDuplicateElementsMethod) {
    containers::list<int> s21_lst1 = {1, 2, 3};
    containers::list<int> s21_lst2 = {2, 3, 4};

    std::list<int> std_lst1 = {1, 2, 3};
    std::list<int> std_lst2 = {2, 3, 4};

    s21_lst1.merge(s21_lst2);
    std_lst1.merge(std_lst2);

    EXPECT_EQ(s21_lst1.size(), std_lst1.size());
    EXPECT_EQ(s21_lst1.front(), std_lst1.front());
    EXPECT_EQ(s21_lst1.back(), std_lst1.back());
    EXPECT_TRUE(s21_lst2.empty());
    EXPECT_TRUE(std_lst2.empty());
}

TEST(ListTests, SpliceMethod) {
    containers::list<int> s21_lst1 = {1, 2, 3};
    containers::list<int> s21_lst2 = {4, 5, 6};

    std::list<int> std_lst1 = {1, 2, 3};
    std::list<int> std_lst2 = {4, 5, 6};

    s21_lst1.splice(++s21_lst1.begin(), s21_lst2);
    std_lst1.splice(++std_lst1.begin(), std_lst2);

    EXPECT_EQ(s21_lst1.size(), std_lst1.size());
    EXPECT_EQ(s21_lst2.size(), std_lst2.size());

    auto s21_it = s21_lst1.begin();
    auto std_it = std_lst1.begin();
    for (; s21_it != s21_lst1.end() && std_it != std_lst1.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
    EXPECT_TRUE(s21_lst2.empty());
    EXPECT_TRUE(std_lst2.empty());
}

TEST(ListTests, UniqueMethod) {
    containers::list<int> s21_lst = {1, 2, 2, 3, 4, 4, 5};
    std::list<int> std_lst = {1, 2, 2, 3, 4, 4, 5};

    s21_lst.unique();
    std_lst.unique();

    EXPECT_EQ(s21_lst.size(), std_lst.size());

    auto s21_it = s21_lst.begin();
    auto std_it = std_lst.begin();
    for (; s21_it != s21_lst.end() && std_it != std_lst.end(); ++s21_it, ++std_it) {
        EXPECT_EQ(*s21_it, *std_it);
    }
}

TEST(ListTests, ClearMethod) {
    containers::list<int> s21_lst = {1, 2, 3, 4, 5};
    std::list<int> std_lst = {1, 2, 3, 4, 5};

    s21_lst.clear();
    std_lst.clear();

    EXPECT_EQ(s21_lst.size(), std_lst.size());
    EXPECT_TRUE(s21_lst.empty());
    EXPECT_TRUE(std_lst.empty());
}
