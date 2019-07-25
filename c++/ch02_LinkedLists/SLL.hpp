#ifndef SLL_HPP
#define SLL_HPP

struct Node {
    int data;
    Node* next;

    Node(int d);    // Constructor
};

class SLL {
    public:
        Node *head, *tail;
    
        SLL();      // Constructor
        ~SLL();     // Destructor
        void print();
        void appendToTail(int d);
        void removeDuplicates1();                           // q01: Buffers are allowed. 
        void removeDuplicates2();                           // q01: Buffers are not allowed.
        void deleteMiddleNode(Node* node);                  // q03
        int size();
        int findKthToLast(Node* head, int k);               // q02: Recursive (size of list is not known)
        int findKthToLast(Node* head, int k, int size);     // q02: Iterative (size of list is known)
};

#endif