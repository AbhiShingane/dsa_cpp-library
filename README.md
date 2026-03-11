# 📚 DSA C++ Library

A **production-style C++ implementation of fundamental and advanced Data Structures** commonly asked in **software engineering interviews and used in real systems**.

This repository contains **clean, modular, header-only implementations** of major data structures including trees, graphs, heaps, hashing, queues, stacks, and advanced structures like **AVL Trees, Red-Black Trees, Treaps, Segment Trees, Fenwick Trees, and LRU Cache**.

The goal of this project is to create a **comprehensive DSA reference library** implemented in **modern C++**.

---

# 🚀 Features

- Clean **header-only implementations**
- **Template-based structures** where applicable
- Organized **modular repository structure**
- Covers **core + advanced data structures**
- Designed for **DSA learning, interviews, and reference**
- Minimal external dependencies

---

# 📂 Repository Structure


dsa-cpp/
│
├── README.md
├── CMakeLists.txt
├── LICENSE
│
├── include/
│ ├── common/
│ │ ├── node.hpp
│ │ └── utilities.hpp
│ │
│ ├── arrays/
│ │ └── dynamic_array.hpp
│ │
│ ├── linked_list/
│ │ ├── singly_linked_list.hpp
│ │ ├── doubly_linked_list.hpp
│ │ └── circular_linked_list.hpp
│ │
│ ├── stack/
│ │ ├── stack_array.hpp
│ │ ├── stack_linkedlist.hpp
│ │ └── min_stack.hpp
│ │
│ ├── queue/
│ │ ├── queue_array.hpp
│ │ ├── circular_queue.hpp
│ │ └── deque.hpp
│ │
│ ├── hash/
│ │ ├── hash_map_chaining.hpp
│ │ └── hash_map_open_addressing.hpp
│ │
│ ├── heap/
│ │ ├── min_heap.hpp
│ │ └── max_heap.hpp
│ │
│ ├── tree/
│ │ ├── binary_tree.hpp
│ │ ├── binary_search_tree.hpp
│ │ ├── avl_tree.hpp
│ │ ├── red_black_tree.hpp
│ │ ├── treap.hpp
│ │ ├── b_tree.hpp
│ │ ├── segment_tree.hpp
│ │ ├── fenwick_tree.hpp
│ │ └── trie.hpp
│ │
│ ├── graph/
│ │ ├── graph_adj_list.hpp
│ │ └── disjoint_set_union.hpp
│ │
│ └── advanced/
│ ├── lru_cache.hpp
│ └── sparse_table.hpp
│
├── src/
│ └── main.cpp
│
└── tests/
└── ds_tests.cpp

---

# 📦 Implemented Data Structures

## Arrays

### Dynamic Array

File:


arrays/dynamic_array.hpp


Features:

- Dynamic resizing
- Push / Pop operations
- Index access
- Amortized **O(1)** insert

---

# 🔗 Linked Lists

Files:


linked_list/
├── singly_linked_list.hpp
├── doubly_linked_list.hpp
└── circular_linked_list.hpp


Supported operations:

- Insert at front
- Insert at back
- Delete nodes
- Traversal
- Search

---

# 📚 Stack

Files:


stack/
├── stack_array.hpp
├── stack_linkedlist.hpp
└── min_stack.hpp


Operations:

- push
- pop
- top
- isEmpty
- size

### Min Stack

Supports retrieving **minimum element in O(1)**.

---

# 🚶 Queue

Files:


queue/
├── queue_array.hpp
├── circular_queue.hpp
└── deque.hpp


### Queue (Array Implementation)

Operations:

- enqueue
- dequeue
- front
- rear

### Circular Queue

Uses circular indexing:


index = (index + 1) % capacity


Prevents unused array space.

### Deque (Double Ended Queue)

Supports:

- push_front
- push_back
- pop_front
- pop_back

---

# 🗂 Hash Maps

Files:


hash/
├── hash_map_chaining.hpp
└── hash_map_open_addressing.hpp


Techniques implemented:

- **Separate Chaining**
- **Open Addressing**

---

# 🏗 Heap

Files:


heap/
├── min_heap.hpp
└── max_heap.hpp


Operations:

- insert
- extractMin / extractMax
- heapify
- peek
- size

Time Complexity:

| Operation | Complexity |
|----------|------------|
| Insert | O(log n) |
| Extract | O(log n) |
| Peek | O(1) |

---

# 🌳 Trees

