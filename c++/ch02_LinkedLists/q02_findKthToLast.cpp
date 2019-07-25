/*
 * 07/19/2019
 * Samuel Mercado
 * 2.2 - Return Kth to Last
 * 
 * Description: Both of the functions below find and print the kth-to-last element of a
 * linked list, where k is an integer defined by the user. The first implementation uses
 * recursion, while the second uses iteration. 
 * 
 * Assumption(s): k = 1 refers to the last element, k = 2 refers to the second to last,
 * and so on.
 */

#include <iostream>
#include "SLL.hpp"

using namespace std;

/*
 * Finds the kth-to-last element of a linked list using recursion. Rather than returning the 
 * data contained by the desired node, a count value is recursively returned through the calls.
 * This is accomplished by recursing through each node until the end (nullptr) has been reached, 
 * which starts the count at 0. Then this count value is passed back through the call stack and
 * increases with each pass. Once this count value is equivalent to the 'k' value, the data 
 * contained by the corresponding node is printed to the terminal.
 * 
 * Return Value: A count value that begins counting once the end of the list is reached, and is 
 * incremented with each pass "up" through the list until reaching the first node.
 * 
 * Overall Time Complexity: O(n)
 * Additional Space Complexity: O(n)
 */
int SLL::findKthToLast(Node* head, int k) {
    // Base Case
    if (head == nullptr)
        return 0;

    // Recursive Step
    int index = findKthToLast(head->next, k) + 1;

    if (index == k)
        cout << "With k = " << k << ", the kth to last element is: " << head->data << "\n" << endl;

    return index;
}

/*
 * Finds the kth-to-last element of a linked list using iteration. Since the size of the list
 * is known, this solution becomes very trivial because all we need to do is iterate through
 * the list until the calculated index has been reached. Although this works, other approaches 
 * may be desired in situations where the size is unknown.
 * 
 * Return Value: The data contained by the kth-to-last node of the list.
 * 
 * Overall Time Complexity: O(n)
 * Additional Space Complexity: None
 */
int SLL::findKthToLast(Node* head, int k, int size) {
    int index = size - k;

    for (int i = 0; i != index; i++)
        head = head->next;

    return head->data;
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

    Node* head = list.head;
    int k;

    /*** USE THE CODE BELOW FOR THE RECURSIVE ALGORITHM (SIZE IS NOT KNOWN) ***/
    // while (k != -1) {
    //     cout << "Enter the value for 'k' to find the kth-to-last element of the list (-1 = quit): ";
    //     cin >> k;
    //     list.findKthToLast(head, k);
    // }

    /*** USE THE CODE BELOW FOR THE ITERATIVE ALGORITHM (SIZE IS KNOWN) ***/
    int size, result;
    while (k != -1) {
        cout << "Enter the value for 'k' to find the kth-to-last element of the list (-1 = quit): ";
        cin >> k;

        size = list.size();
        result = list.findKthToLast(head, k, size);
        cout << "With k = " << k << ", the kth to last element is: " << result << "\n" << endl;
    }

    return 0;
}