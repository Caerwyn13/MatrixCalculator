#include "Matrix.h"
#include <iostream>

using namespace std;

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

    cout << "testMatrix1:\n";
    displayMatrix(testMatrix1);

    cout << "\ntestMatrix1 added to itself:\n";
    displayMatrix(testMatrix1 + testMatrix1);

    cout << "\ntestMatrix1 subtracted from itself:\n";
    displayMatrix(testMatrix1 - testMatrix1);
    
    cout << "\ntestMatrix1 multiplied by itself:\n";
    displayMatrix(testMatrix1 * testMatrix1);

    cout << "\ntestMatrix1 squared:\n";
    displayMatrix(matrixPower(testMatrix1, 2));

    cout << "\ntestMatrix1 multiplied by a scalar\n";
    displayMatrix(testMatrix1 * 3);

    return 0;
}
