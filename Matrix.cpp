//
// Created by Caerwyn on 27/06/2026.
//

#include "Matrix.h"
#include <iostream>

// ==========================================
// CLASS MEMBER FUNCTIONS
// ==========================================

// Constructor: Initializes the 2D vector with 'r' rows and 'c' columns, filled with 0.0
Matrix::Matrix(const unsigned long r, const unsigned long c)
    : matrix(r, std::vector<double>(c, 0.0)) {}

// Non-const bracket operator: returns a modifiable row reference
std::vector<double>& Matrix::operator[](const unsigned long i) {
    return matrix[i];
}

// Const bracket operator: returns a read-only row reference
const std::vector<double>& Matrix::operator[](const unsigned long i) const {
    return matrix[i];
}

// Returns the total number of rows
unsigned long Matrix::getRows() const {
    return matrix.size();
}

// Returns the total number of columns (0 if matrix is empty)
unsigned long Matrix::getCols() const {
    return matrix.empty() ? 0 : matrix[0].size();
}


// ==========================================
// GLOBAL HELPER FUNCTIONS
// ==========================================

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

Matrix multiplyMatrix(const Matrix& mat1, const Matrix& mat2) {
    if (mat1.getCols() != mat2.getRows()) {
        std::cout << "Error: Matrices cannot be multiplied!\n";
        return {0, 0};
    }

    Matrix result(mat1.getRows(), mat2.getCols());

    for (unsigned long r = 0; r < mat1.getRows(); r++) {
        for (unsigned long c = 0; c < mat2.getCols(); c++) {
            for (unsigned long k = 0; k < mat1.getCols(); k++) {
                result[r][c] += mat1[r][k] * mat2[k][c];
            }
        }
    }
    return result;
}
