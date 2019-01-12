/*
 * 01/09/2019
 * 
 * Description: determines whether or not two strings are more than one edit
 * away from one another.
 * 
 * Assumption(s): the strings are case sensitive.
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* 
 * This algorithm determines whether two strings are one edit away from one
 * another by inserting each character from the smaller string into a hash
 * table. Then it counts the amount of characters within the larger string
 * that aren't in the hash table, if the count is >1 then it would require 
 * more than one edit for the strings to become equal.
 * 
 * Overall Time Complexity: O(n), where n = shorter string length.
 * Additional Spacial Complexity: O(n), where n = str1.length
 */
bool isOneEditAway(string str1, string str2) {
    int editCount = 0;
    
    if (str1 == str2) 
        return true;

    // Ensures that str1 is the larger string => O(1)
    if (str1.length() < str2.length())
        str2.swap(str1);    

    /* If the difference between the lengths is >1 then this would lead to
       >1 additions/removals, meaning there would be >1 edits. */
    if (str1.length() - str2.length() > 1)
        return false; 
    
    unordered_map<char, bool> table;
    for (int i = 0; i < str2.length(); i++)
        table[str2[i]] = true;

    for (int i = 0; i < str1.length(); i++) {
        if (!table[str1[i]])
            editCount++;
        
        if (editCount > 1)
            return false;
    }

    return true;
}

int main() {
    string str1, str2;
    cout << "Enter two strings separated by a space: ";
    cin >> str1 >> str2;

    bool result = isOneEditAway(str1, str2);

    if (result)
        cout << "The strings are one edit (or zero edits) away." << endl;
    else 
        cout << "The strings are more than one edit away." << endl;

    return 0;
}