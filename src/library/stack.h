#ifndef CONTAINERS_STACK
#define CONTAINERS_STACK

#include <cstddef>

#include "vector.h"

namespace containers {
template <typename T, typename _container = containers::vector<T>>
class stack {
    using value_type = T;
    using const_reference = const T &;
    using reference = T &;
    using size_type = size_t;

   private:
    _container stack_;

   public:
    // Stack Member functions
    stack();
    stack(std::initializer_list<T> const &items);
    stack(const stack &s);
    stack(stack &&s);
    stack &operator=(stack &&s);
    ~stack();

    // Stack Element access
    const_reference top() const noexcept;

    // Stack Capacity
    bool empty() const noexcept;
    size_type size() const noexcept;

    // Stack Modifiers
    void push(const_reference value) noexcept;
    void pop() noexcept;
    void swap(stack &other) noexcept;
};
}  // namespace containers

template <typename T, typename _container>
containers::stack<T, _container>::stack() {}

template <typename T, typename _container>
containers::stack<T, _container>::stack(std::initializer_list<T> const &items) {
    for (T i : items) push(i);
    stack_.print();
}

template <typename T, typename _container>
containers::stack<T, _container>::stack(const stack &s) : stack_(s.stack_) {}

template <typename T, typename _container>
containers::stack<T, _container>::stack(stack &&s) : stack_(std::move(s.stack_)) {}

template <typename T, typename _container>
containers::stack<T, _container> &containers::stack<T, _container>::operator=(stack &&s) {
    if (this != &s) {
        stack_ = std::move(s.stack_);
    }
    return *this;
}

template <typename T, typename _container>
containers::stack<T, _container>::~stack() {}

template <typename T, typename _container>
typename containers::stack<T, _container>::const_reference containers::stack<T, _container>::top() const noexcept {
    return stack_.back();
}

template <typename T, typename _container>
bool containers::stack<T, _container>::empty() const noexcept {
    return stack_.empty();
}

template <typename T, typename _container>
size_t containers::stack<T, _container>::size() const noexcept {
    return stack_.size();
}

template <typename T, typename _container>
void containers::stack<T, _container>::pop() noexcept {
    stack_.pop_back();
}

template <typename T, typename _container>
void containers::stack<T, _container>::push(const_reference value) noexcept {
    stack_.push_back(value);
}

template <typename T, typename _container>
void containers::stack<T, _container>::swap(stack &other) noexcept {
    std::swap(stack_, other.stack_);
}

#endif