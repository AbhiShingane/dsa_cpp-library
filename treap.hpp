#pragma once
#include <cstdlib>

template<typename T>
class Treap {

    struct Node {

        T key;
        int priority;
        Node* left;
        Node* right;

        Node(T k)
            : key(k), priority(rand()), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    Node* rotateRight(Node* y) {

        Node* x = y->left;
        y->left = x->right;
        x->right = y;

        return x;
    }

    Node* rotateLeft(Node* x) {

        Node* y = x->right;
        x->right = y->left;
        y->left = x;

        return y;
    }

    Node* insert(Node* node, T key) {

        if (!node)
            return new Node(key);

        if (key < node->key) {

            node->left = insert(node->left, key);

            if (node->left->priority > node->priority)
                node = rotateRight(node);
        }
        else {

            node->right = insert(node->right, key);

            if (node->right->priority > node->priority)
                node = rotateLeft(node);
        }

        return node;
    }

public:

    void insert(T key) {
        root = insert(root, key);
    }
};