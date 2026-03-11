#pragma once
#include <unordered_map>

class Trie {

    struct Node {
        std::unordered_map<char,Node*> children;
        bool end = false;
    };

    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(const std::string& word) {

        Node* cur = root;

        for(char c : word) {

            if(!cur->children[c])
                cur->children[c] = new Node();

            cur = cur->children[c];
        }

        cur->end = true;
    }

    bool search(const std::string& word) {

        Node* cur = root;

        for(char c : word) {

            if(!cur->children.count(c))
                return false;

            cur = cur->children[c];
        }

        return cur->end;
    }
};