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
    cout << testMatrix1 << endl;

    cout << "\ntestMatrix1 added to itself:\n";
    cout << testMatrix1 + testMatrix1 << endl;

    cout << "\ntestMatrix1 subtracted from itself:\n";
    cout << testMatrix1 - testMatrix1 << endl;
    
    cout << "\ntestMatrix1 multiplied by itself:\n";
    cout << testMatrix1 * testMatrix1 << endl;

    cout << "\ntestMatrix1 squared:\n";
    cout << matrixPower(testMatrix1, 2) << endl;

    cout << "\ntestMatrix1 multiplied by a scalar\n";
    cout << testMatrix1 * 3 << endl;

    cout << "\ntestMatrix1 divided by a scalar\n";
    cout << testMatrix1 / 3 << endl;

    return 0;
}
