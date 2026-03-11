#pragma once
#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t length;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];

        for (size_t i = 0; i < length; i++)
            newData[i] = data[i];

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(size_t cap = 4) {
        capacity = cap;
        length = 0;
        data = new T[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (length == capacity)
            resize(capacity * 2);

        data[length++] = value;
    }

    void pop_back() {
        if (length == 0)
            throw std::out_of_range("Array empty");

        length--;
    }

    T& operator[](size_t index) {
        if (index >= length)
            throw std::out_of_range("Index out of range");

        return data[index];
    }

    size_t size() const { return length; }

    size_t getCapacity() const { return capacity; }
};