#ifndef SLL_HPP
#define SLL_HPP

struct Node {
    int data;
    Node* next;

    Node();         // Default constructor
    Node(int d);    // Paramaterized constructor
};

class SLL {
    public:
    Node *head, *tail;
    
    SLL();                      // Default constructor
    SLL(int size, int max);     // Paramaterized constructor
    SLL(const SLL &oldList);    // Copy constructor
    void print();
    void appendToTail(int val);
    void removeDuplicates1();                           // q01: Buffers are allowed. 
    void removeDuplicates2();                           // q01: Buffers are not allowed.
    void deleteMiddleNode(Node* node);                  // q03
    int size();
    int findKthToLast(Node* head, int k);               // q02: Recursive (size of list is not known)
    int findKthToLast(Node* head, int k, int size);     // q02: Iterative (size of list is known)
};

#endif