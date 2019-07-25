/*
 * 07/15/2019
 * Samuel Mercado
 * 2.1 - Remove Duplicates
 * 
 * Description: The algorithms shown below both remove duplicates from an unsorted linked list.
 * The first solution uses the C++ standard library's std::unordered_set (i.e., a hash table)
 * as a buffer to keep track of the unique values within the list. As a follow-up exercise,
 * the second solution doesn't use a buffer -- this saves memory, but results in a slower runtime.
 * 
 * Assumption(s): None.
 */

#include <iostream>
#include <unordered_set>
#include "SLL.hpp"

using namespace std;

/*
 * The use of a hash table makes this problem much simpler since the runtime of accessing 
 * and/or finding elements within the table is constant as the number of elements grows.  
 * This function works by iterating through each node, inserting the node's data value 
 * into the hash table, and then using the hash table to check if the next node in the 
 * list is a duplicate.
 * 
 * Overall Time Complexity: O(n)
 * Additional Space Complexity: O(n)
 */
void SLL::removeDuplicates1() {
    unordered_set<int> set;
    Node* curr = head;
    cout << "Removing duplicates with a buffer..." << endl;

    while (curr->next != nullptr) {
        set.emplace(curr->data);    // Avg. runtime for emplace() is O(1).

        if (set.count(curr->next->data) > 0) {
            cout << "Duplicate found: " << curr->next->data << endl;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    cout << "All duplicates have been removed." << endl;
}

/*
 * This implementation avoids using a buffer and instead uses two pointers to iterate 
 * through the list and remove duplicates. The 'curr' pointer acts as the reference,
 * while the 'runner' pointer iterates through the remaining nodes, searching for any
 * duplicates. Once the runner has reached the end and removed any duplicates, the curr
 * pointer moves to the next node, and this process continues until curr reaches the end.
 * 
 * Overall Time Complexity: O(n^2)
 * Additional Space Complexity: O(1)
 */
void SLL::removeDuplicates2() {
    Node* curr = head;
    cout << "Removing duplicates without a buffer..." << endl;

    while (curr != nullptr) {
        Node* runner = curr;

        while (runner->next != nullptr) {
            if (runner->next->data == curr->data) {
                cout << "Duplicate found: " << runner->next->data << endl;
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
    cout << "All duplicates have been removed." << endl;
}

int main() {
    SLL list;
    int userInput;

    // Create the linked-list.
    list.appendToTail(3);
    list.appendToTail(11);
    list.appendToTail(11);
    list.appendToTail(11);
    list.appendToTail(12);
    list.appendToTail(23);
    list.appendToTail(23);
    list.print();

    cout << "Buffer allowed? (1 = Yes, 2 = No)." << "\nYour input: ";
    cin >> userInput;
    cout << endl;

    // Remove the duplicate nodes and print the resulting list.
    if (userInput == 1) list.removeDuplicates1();
    if (userInput == 2) list.removeDuplicates2();
    list.print();

    return 0;
}