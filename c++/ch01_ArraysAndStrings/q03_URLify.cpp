/*
 * 01/08/2019
 * 
 * Description: replaces all spaces within a string with "%20".
 * 
 * Assumption(s): the given string has enough add'l spaces to accommadate the space
 * needed for the extra characters.
 */

#include <string>
#include <iostream>

using namespace std;

/*
 * Rather than solving the problem "in-place", this algorithm returns a new copy of  
 * the string. Although a simple solution, it uses up more space than an algorithm
 * that computes the replacement in-place.
 * 
 * Overall Time Complexity: O(n)
 * Additional Spacial Complexity: O(n)
 */
string URLify(string str, int trueLength) {
    string newStr = "";

    for (int i = 0; i < trueLength; i++) {
        if (str[i] == ' ' )
            newStr += "%20";
        else   
            newStr += str[i];
    }

    return newStr;
}

int main() {
    string str, newStr;
    int trueLength;

    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter it's true length: ";
    cin >> trueLength;

    newStr = URLify(str, trueLength);
    cout << "New string: " << newStr << endl;

    return 0;
}