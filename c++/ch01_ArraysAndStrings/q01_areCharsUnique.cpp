/*
 * 01/05/2019
 * 
 * Description: checks if a given string contains all unique characters. Two implementations
 * are provided: the first uses a hash map, and the second does not use any additional data
 * structures (at the cost of a slower runtime).
 * 
 * Assumption(s): the string is ASCII encoded.
 */

#include <algorithm>    // std::sort
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* 
 * This algorithm uses a hash map (table) data structure to determine if the string contains
 * all unique characters. Each character is mapped to the table with its corresponding key
 * being the ASCII code for that character. If a collision occurs, this indicates that 
 * a duplicate character has been found, and immediately returns false. The spacial 
 * complexity is increased due to the additional data structure.
 * 
 * Overall Time Complexity: O(n)
 * Additional Spacial Complexity: O(n)
 */
bool areCharsUnique1(string str) {
    unordered_map<int, char> table;

    // At worst, all characters will be inserted into hash table => O(n) runtime.
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        int key = c;
        if (table.count(key) > 0)
            return false;
        table[key] = c;
    }

    return true;
}

/* 
 * This algorithm does not use any additional data structures to arrive at the solution.
 * First, the characters within the given string are sorted alphabetically, which will
 * then place any duplicate characters next to each other. Each loop iteration compares
 * the current character with the succeeding character, and returns false if equivalent.
 * 
 * Overall Time Complexity: O(n*log(n))
 * Additional Spacial Complexity: O(1)
 */
bool areCharsUnique2(string str) {
    /* Alphabetically sorts all characters within the string => O(n*log(n)) runtime,
       where n = std::distance(first, last) comparisons. */
    sort(str.begin(), str.end());

    // At worst, all characters will be compared => O(n) runtime. 
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i + 1])
            return false;
    }

    return true;
}

int main() {
    string str;
    int choice;
    bool result;

    cout << "Enter a string to test: ";
    cin >> str;
    cout << "Are additional data structures allowed? (1 = Yes, 2 = No): ";
    cin >> choice;

    if (choice == 1)
        result = areCharsUnique1(str);
    else if (choice == 2)
        result = areCharsUnique2(str);
    else 
        return 0;

    if (result)
        cout << "The string contains all unique characters." << endl;
    else
        cout << "The string does not contain all unique characters." << endl;

    return 0;
}