#pragma once
#include <stdexcept>

template<typename T>
class QueueArray {

private:

    T* data;
    size_t capacity;
    int front_index;
    int rear_index;
    size_t count;

public:

    QueueArray(size_t cap = 10) {
        capacity = cap;
        data = new T[capacity];
        front_index = 0;
        rear_index = -1;
        count = 0;
    }

    ~QueueArray() {
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
            throw std::overflow_error("Queue is full");

        rear_index++;
        data[rear_index] = value;
        count++;
    }

    void dequeue() {

        if (empty())
            throw std::underflow_error("Queue is empty");

        front_index++;
        count--;
    }

    T& front() {

        if (empty())
            throw std::underflow_error("Queue is empty");

        return data[front_index];
    }

    T& rear() {

        if (empty())
            throw std::underflow_error("Queue is empty");

        return data[rear_index];
    }
};