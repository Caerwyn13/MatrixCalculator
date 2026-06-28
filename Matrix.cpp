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

Matrix Matrix::identity(const unsigned long n) {
    // Create a square matrix of the given size filled with zeros
    Matrix id(n, n);

    // Set the main diagonal elements to 1.0
    for (unsigned long i = 0; i < n; ++i) {
        id[i][i] = 1.0;
    }

    return id;
}


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

double Matrix::getElement(const unsigned long row, const unsigned long col) const {
    return matrix[row][col];
}

// ==========================================
// OPERATOR OVERLOAD FUNCTIONS
// ==========================================

Matrix Matrix::operator+(const Matrix& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        std::cout << "Error: Matrices cannot be added!\n";
        return {0, 0};
    }
    Matrix result(this->getRows(), this->getCols());

    for (unsigned long r = 0; r < this->getRows(); r++) {
        for (unsigned long c = 0; c < this->getCols(); c++) {
            result[r][c] = (*this)[r][c] + other[r][c];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        std::cout << "Error: Matrices cannot be added!\n";
        return {0, 0};
    }
    Matrix result(this->getRows(), this->getCols());

    for (unsigned long r = 0; r < this->getRows(); r++) {
        for (unsigned long c = 0; c < this->getCols(); c++) {
            result[r][c] = (*this)[r][c] - other[r][c];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (this->getCols() != other.getRows()) {
        std::cout << "Error: Matrices cannot be multiplied!\n";
        return {0, 0};
    }
    Matrix result(this->getRows(), other.getCols());

    for (unsigned long r = 0; r < this->getRows(); r++) {
        for (unsigned long c = 0; c < other.getCols(); c++) {
            for (unsigned long k = 0; k < this->getCols(); k++) {
                result[r][c] += (*this)[r][k] * other[k][c];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(const double scalar) const {
    Matrix result(this->getRows(), this->getCols());
    for (unsigned long r = 0; r < this->getRows(); r++) {
        for (unsigned long c = 0; c < this->getCols(); c++) {
            result[r][c] = (*this)[r][c] * scalar;
        }
    }

    return result;
}

Matrix Matrix::operator/(const double scalar) const {
    Matrix result(this->getRows(), this->getCols());
    for (unsigned long r = 0; r < this->getRows(); r++) {
        for (unsigned long c = 0; c < this->getCols(); c++) {
            result[r][c] = (*this)[r][c] / scalar;
        }
    }
    return results;
}


// ==========================================
// OTHER FUNCTIONS
// ==========================================

Matrix matrixPower(const Matrix& base, unsigned long exp) {
    Matrix result = base;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }
        exp /= 2;
    }
    return result;
}

void displayMatrix(const Matrix& mat) {
    for (unsigned long r = 0; r < mat.getRows(); r++) {
        for (unsigned long c = 0; c < mat.getCols(); c++) {
            std::cout << mat[r][c] << ' ';
        }
        std::cout << '\n';
    }
}
