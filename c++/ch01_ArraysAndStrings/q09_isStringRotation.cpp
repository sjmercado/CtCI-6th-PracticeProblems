/*
 * 07/11/2019
 * Samuel Mercado
 * 
 * Description: Given two strings, checks whether one of the strings is a rotation of 
 * the other string.
 * 
 * Assumption(s): The strings are case sensitive.
 */

#include <iostream>
#include <string>

using namespace std;

/* 
 * Checks if s1 is a substring of s2. Note that this algorithm assumes the length of s1
 * is less than or equal to the length of s2. 
 * 
 * Overall Time Complexity: O(a + b), where a = n1 and b = n2.
 */
bool isSubstring(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    for (int i = 0; i < n2 - n1 + 1; i++) {
        string tmp = s2.substr(i, n1);

        if (tmp == s1)
            return true;
    }

    return false;
}

/* 
 * This algorithm checks if s2 is a string rotation of s1. This is accomplished by first
 * realizing that a rotation is simply splitting a string into two segments and swapping 
 * them. For instance, s1 is split into two parts, x and y, such that s1 = xy. If s2 is 
 * a string rotation of s1, then s2 = yx. We can guarantee that s2 is a string rotation
 * of s1 by concatenating s2 with itself and saving this as a new variable (s3 = s2s2 = yxyx), 
 * and then using the isSubstring function above to verify that s1, or xy,  exists in s3.
 * 
 * Overall Time Complexity: O(n), where n = s3.length()
 * Additional Space Complexity: O(n) due to creating additional string s3.
 */
bool isStringRotation(string s1, string s2) {
    // First check that both strings have the same length, and that the length is > 0.
    if (s1.length() != s2.length() || s1.length() == 0)
        return false;

    string s3 = s2 + s2;
    return isSubstring(s1, s3);
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    bool result = isStringRotation(s1, s2);
    if (result)
        cout << "s2 is a string rotation of s1.";
    else 
        cout << "s2 is not a string rotation of s1.";

    return 0;
}