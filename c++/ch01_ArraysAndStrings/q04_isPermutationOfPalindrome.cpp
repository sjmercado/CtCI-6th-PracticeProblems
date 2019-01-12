/*
 * 01/09/2019
 * 
 * Description: determines whether a string is a permutation of a palindrome.
 * 
 * Assumption(s): the characters in the string are case sensitive.
 */

#include <algorithm>    // std::remove_if
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* Time Complexity: O(n) */
string removeNonLetters(string str) {
    for (int i = 0; i < str.length(); i++) {
        if ( !isalpha(str[i]) ) {
            str.erase(i, 1);
            i -= 1;     // Since the string's length is being shortened by one, don't increment i.
        }
    }

    return str;
}

/* 
 * This algorithm uses a helper function removeNonLetters to ensure that the string only contains
 * alphabetical characters. Then, a hash table is used to determine the frequency count of each
 * character. By definition of a permutation, there may only be at most one character with an odd
 * frequency, thus it is this validation that determines whether the given string is a permutation 
 * of a palindrome.
 * 
 * Overall Time Complexity: O(n)
 * Additional Space Complexity: O(n)
 */
bool isPermutationOfPalindrome(string str) {
    unordered_map<char, int> table;

    // I decided to use my own helper function instead of the following to maintain control of complexity.
    // str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isalpha(c); } ), str.end());

    str = removeNonLetters(str);

    for (int i = 0; i < str.length(); i++)
        table[str[i]]++;

    int oddFreqCount = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second % 2 == 1)
            oddFreqCount++;

        if (oddFreqCount > 1) 
            return false;
    }

    return true;
}


int main() {
    string str;
    bool result;

    cout << "Enter a string: ";
    getline(cin, str);

    result = isPermutationOfPalindrome(str);
    if (result)
        cout << "The string is a permutation of a palindrome." << endl;
    else
        cout << "The string is not a permutation of a palindrome." << endl;

    return 0;    
}