/*
 * 01/10/2019
 * Samuel Mercado
 * 
 * Description: Performs basic string compression using counts of repeated characters.
 * 
 * Assumption(s): The strings are case sensitive.
 */

#include <iostream>
#include <string>

using namespace std;

/* 
 * This algorithm compresses the given string by counting consecutive 
 * characters. First, the variables targetChar and targetCharCount 
 * are set to the first character and 1, respectively. Using a for 
 * loop, each character of the string is visited and when a character
 * differs from the targetChar, both targetChar and targetCharCount are
 * appended to the output string and then reset to account for the new
 * character. 
 * 
 * I conducted some brief research and concluded that due to C++ strings
 * being mutable, the string concatenation done by the += operator should
 * not negatively affect the efficiency of the algorithm. 
 * 
 * Overall Time Complexity: O(n), where n = length of input string.
 * Additional Space Complexity: O(m), where m = length of output string.
 */
string compressString(string str) {
    string compressedStr = "";
    char targetChar = str[0];
    int targetCharCount = 1;

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == targetChar)
            targetCharCount++;
        else {
            compressedStr += targetChar + to_string(targetCharCount);
            targetChar = str[i];
            targetCharCount = 1;
        }
    }
    compressedStr += targetChar + to_string(targetCharCount);

    if (compressedStr.length() < str.length())
        return compressedStr;
    else 
        return str;
}

int main() {
    string inputStr, outputStr;

    cout << "Enter a string to compress: ";
    cin >> inputStr;

    outputStr = compressString(inputStr);
    cout << "Compressed string = " << outputStr << endl;

    return 0;
}