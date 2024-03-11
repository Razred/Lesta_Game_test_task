#pragma once

#include <iostream>

template<typename ItemType, size_t Size>
class cycling_buffer_array {

    using value_type = ItemType;

public:

    cycling_buffer_array() {
        head_ = 0;
        tail_ = 0;
        length_ = 0;
    }

    cycling_buffer_array(const cycling_buffer_array& other) {
        if (items_ == other.items_) {
            return;
        }

        for (int i = 0; i < Size; ++i) {
            items_[i] = other.items_[i];
        }

        head_ = other.head_;
        tail_ = other.tail_;
        length_ = other.length_;
    }

    cycling_buffer_array(cycling_buffer_array&& other) {
        if (items_ == other.items_) {
            return;
        }

        for (int i = 0; i < Size; ++i) {
            items_[i] = std::move(other.items_[i]);
        }

        head_ = other.head_;
        tail_ = other.tail_;
        length_ = other.length_;

        other.head_ = 0;
        other.tail_ = 0;
        other.length_ = 0;
    }

    cycling_buffer_array& operator=(const cycling_buffer_array& other) {
        if (items_ == other.items_) {
            return *this;
        }

        for (int i = 0; i < Size; ++i) {
            items_[i] = other.items_[i];
        }

        head_ = other.head_;
        tail_ = other.tail_;
        length_ = other.length_;

        return *this;
    }

    cycling_buffer_array& operator=(cycling_buffer_array&& other) {
        if (items_ == other.items_) {
            return *this;
        }

        for (int i = 0; i < Size; ++i) {
            items_[i] = std::move(other.items_[i]);
        }

        head_ = other.head_;
        tail_ = other.tail_;
        length_ = other.length_;

        other.head_ = 0;
        other.tail_ = 0;
        other.length_ = 0;

        return *this;
    }

    void push(const value_type& item) {
        if (length_ == Size) {
            throw std::runtime_error("Buffer if full");
        }
        items_[head_] = item;

        (head_ >= Size)? 0 : ++head_;
        ++length_;
    }

    value_type pop() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }
        value_type ret_value = std::move(items_[tail_]);

        (tail_ >= Size)? 0 : ++tail_;
        --length_;

        return ret_value;
    }

    value_type peek() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }

        return items_[tail_];
    }

    bool empty() {
        return length_ == 0;
    }

    size_t length() {
        return length_;
    }

    size_t size() {
        return Size;
    }


private:
    value_type items_[Size];

    size_t head_;
    size_t tail_;
    size_t length_;
};