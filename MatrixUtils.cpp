//
// Created by Caerwyn on 27/06/2026.
//

#include "Matrix.h"
#include <iostream>

void displayMatrix(const Matrix& mat) {
    for (unsigned long r = 0; r < mat.getRows(); r++) {
        for (unsigned long c = 0; c < mat.getCols(); c++) {
            std::cout << mat[r][c] << ' ';
        }
        std::cout << '\n';
    }
}

Matrix addMatrix(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.getRows() != mat2.getRows() ||
        mat1.getCols() != mat2.getCols()) {
        std::cout << "Error: Matrices cannot be added!\n";
        return {0, 0};
        }

    Matrix result(mat1.getRows(), mat1.getCols());

    for (unsigned long r = 0; r < mat1.getRows(); r++) {
        for (unsigned long c = 0; c < mat1.getCols(); c++) {
            result[r][c] = mat1[r][c] + mat2[r][c];
        }
    }

    return result;
}