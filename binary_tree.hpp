#pragma once
#include <iostream>
#include <queue>

template<typename T>
class BinaryTree {

public:

    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    void preorder(Node* node) {
        if (!node) return;

        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node) return;

        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;

        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    void level_order() {

        if (!root) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            Node* cur = q.front();
            q.pop();

            std::cout << cur->data << " ";

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
};