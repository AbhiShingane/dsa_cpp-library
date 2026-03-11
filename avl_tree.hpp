#pragma once
#include <algorithm>

template<typename T>
class AVLTree {

private:

    struct Node {
        T key;
        Node* left;
        Node* right;
        int height;

        Node(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root = nullptr;

    int height(Node* n) {
        return n ? n->height : 0;
    }

    int balance(Node* n) {
        return height(n->left) - height(n->right);
    }

    Node* rotateRight(Node* y) {

        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* rotateLeft(Node* x) {

        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, T key) {

        if (!node)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int bf = balance(node);

        if (bf > 1 && key < node->left->key)
            return rotateRight(node);

        if (bf < -1 && key > node->right->key)
            return rotateLeft(node);

        if (bf > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (bf < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

public:

    void insert(T key) {
        root = insert(root, key);
    }
};