The repository contains implementations of **many tree data structures used in interviews and real systems**.

---

## Binary Tree

File:


tree/binary_tree.hpp


Traversal Algorithms:

- Preorder
- Inorder
- Postorder
- Level Order

---

## Binary Search Tree (BST)

File:


tree/binary_search_tree.hpp


Operations:

- Insert
- Search

Time Complexity:

| Operation | Average | Worst |
|----------|--------|------|
| Insert | O(log n) | O(n) |
| Search | O(log n) | O(n) |

---

## AVL Tree

File:


tree/avl_tree.hpp


Self-balancing BST using rotations.

Rotations implemented:

- Left rotation
- Right rotation
- Left-Right rotation
- Right-Left rotation

Time Complexity:


Insert: O(log n)
Search: O(log n)
Delete: O(log n)


---

## Red-Black Tree

File:


tree/red_black_tree.hpp


Balanced binary search tree with color properties.

Properties:

1. Root is black  
2. Red nodes cannot have red children  
3. Every path has same number of black nodes  

Used internally in:

- `std::map`
- `std::set`

---

## Treap

File:


tree/treap.hpp


Combination of:

- **Binary Search Tree**
- **Heap**

Each node has:


(key, priority)


Used in randomized balanced trees.

---

## B Tree

File:


tree/b_tree.hpp


Multi-way search tree used in:

- Databases
- Filesystems
- Storage engines

Supports efficient disk-based operations.

---

## Segment Tree

File:


tree/segment_tree.hpp


Supports efficient range queries.

Operations:

- Build tree
- Range sum query
- Update

Time Complexity:

| Operation | Complexity |
|----------|------------|
| Build | O(n) |
| Query | O(log n) |
| Update | O(log n) |

---

## Fenwick Tree (Binary Indexed Tree)

File:


tree/fenwick_tree.hpp


Efficient prefix sum data structure.

Operations:

- update
- prefix sum query

Time Complexity:


Update: O(log n)
Query: O(log n)


---

## Trie

File:


tree/trie.hpp


Efficient structure for string storage and prefix queries.

Operations:

- insert word
- search word
- prefix lookup

Used in:

- autocomplete
- dictionary lookup
- search engines

---

# 🌐 Graph

Files:


graph/
├── graph_adj_list.hpp
└── disjoint_set_union.hpp


---

## Graph (Adjacency List)

Supports:

- add edge
- print graph

Efficient representation for sparse graphs.

---

## Disjoint Set Union (Union-Find)

File:


graph/disjoint_set_union.hpp


Optimizations implemented:

- Path Compression
- Union by Rank

Operations:

- find
- union

Used in algorithms like:

- Kruskal's MST
- Connected Components
- Cycle Detection

---

# ⚡ Advanced Data Structures

Files:


advanced/
├── lru_cache.hpp
└── sparse_table.hpp


---

## LRU Cache

Implements **Least Recently Used cache** using:

- Hash Map
- Doubly Linked List

Time Complexity:

| Operation | Complexity |
|----------|------------|
| get | O(1) |
| put | O(1) |

---

## Sparse Table

Used for **static range queries**.

Typical uses:

- Range Minimum Query (RMQ)
- Range GCD

Time Complexity:

| Operation | Complexity |
|----------|------------|
| Build | O(n log n) |
| Query | O(1) |

---

# 🛠 Build Instructions

This project uses **CMake**.

### Build


mkdir build
cd build
cmake ..
make


### Run


./main


---

# 🧪 Tests

Tests are located in:


tests/ds_tests.cpp


You can add unit tests for each data structure.

---

# 📈 Learning Goals

This repository helps practice:

- Data Structures for **Coding Interviews**
- Understanding **internal implementations**
- Writing **clean modular C++ code**
- Implementing **advanced tree structures**

---

# 📌 Future Improvements

Planned additions:

- Graph Algorithms
  - BFS
  - DFS
  - Dijkstra
  - Kruskal
  - Topological Sort

- Advanced Structures
  - Skip List
  - Fibonacci Heap
  - Order Statistic Tree

---

# 📜 License

This project is licensed under the **MIT License**.

---

# ⭐ Contributions

Contributions are welcome!

If you'd like to improve the implementations or add more structures:

1. Fork the repository
2. Create a new branch
3. Submit a pull request

---

# 👨‍💻 Author

Developed as a **comprehensive C++ Data Structures reference repository** for learning and interview pre