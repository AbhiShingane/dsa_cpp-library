#pragma once
#include <iostream>

template<typename T>
class SinglyLinkedList {

private:

    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;

public:

    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    void push_front(T value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
    }

    void push_back(T value) {

        Node* node = new Node(value);

        if (!head) {
            head = node;
            return;
        }

        Node* curr = head;

        while (curr->next)
            curr = curr->next;

        curr->next = node;
    }

    bool search(T value) {

        Node* curr = head;

        while (curr) {
            if (curr->data == value)
                return true;

            curr = curr->next;
        }

        return false;
    }

    void print() {

        Node* curr = head;

        while (curr) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }

        std::cout << std::endl;
    }
};