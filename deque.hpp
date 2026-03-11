#pragma once
#include <stdexcept>

template<typename T>
class Deque {

private:

    T* data;
    size_t capacity;
    int front_index;
    int rear_index;
    size_t count;

public:

    Deque(size_t cap = 10) {
        capacity = cap;
        data = new T[capacity];
        front_index = -1;
        rear_index = 0;
        count = 0;
    }

    ~Deque() {
        delete[] data;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == capacity;
    }

    size_t size() const {
        return count;
    }

    void push_front(const T& value) {

        if (full())
            throw std::overflow_error("Deque full");

        if (front_index == -1) {
            front_index = rear_index = 0;
        }
        else if (front_index == 0)
            front_index = capacity - 1;
        else
            front_index--;

        data[front_index] = value;
        count++;
    }

    void push_back(const T& value) {

        if (full())
            throw std::overflow_error("Deque full");

        if (front_index == -1) {
            front_index = rear_index = 0;
        }
        else if (rear_index == capacity - 1)
            rear_index = 0;
        else
            rear_index++;

        data[rear_index] = value;
        count++;
    }

    void pop_front() {

        if (empty())
            throw std::underflow_error("Deque empty");

        if (front_index == rear_index) {
            front_index = rear_index = -1;
        }
        else if (front_index == capacity - 1)
            front_index = 0;
        else
            front_index++;

        count--;
    }

    void pop_back() {

        if (empty())
            throw std::underflow_error("Deque empty");

        if (front_index == rear_index) {
            front_index = rear_index = -1;
        }
        else if (rear_index == 0)
            rear_index = capacity - 1;
        else
            rear_index--;

        count--;
    }

    T& front() {

        if (empty())
            throw std::underflow_error("Deque empty");

        return data[front_index];
    }

    T& back() {

        if (empty())
            throw std::underflow_error("Deque empty");

        return data[rear_index];
    }
};