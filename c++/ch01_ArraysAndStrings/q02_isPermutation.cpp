/*
 * 01/06/2019
 * 
 * Description: determines if one string is a permutation of the other.
 * 
 * Assumption(s): the strings are case sensitive, and whitespace is insignificant.
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * This algorithm determines whether a string is a permutation of the other by
 * summing the ASCII codes of each character. If the sums for each string are
 * the same, then they are permutations of one another. 
 * 
 * Overall Time Complexity: O(n)
 * Additional Spacial Complexity: O(1)
 */
bool isPermutation(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < str1.length(); i++) {
        sum1 += str1[i];
        sum2 += str2[i];
    }

    if (sum1 == sum2)
        return true;
    else 
        return false;
}

int main() {
    string str1, str2;
    bool result;

    cout << "Enter two strings separated by a space: ";
    cin >> str1 >> str2;

    result = isPermutation(str1, str2);
    if (result)
        cout << "One of the strings is a permutation of the other." << endl;
    else    
        cout << "Neither string is a perumation of the other." << endl;

    return 0;
}
