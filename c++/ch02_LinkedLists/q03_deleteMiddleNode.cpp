/*
 * 07/25/2019
 * Samuel Mercado
 * 2.3 - Delete Middle Node
 * 
 * Description: Implements an algorithm to delete a node in the middle of a singly linked list.
 * 
 * Assumption(s): The node to be deleted can be any node but the first & last nodes of the list,
 * and doesn't necessarily have to be the exact middle node of the list.
 */

#include <iostream>
#include "SLL.hpp"

using namespace std;

/*
 * The solution to this problem is very simple as it executes with a constant runtime and no 
 * additional space complexity. First, the node given as input is checked to verify that it
 * exists and is not the last node of the list. Then, the node's data value is overwritten with the
 * value of the following node, and then the next node is removed from the list.
 * 
 * Overall Time Complexity: O(1)
 * Additional Space Complexity: None
 */
void SLL::deleteMiddleNode(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        cout << "ERROR: Incorrect input. Cannot delete null nodes or the last node of a list." << endl;
        return;
    }

    node->data = node->next->data;
    node->next = node->next->next;
    cout << "Successfully deleted the middle node." << endl;
}

int main() {
    SLL list;

    // Create the linked-list.
    list.appendToTail(3);
    list.appendToTail(7);
    list.appendToTail(11);
    list.appendToTail(21);
    list.appendToTail(23);
    list.print();

    // Find a node in the list to test the deleteMiddleNode() function, then print the results.
    Node* head = list.head;
    Node* middleNode = head->next->next->next;
    cout << "Attempting to delete node with value: " << middleNode->data << endl;
    list.deleteMiddleNode(middleNode);
    list.print();

    return 0;
}
