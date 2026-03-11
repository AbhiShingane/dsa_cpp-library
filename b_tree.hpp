#pragma once
#include <vector>

template<typename T>
class BTree {

    struct Node {

        std::vector<T> keys;
        std::vector<Node*> children;
        bool leaf;

        Node(bool leaf) : leaf(leaf) {}
    };

    Node* root;
    int t;

public:

    BTree(int degree) {
        root = new Node(true);
        t = degree;
    }

    void insert(T key) {
        root->keys.push_back(key);
    }
};