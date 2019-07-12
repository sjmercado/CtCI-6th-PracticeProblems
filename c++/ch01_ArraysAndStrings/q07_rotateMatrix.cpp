/*
 * 01/12/2019
 * Samuel Mercado
 * 
 * Description: Rotates an image represented as an NxN matrix by 90
 * degrees, where each pixel in the image is 4 bytes. 
 * 
 * Assumption(s): The desired rotation is clockwise. 
 */

#include <iostream>
#include <vector>

using namespace std;

const int N = 5;    // Matrix dimension.

/* 
 * This algorithm rotates the matrix one row at a time, where the top row
 * of the original matrix becomes the last column of the new matrix, and
 * the second row of the original matrix becomes the second to last column
 * of the new matrix, and so on. This is not the most efficient
 * implementation because it does not compute the rotation in-place.
 * 
 * Overall Time Complexity: O(N^2)
 * Additional Spacial Complexity: O(N^2)
 */
vector<vector<int>> rotateMatrix(vector<vector<int>> oldMatrix) {
    vector<vector<int>> newMatrix(N, vector<int>(N));

    int orig_j = 0;
    for (int j = N - 1; j >= 0; j--) {
        for (int i = 0; i < N; i++)
            newMatrix[i][j] = oldMatrix[orig_j][i];
        orig_j++;
    }

    return newMatrix;
}

int main() {
    int byteNum = 0;
    vector<vector<int>> matrix(N, vector<int>(N));

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = byteNum;
            byteNum += 4;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    vector<vector<int>> rotatedMatrix = rotateMatrix(matrix);

    cout << "\nRotated Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << rotatedMatrix[i][j] << "\t";
        cout << endl;
    }
    
    return 0;
}