#include "Matrix.h"
#include <iostream>

int main() {
    //TODO: Implement user matrix input
    Matrix testMatrix1(3, 3);

    testMatrix1[0][0] = 1;
    testMatrix1[0][1] = 2;
    testMatrix1[0][2] = 3;
    testMatrix1[1][0] = 4;
    testMatrix1[1][1] = 5;
    testMatrix1[1][2] = 6;
    testMatrix1[2][0] = 7;
    testMatrix1[2][1] = 8;
    testMatrix1[2][2] = 9;

    const Matrix testMatrix2 = testMatrix1;

    displayMatrix(testMatrix1);
    std::cout << "\n";
    displayMatrix(addMatrix(testMatrix1, testMatrix2));

    return 0;
}