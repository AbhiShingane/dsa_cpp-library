#pragma once
#include <vector>
#include <stdexcept>

template<typename T>
class MinHeap {

private:

    std::vector<T> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyDown(int i) {

        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;

        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {

        while (i != 0 && heap[parent(i)] > heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:

    void push(T value) {

        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    T top() {

        if (heap.empty())
            throw std::runtime_error("Heap empty");

        return heap[0];
    }

    void pop() {

        if (heap.empty())
            throw std::runtime_error("Heap empty");

        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
    }

    bool empty() { return heap.empty(); }
};