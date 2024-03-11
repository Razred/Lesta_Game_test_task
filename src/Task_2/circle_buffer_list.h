#pragma once

#include <iostream>

template<typename ItemType>
struct list {

    using value_type = ItemType;

    value_type value;
    list* next;

    list() = default;

    list(const list& other) {

        value = other.value;
        next = nullptr;
    }

    list(list&& other) {

        value = std::move(other.value);
        next = nullptr;
        other.next = nullptr;
    }

    list& operator=(const list& other) {

        value = other.value;
        next = nullptr;
        return *this;
    }

    list& operator=(list&& other) {
        value = std::move(other.value);
        next = nullptr;
        other.next = nullptr;
        return *this;
    }

};

template<typename ItemType, size_t Size>
class cycling_buffer_list {

    using value_type = ItemType;

public:
    cycling_buffer_list() {
        head_ = items;
        tail_ = items;
        length_ = 0;

        for (int i = 0; i < Size - 1; ++i) {
            items[i].next = &items[i + 1];
        }
        items[Size - 1].next = &items[0];
    }

    cycling_buffer_list(const cycling_buffer_list& other) {
        if (this->items == other.items) {
            return;
        }

        for (int i = 0; i < Size; ++i) {
            items[i] = other.items[i];
        }

        for (int i = 0; i < Size - 1; ++i) {
            items[i].next = &items[i+1];
        }
        items[Size - 1].next = &items[0];
        head_ = items + (other.head_ - other.items);
        tail_ = items + (other.tail_ - other.items);
        length_ = other.length_;

    }

    cycling_buffer_list(cycling_buffer_list&& other) {
        if (this->items == other.items) {
            return;
        }

        for (int i = 0; i < Size; ++i) {
            items[i] = std::move(other.items[i]);
        }

        for (int i = 0; i < Size - 1; ++i) {
            items[i].next = &items[i + 1];
        }
        items[Size - 1].next = &items[0];

        head_ = items + (other.head_ - other.items);
        tail_ = items + (other.tail_ - other.items);
        length_ = other.length_;

        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.length_ = 0;
    }

    cycling_buffer_list& operator=(const cycling_buffer_list& other) {
        if (this->items == other.items) {
            return *this;
        }

        for (int i = 0; i < Size; ++i) {
            items[i] = other.items[i];
        }

        for (int i = 0; i < Size - 1; ++i) {
            items[i].next = &items[i+1];
        }
        items[Size - 1].next = &items[0];

        head_ = items + (other.head_ - other.items);
        tail_ = items + (other.tail_ - other.items);
        length_ = other.length_;

        return *this;
    }

    cycling_buffer_list& operator=(cycling_buffer_list&& other) {
        if (this->items == other.items) {
            return *this;
        }

        for (int i = 0; i < Size; ++i) {
            items[i] = std::move(other.items[i]);
        }

        for (int i = 0; i < Size - 1; ++i) {
            items[i].next = &items[i + 1];
        }
        items[Size - 1] = &items[0];

        head_ = items + (other.head - other.items);
        tail_ = items + (other.tail_ - other.items);
        length_ = other.length_;

        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.length_ = 0;

        return *this;
    }

    void push(const value_type& item) {
        if (length_ == Size) {
            throw std::runtime_error("Buffer is full");
        }

        head_->value = item;
        ++length_;
        head_ = head_->next;
    }

    value_type pop() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }

        value_type ret_value = std::move(tail_->value);

        tail_ = tail_->next;
        --length_;
        return ret_value;
    }

    value_type peek() {
        if (empty()) {
            throw std::runtime_error("Buffer is empty");
        }
        return tail_->value;
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

    void clear() {
        if (items == nullptr) {
            return;
        }

        head_ = nullptr;
        tail_ = nullptr;
        length_ = 0;
    }

private:
    list<value_type> items[Size];
    list<value_type>* head_;
    list<value_type>* tail_;
    size_t length_;
};
