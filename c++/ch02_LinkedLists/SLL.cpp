#include <iostream>
#include "SLL.hpp"

/************************** FUNCTIONS FOR THE NODE STRUCT **************************/

/* Node constructor. */
Node::Node(int d) {
    data = d;
    next = nullptr;
}

/*************************** FUNCTIONS FOR THE SLL CLASS ***************************/

/* SLL constructor. */
SLL::SLL() {
    head = nullptr;
    tail = nullptr;
}

/* SLL destructor. */
SLL::~SLL() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
}

/* Prints the contents of the linked list. */
void SLL::print() {
    Node* curr = head;

    std::cout << "\n";
    while (curr != nullptr) {
        std::cout << curr->data;
        if (curr->next != nullptr) 
            std::cout << " -> ";
        
        curr = curr->next;
    }
    std::cout << "\n\n";
}

/* Appends a new node to the end of the linked list. */
void SLL::appendToTail(int d) {
    Node* end = new Node(d);
    Node* curr = head;

    // If the list doesn't exist (i.e., head node is null), save the new node as the head.
    if (!head) {
        head = end;
        return;
    }

    // Traverse the list until the tail node is reached, then add the new node to the end.
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = end;
}

/* Returns the size of the linked list. Runtime = O(n). */
int SLL::size() {
    Node* curr = head;
    int size = 0;

    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }

    return size;
}