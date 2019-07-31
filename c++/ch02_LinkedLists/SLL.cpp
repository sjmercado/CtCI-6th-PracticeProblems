#include <iostream>
#include "SLL.hpp"

/************************** FUNCTIONS FOR THE NODE STRUCT **************************/

/* Node default constructor. */
Node::Node() {
    data = 0;
    next = nullptr;
}

/* Node parameterized constructor. */
Node::Node(int d) {
    data = d;
    next = nullptr;
}

/*************************** FUNCTIONS FOR THE SLL CLASS ***************************/

/* SLL default constructor. */
SLL::SLL() {
    head = nullptr;
    tail = nullptr;
}

/* SLL parameterized constructor */
SLL::SLL(int size, int max) {
    // Allocate memory for the head node (which will give access to entire list).
    head = new Node();

    // Create first node.
    int val = std::rand() % max + 1;
    head->data = val;
    tail = head;

    // Create remaining nodes (if the desired size is more than 1)
    if (size > 1) {
        Node* curr = head;

        // Create new nodes with values in the range of [1, max] and append to the end of the list.
        for (int i = 1; i < size; i++) {
            val = std::rand() % max + 1;    
            Node* node = new Node(val);
            curr->next = node;
            curr = node;
        }
        tail = curr;
    }
}

/* SLL copy constructor */
SLL::SLL(const SLL &oldList) {
    // Configure the new list's head node.
    if (oldList.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = new Node();
        head->data = oldList.head->data;
    }

    Node* newListPtr = head;
    Node* oldListPtr = oldList.head->next;

    // Copy only the data values from the old list.
    while (oldListPtr != nullptr) {
        Node* newNode = new Node(oldListPtr->data);
        newListPtr->next = newNode;

        newListPtr = newListPtr->next;
        oldListPtr = oldListPtr->next;
    }
    tail = newListPtr;
}

/* Prints the contents of the linked list. 
 * Time Complexity: O(n) */
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

/* Appends a new node to the end of the linked list. 
 * Time Complexity: O(1) */
void SLL::appendToTail(int val) {
    Node* newTail = new Node(val);

    // If the list doesn't exist (i.e., head node is null), save the new node as the head.
    // Note that if there is only one node in the list, the head is the same as the tail.
    if (!head) {
        head = newTail;
        tail = head;
        return;
    }

    // Attach the new node to the end of the list, and update the tail.
    tail->next = newTail;
    tail = newTail;
}

/* Returns the size of the linked list. 
 * Time Complexity: O(n). */
int SLL::size() {
    Node* curr = head;
    int size = 0;

    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }

    return size;
}