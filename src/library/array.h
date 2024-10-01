#ifndef CONTAINERS_ARRAY
#define CONTAINERS_ARRAY

#include <stddef.h>

#include <iostream>

namespace containers {
template <typename T, size_t _size>
class array {
    using size_type = size_t;
    using const_reference = const T&;
    using reference = T&;

   private:
    T* data_;
    size_type size_ = _size;
    std::allocator<T> allocator_;

   public:
    // Iterator
    class iterator {
       private:
        T* ptr_;

       public:
        iterator(T* ptr) : ptr_(ptr) {}
        reference operator*() const { return *ptr_; }
        iterator& operator++() {
            ++ptr_;
            return *this;
        }
        iterator& operator--() {
            --ptr_;
            return *this;
        }
        iterator operator+(std::ptrdiff_t n) { return iterator(ptr_ + n); }
        iterator operator-(std::ptrdiff_t n) { return iterator(ptr_ - n); }
        bool operator>(const iterator& other) const { return ptr_ > other.ptr_; }
        bool operator>=(const iterator& other) const { return ptr_ >= other.ptr_; }
        bool operator<(const iterator& other) const { return ptr_ < other.ptr_; }
        bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }
        T* get_ptr() { return ptr_; }
    };

    // Array Member functions
    array();
    array(std::ptrdiff_t n);
    array(const std::initializer_list<T>& items);
    array(const array& other);
    array(array&& other);
    ~array();
    array& operator=(const array& right);
    array& operator=(array&& right);

    // Array Element access
    reference at(size_type pos);
    reference operator[](size_type pos);
    const_reference front() const;
    const_reference back() const;

    // Array Iterators
    iterator begin() const;
    iterator end() const;

    // Array Capacity
    bool empty() const noexcept;
    constexpr size_type size() const noexcept;
    constexpr size_type max_size() const noexcept;
    
    // Array Modifiers
    void swap(array& other);
    void fill(const_reference value);
};
}  // namespace containers

template <typename T, size_t _size>
containers::array<T, _size>::array() {
    data_ = allocator_.allocate(size_);
}

template <typename T, size_t _size>
containers::array<T, _size>::array(std::ptrdiff_t n) : size_(n) {
    if (n < 0) {
        throw std::length_error("length_error");
    }
    data_ = allocator_.allocate(n);
}

template <typename T, size_t _size>
containers::array<T, _size>::array(const std::initializer_list<T>& items) {
    size_ = items.size();
    data_ = allocator_.allocate(size_);
    std::copy(items.begin(), items.end(), data_);
}

template <typename T, size_t _size>
containers::array<T, _size>::array(const array& other) : size_(other.size_) {
    data_ = allocator_.allocate(size_);
    std::memcpy(data_, other.data_, size_ * sizeof(T));
}

template <typename T, size_t _size>
containers::array<T, _size>::array(array&& other) : data_(other.data_), size_(other.size_) {
    other.size_ = 0;
    other.data_ = nullptr;
}

template <typename T, size_t _size>
containers::array<T, _size>::~array() {
    if (data_) {
        allocator_.deallocate(data_, size_);
    }
}

template <typename T, size_t _size>
containers::array<T, _size>& containers::array<T, _size>::operator=(const array& right) {
    if (this != &right) {
        allocator_.deallocate(data_, size_);
        for (size_type i = 0; i < size_; i++) {
            (data_ + i)->~T();
        }
        size_ = right.size_;
        data_ = allocator_.allocate(size_);
    }
    return *this;
}

template <typename T, size_t _size>
containers::array<T, _size>& containers::array<T, _size>::operator=(array&& right) {
    if (this != &right) {
        allocator_.deallocate(data_);
        for (size_type i = 0; i < size_; i++) {
            (data_ + i)->~T();
        }
        size_ = right.size_;
        data_ = right.data_;
        right.size_ = 0;
        right.data_ = nullptr;
    }
    return *this;
}

template <typename T, size_t _size>
typename containers::array<T, _size>::reference containers::array<T, _size>::at(size_type pos) {
    if (pos >= size_ || pos < 0) throw std::out_of_range("out_of_range");
    return data_[pos];
}

template <typename T, size_t _size>
typename containers::array<T, _size>::reference containers::array<T, _size>::operator[](size_type pos) {
    return at(pos);
}

template <typename T, size_t _size>
typename containers::array<T, _size>::const_reference containers::array<T, _size>::front() const {
    return data_[0];
}

template <typename T, size_t _size>
typename containers::array<T, _size>::const_reference containers::array<T, _size>::back() const {
    return data_[size_ - 1];
}

template <typename T, size_t _size>
typename containers::array<T, _size>::iterator containers::array<T, _size>::begin() const {
    return data_;
}

template <typename T, size_t _size>
typename containers::array<T, _size>::iterator containers::array<T, _size>::end() const {
    return data_ + size_;
}

template <typename T, size_t _size>
constexpr size_t containers::array<T, _size>::size() const noexcept {
    return size_;
}

template <typename T, size_t _size>
constexpr size_t containers::array<T, _size>::max_size() const noexcept {
    return size_;
}

template <typename T, size_t _size>
bool containers::array<T, _size>::empty() const noexcept {
    return begin() == end();
}

template <typename T, size_t _size>
void containers::array<T, _size>::swap(array& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
}

template <typename T, size_t _size>
void containers::array<T, _size>::fill(const_reference value) {
    for (size_type i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}

#endif
