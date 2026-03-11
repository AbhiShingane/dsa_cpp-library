#include <iostream>
#include <cassert>

#include "../include/arrays/dynamic_array.hpp"
#include "../include/queue/circular_queue.hpp"
#include "../include/heap/min_heap.hpp"
#include "../include/tree/fenwick_tree.hpp"
#include "../include/tree/trie.hpp"
#include "../include/graph/disjoint_set_union.hpp"

void test_dynamic_array() {

    DynamicArray<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    assert(arr.size() == 3);
    assert(arr[0] == 1);
    assert(arr[2] == 3);

    std::cout << "DynamicArray test passed\n";
}

void test_circular_queue() {

    CircularQueue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);

    assert(q.front() == 10);

    q.dequeue();

    assert(q.front() == 20);

    std::cout << "CircularQueue test passed\n";
}

void test_min_heap() {

    MinHeap<int> heap;

    heap.push(30);
    heap.push(10);
    heap.push(20);

    assert(heap.top() == 10);

    heap.pop();

    assert(heap.top() == 20);

    std::cout << "MinHeap test passed\n";
}

void test_fenwick_tree() {

    FenwickTree ft(5);

    ft.update(1,5);
    ft.update(2,3);
    ft.update(3,7);

    assert(ft.query(3) == 15);

    std::cout << "FenwickTree test passed\n";
}

void test_trie() {

    Trie trie;

    trie.insert("hello");
    trie.insert("hell");

    assert(trie.search("hello") == true);
    assert(trie.search("hell") == true);
    assert(trie.search("hel") == false);

    std::cout << "Trie test passed\n";
}

void test_dsu() {

    DisjointSetUnion dsu(5);

    dsu.unite(0,1);
    dsu.unite(1,2);

    assert(dsu.find(0) == dsu.find(2));

    std::cout << "DSU test passed\n";
}

int main() {

    std::cout << "Running Data Structure Tests...\n\n";

    test_dynamic_array();
    test_circular_queue();
    test_min_heap();
    test_fenwick_tree();
    test_trie();
    test_dsu();

    std::cout << "\nAll tests passed successfully!\n";

    return 0;
}