#pragma once
#include <iostream>

template<typename T>
class BinarySearchTree {

    struct Node {
        T key;
        Node* left;
        Node* right;

        Node(T k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    Node* insert(Node* node, T key) {

        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);

        else if (key > node->key)
            node->right = insert(node->right, key);

        return node;
    }

    bool search(Node* node, T key) {

        if (!node)
            return false;

        if (node->key == key)
            return true;

        if (key < node->key)
            return search(node->left, key);

        return search(node->right, key);
    }

public:

    void insert(T key) {
        root = insert(root, key);
    }

    bool search(T key) {
        return search(root, key);
    }
};