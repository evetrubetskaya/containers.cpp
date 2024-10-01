#ifndef CONTAINERS_LIST
#define CONTAINERS_LIST

#include <iostream>
#include <memory>

namespace containers {
template <typename T, typename Allocator = std::allocator<T>>
class list {
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;

   private:
    struct node {
        value_type value_;
        node *prev_;
        node *next_;

        node(const_reference value, node *prev = nullptr, node *next = nullptr)
            : value_(value), prev_(prev), next_(next) {}
    };
    size_type size_ = 0;
    node *head_ = nullptr;  // pointer to the first node
    node *tail_ = nullptr;  // pointer to the next node after the last one

   public:
    class iterator {
       private:
        node *ptr_;

       public:
        iterator(node *ptr) : ptr_(ptr) {}

        reference operator*() const { return ptr_->value_; }

        iterator &operator++() {
            ptr_ = ptr_->next_;
            return *this;
        }
        iterator &operator--() {
            ptr_ = ptr_->prev_;
            return *this;
        }
        bool operator==(const iterator &other) const { return ptr_ == other.ptr_; }
        bool operator!=(const iterator &other) const { return ptr_ != other.ptr_; }
        node *get_ptr() { return ptr_; }
    };

    // List Functions
    list();
    list(size_type n);
    list(std::initializer_list<T> const &items);
    list(const list &l);
    list(list &&l);
    list &operator=(list &&l);
    list &operator=(std::initializer_list<T> const &items);
    ~list();

    // List Element access
    const_reference front() const;
    const_reference back() const;

    // List Iterators
    iterator begin() const;
    iterator end() const;

    // List Capacity
    bool empty() const noexcept;
    size_type size() const;
    size_type max_size() const noexcept;

    // List Modifiers
    void clear();
    iterator insert(iterator pos, const_reference value);
    void push_back(const_reference value);
    void push_front(const_reference value);
    void pop_back();
    void pop_front();
    void reverse();
    void erase(iterator pos);
    void swap(list &other);
    void merge(list &other);
    void splice(const iterator pos, list &other);
    void unique();

    // Other
    template <typename... Args>
    void insert_many(iterator pos, Args &&...args);

    template <typename... Args>
    void insert_many_back(Args &&...args);

    template <typename... Args>
    void insert_many_front(Args &&...args);

    void print();
};
}  // namespace containers

template <typename T, typename Allocator>
containers::list<T, Allocator>::list() {}

template <typename T, typename Allocator>
containers::list<T, Allocator>::list(size_type n) {
    for (size_type i = 0; i < n; ++i) push_back(0);
}

template <typename T, typename Allocator>
containers::list<T, Allocator>::list(std::initializer_list<T> const &items) {
    for (auto &item : items) push_back(item);
}

template <typename T, typename Allocator>
containers::list<T, Allocator>::list(const list &l) {
    for (auto &item : l) push_back(item);
}

template <typename T, typename Allocator>
containers::list<T, Allocator>::list(list &&l) : size_(l.size_), head_(l.head_), tail_(l.tail_) {
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
}

template <typename T, typename Allocator>
containers::list<T, Allocator> &containers::list<T, Allocator>::operator=(std::initializer_list<T> const &items) {
    for (auto &item : items) push_back(item);
}

template <typename T, typename Allocator>
containers::list<T, Allocator> &containers::list<T, Allocator>::operator=(list &&l) {
    clear();
    size_ = l.size_;
    head_ = l.head_;
    tail_ = l.tail_;
    l.head_ = nullptr;
    l.tail_ = nullptr;
    l.size_ = 0;
    return *this;
}

template <typename T, typename Allocator>
containers::list<T, Allocator>::~list() {
    clear();
}

template <typename T, typename Allocator>
typename containers::list<T, Allocator>::iterator containers::list<T, Allocator>::begin() const {
    return head_;
}

template <typename T, typename Allocator>
typename containers::list<T, Allocator>::iterator containers::list<T, Allocator>::end() const {
    return tail_;
}

template <typename T, typename Allocator>
typename containers::list<T, Allocator>::const_reference containers::list<T, Allocator>::front() const {
    if (empty()) {
        throw std::out_of_range("out_of_range");
    }
    return head_->value_;
}

template <typename T, typename Allocator>
typename containers::list<T, Allocator>::const_reference containers::list<T, Allocator>::back() const {
    if (empty()) {
        throw std::out_of_range("out_of_range");
    }
    return tail_->prev_->value_;
}

template <typename T, typename Allocator>
size_t containers::list<T, Allocator>::size() const {
    return size_;
}

template <typename T, typename Allocator>
bool containers::list<T, Allocator>::empty() const noexcept {
    return head_ == nullptr;
}

