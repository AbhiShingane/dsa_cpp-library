#include <iostream>
#include <vector>

#include "../include/arrays/dynamic_array.hpp"
#include "../include/linked_list/singly_linked_list.hpp"
#include "../include/stack/stack_array.hpp"
#include "../include/queue/queue_array.hpp"
#include "../include/heap/min_heap.hpp"
#include "../include/tree/binary_search_tree.hpp"
#include "../include/tree/trie.hpp"
#include "../include/graph/graph_adj_list.hpp"
#include "../include/graph/disjoint_set_union.hpp"

int main() {

    std::cout << "===== Dynamic Array =====" << std::endl;

    DynamicArray<int> arr;

    for (int i = 1; i <= 5; i++)
        arr.push_back(i);

    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";

    std::cout << "\n\n";


    std::cout << "===== Singly Linked List =====" << std::endl;

    SinglyLinkedList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.print();

    std::cout << "\n";


    std::cout << "===== Stack =====" << std::endl;

    StackArray<int> stack(10);

    stack.push(5);
    stack.push(10);
    stack.push(15);

    std::cout << "Top: " << stack.top() << std::endl;

    stack.pop();

    std::cout << "Top after pop: " << stack.top() << std::endl;

    std::cout << "\n";


    std::cout << "===== Queue =====" << std::endl;

    QueueArray<int> q(10);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Front: " << q.front() << std::endl;

    q.dequeue();

    std::cout << "Front after dequeue: " << q.front() << std::endl;

    std::cout << "\n";


    std::cout << "===== Min Heap =====" << std::endl;

    MinHeap<int> heap;

    heap.push(10);
    heap.push(5);
    heap.push(20);

    std::cout << "Min: " << heap.top() << std::endl;

    heap.pop();

    std::cout << "Min after pop: " << heap.top() << std::endl;

    std::cout << "\n";


    std::cout << "===== Binary Search Tree =====" << std::endl;

    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::cout << "Search 40: " << bst.search(40) << std::endl;

    std::cout << "\n";


    std::cout << "===== Trie =====" << std::endl;

    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    std::cout << "Search apple: " << trie.search("apple") << std::endl;
    std::cout << "Search app: " << trie.search("app") << std::endl;
    std::cout << "Search ap: " << trie.search("ap") << std::endl;

    std::cout << "\n";


    std::cout << "===== Graph =====" << std::endl;

    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(3,4);

    g.print();

    std::cout << "\n";


    std::cout << "===== Disjoint Set Union =====" << std::endl;

    DisjointSetUnion dsu(5);

    dsu.unite(0,1);
    dsu.unite(1,2);

    std::cout << "Find(0): " << dsu.find(0) << std::endl;
    std::cout << "Find(2): " << dsu.find(2) << std::endl;

    std::cout << "\n";

    std::cout << "Program completed successfully." << std::endl;

    return 0;
}