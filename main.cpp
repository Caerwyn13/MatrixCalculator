#include <format>

#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
    unsigned int rows, cols;
    cout << "Enter the number of rows and columns:\n";
    cin >> rows >> cols;

    Matrix userMatrix(rows, cols);

    for (unsigned int row = 0; row < rows; row++) {
        for (unsigned int col = 0; col < cols; col++) {
            cout << format("Enter element {},{}: ", row+1, col+1);
            cin >> userMatrix[row][col];
        }
    }

    cout << "Your Matrix is:\n" << userMatrix << endl;
    cout << "\n3A^T + 4A**2:" << endl;
    cout << (matrixTranspose(userMatrix) * 3 + matrixPower(userMatrix, 2) * 4) << endl;

    return 0;
}