template <typename T, typename Allocator>
size_t containers::list<T, Allocator>::max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / (sizeof(T) * 6);
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::clear() {
    while (!empty()) {
        node *tmp = head_->next_;
        delete head_;
        head_ = tmp;
    }
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::push_back(const_reference value) {
    if (head_ == nullptr) {
        head_ = new node(value);
        tail_ = new node(value, head_);
        head_->next_ = tail_;
        ++size_;
        return;
    }
    tail_->value_ = value;  // put the value in the dummy node, which now will no longer be dummy
    tail_->next_ = new node(value, tail_);  // allocate new dummy for tail_
    tail_ = tail_->next_;                   // tail_ -> new dummy node
    ++size_;                                // ++size_
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::push_front(const_reference value) {
    if (head_ == nullptr) {
        push_back(value);
        return;
    }
    head_->prev_ = new node(value, nullptr, head_);
    head_ = head_->prev_;
    ++size_;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::pop_back() {
    if (empty()) {
        throw std::out_of_range("out_of_range");
    }
    node *temp = tail_;  // to delete of the end
    if (size_ == 1) {
        tail_ = nullptr;
        head_ = nullptr;
    } else {
        tail_ = tail_->prev_;
        tail_->value_ = tail_->prev_->value_;
        tail_->next_ = nullptr;
    }
    --size_;
    delete temp;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::pop_front() {
    if (empty()) {
        throw std::out_of_range("out_of_range");
    }
    node *temp = head_;
    if (size_ == 1) {
        tail_ = nullptr;
        head_ = nullptr;
    } else {
        head_ = head_->next_;
        head_->prev_ = nullptr;
    }
    --size_;
    delete temp;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::reverse() {
    node *curr = head_;
    node *prev = nullptr;
    node *next = nullptr;
    for (size_type i = 0; i < size_; i++) {
        next = curr->next_;  // save next element
        curr->prev_ = next;  // now it points to the next element
        curr->next_ = prev;  // now it points to the prev element
        prev = curr;         // so that in the next iteration it points to the current element
        curr = next;         // moving on to the next element
    }
    tail_ = head_;
    head_ = prev;
}

template <typename T, typename Allocator>
typename containers::list<T, Allocator>::iterator containers::list<T, Allocator>::insert(iterator pos,
                                                                           const_reference value) {
    if (begin() == pos) {
        push_front(value);
        return begin();
    }
    if (end() == pos) {
        push_back(value);
        return end();
    }
    node *curr = head_;
    node *temp = new node(value);
    iterator iter_begin = begin();
    while (iter_begin != pos) {
        curr = curr->next_;
        ++iter_begin;
    }
    temp->prev_ = curr->prev_;
    temp->next_ = curr;
    curr->prev_ = temp;
    temp->prev_->next_ = temp;
    ++size_;
    return --iter_begin;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::erase(iterator pos) {
    if (begin() == pos) {
        pop_front();
        return;
    }
    if (end() == pos) {
        pop_back();
        return;
    }
    node *curr = head_;
    iterator iter_begin = begin();
    while (iter_begin != pos) {
        curr = curr->next_;
        ++iter_begin;
    }
    curr->prev_->next_ = curr->next_;
    curr->next_->prev_ = curr->prev_;
    --size_;
    delete curr;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::swap(list &other) {
    std::swap(size_, other.size_);
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::merge(list &other) {
    if (other.size_ == 0) return;
    if (size_ == 0) {
        *this = std::move(other);
    } else {
        tail_->prev_->next_ = other.head_;
        other.head_->prev_ = tail_;

        tail_ = other.tail_;
        size_ += other.size_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::splice(const iterator pos, list &other) {
    if (other.size_ == 0) return;
    node *curr = head_;
    iterator iter_begin = begin();
    while (iter_begin != pos) {
        curr = curr->next_;
        ++iter_begin;
    }
    if (curr == head_) {
        other.tail_->next_ = head_;
        head_->prev_ = other.tail_->prev_;
        head_ = other.head_;
    } else {
        curr->prev_->next_ = other.head_;
        other.head_->prev_ = curr->prev_;
    }
    other.tail_->prev_->next_ = curr;
    curr->prev_ = other.tail_->prev_;

    size_ += other.size_;
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::unique() {
    if (empty() || head_->next_ == nullptr) return;
    for (iterator it_last = begin(); it_last != end();) {
        iterator it_next = it_last;
        ++it_next;
        if (it_next == end()) {
            break;
        }
        if (*it_last == *it_next) {
            erase(it_next);
        } else {
            ++it_last;
        }
    }
}

template <typename T, typename Allocator>
template <typename... Args>
void containers::list<T, Allocator>::insert_many(iterator pos, Args &&...args) {
    iterator first_inserted = pos;
    (..., (first_inserted = insert(first_inserted, std::forward<Args>(args))));
}

template <typename T, typename Allocator>
template <typename... Args>
void containers::list<T, Allocator>::insert_many_back(Args &&...args) {
    (push_back(args), ...);
}

template <typename T, typename Allocator>
template <typename... Args>
void containers::list<T, Allocator>::insert_many_front(Args &&...args) {
    auto iter = begin();
    ((insert(iter, std::forward<Args>(args)), --iter), ...);
}

template <typename T, typename Allocator>
void containers::list<T, Allocator>::print() {
    node *curr = head_;
    for (size_type i = 0; i < size_; ++i) {
        std::cout << curr << " | prev: " << curr->prev_ << " | next: " << curr->next_
                  << " | value: " << curr->value_ << std::endl;
        curr = curr->next_;
    }
}

#endif
