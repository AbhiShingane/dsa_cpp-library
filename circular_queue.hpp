#pragma once
#include <stdexcept>

template<typename T>
class CircularQueue {

private:

    T* data;
    size_t capacity;
    int front_index;
    int rear_index;
    size_t count;

public:

    CircularQueue(size_t cap = 10) {
        capacity = cap;
        data = new T[capacity];
        front_index = 0;
        rear_index = -1;
        count = 0;
    }

    ~CircularQueue() {
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

    void enqueue(const T& value) {

        if (full())
            throw std::overflow_error("Circular queue full");

        rear_index = (rear_index + 1) % capacity;
        data[rear_index] = value;
        count++;
    }

    void dequeue() {

        if (empty())
            throw std::underflow_error("Circular queue empty");

        front_index = (front_index + 1) % capacity;
        count--;
    }

    T& front() {

        if (empty())
            throw std::underflow_error("Circular queue empty");

        return data[front_index];
    }

    T& rear() {

        if (empty())
            throw std::underflow_error("Circular queue empty");

        return data[rear_index];
    }
};