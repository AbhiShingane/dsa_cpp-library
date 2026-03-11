#pragma once

template<typename T>
class RedBlackTree {

    enum Color { RED, BLACK };

    struct Node {

        T key;
        Color color;
        Node *left, *right, *parent;

        Node(T k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root = nullptr;

public:

    void insert(T key) {

        Node* node = new Node(key);

        if (!root) {
            node->color = BLACK;
            root = node;
            return;
        }

        Node* cur = root;
        Node* parent = nullptr;

        while (cur) {

            parent = cur;

            if (key < cur->key)
                cur = cur->left;
            else
                cur = cur->right;
        }

        node->parent = parent;

        if (key < parent->key)
            parent->left = node;
        else
            parent->right = node;
    }
};