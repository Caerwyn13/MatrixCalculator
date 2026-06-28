//
// Created by Caerwyn on 27/06/2026.
//

#include "Matrix.h"
#include <iostream>

// ==========================================
// CLASS MEMBER FUNCTIONS
// ==========================================

Matrix::Matrix(const unsigned long r, const unsigned long c)
    : matrix(r, std::vector<double>(c, 0.0)) {}

Matrix Matrix::zeroMatrix(const unsigned long r, const unsigned long c) {
    return {r, c};
}

Matrix Matrix::oneMatrix(const unsigned long r, const unsigned long c) {
    Matrix result(r, c);

    for (unsigned long i = 0; i < r; ++i) {
        for (unsigned long j = 0; j < c; ++j) {
            result[i][j] = 1.0;
        }
    }

    return result;
}

Matrix Matrix::identity(const unsigned long n) {
    Matrix result(n, n);

    for (unsigned long i = 0; i < n; ++i) {
        result[i][i] = 1.0;
    }

    return result;
}

std::vector<double>& Matrix::operator[](const unsigned long i) {
    return matrix[i];
}

const std::vector<double>& Matrix::operator[](const unsigned long i) const {
    return matrix[i];
}

unsigned long Matrix::getRows() const {
    return matrix.size();
}

unsigned long Matrix::getCols() const {
    return matrix.empty() ? 0 : matrix[0].size();
}

double Matrix::getElement(const unsigned long row, const unsigned long col) const {
    return matrix[row][col];
}

// ==========================================
// OPERATOR OVERLOADS
// ==========================================

Matrix Matrix::operator+(const Matrix& other) const {
    if (getRows() != other.getRows() || getCols() != other.getCols()) {
        std::cout << "Error: Matrices cannot be added!\n";
        return {0, 0};
    }

    Matrix result(getRows(), getCols());

    for (unsigned long r = 0; r < getRows(); ++r) {
        for (unsigned long c = 0; c < getCols(); ++c) {
            result[r][c] = (*this)[r][c] + other[r][c];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (getRows() != other.getRows() || getCols() != other.getCols()) {
        std::cout << "Error: Matrices cannot be subtracted!\n";
        return {0, 0};
    }

    Matrix result(getRows(), getCols());

    for (unsigned long r = 0; r < getRows(); ++r) {
        for (unsigned long c = 0; c < getCols(); ++c) {
            result[r][c] = (*this)[r][c] - other[r][c];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (getCols() != other.getRows()) {
        std::cout << "Error: Matrices cannot be multiplied!\n";
        return {0, 0};
    }

    Matrix result(getRows(), other.getCols());

    for (unsigned long r = 0; r < getRows(); ++r) {
        for (unsigned long c = 0; c < other.getCols(); ++c) {
            for (unsigned long k = 0; k < getCols(); ++k) {
                result[r][c] += (*this)[r][k] * other[k][c];
            }
        }
    }

    return result;
}

Matrix Matrix::operator*(const double scalar) const {
    Matrix result(getRows(), getCols());

    for (unsigned long r = 0; r < getRows(); ++r) {
        for (unsigned long c = 0; c < getCols(); ++c) {
            result[r][c] = (*this)[r][c] * scalar;
        }
    }

    return result;
}

Matrix Matrix::operator/(const double scalar) const {
    Matrix result(getRows(), getCols());

    for (unsigned long r = 0; r < getRows(); ++r) {
        for (unsigned long c = 0; c < getCols(); ++c) {
            result[r][c] = (*this)[r][c] / scalar;
        }
    }

    return result;
}

// ==========================================
// NON-MEMBER FUNCTIONS
// ==========================================

Matrix matrixTranspose(const Matrix& matrix) {
    Matrix result(matrix.getCols(), matrix.getRows());

    for (unsigned long r = 0; r < matrix.getRows(); ++r) {
        for (unsigned long c = 0; c < matrix.getCols(); ++c) {
            result[c][r] = matrix[r][c];
        }
    }

    return result;
}

Matrix matrixPower(Matrix base, unsigned long exp) {
    if (exp == 0) {
        return Matrix::identity(base.getRows());
    }

    Matrix result = Matrix::identity(base.getRows());

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }

        base = base * base;
        exp /= 2;
    }

    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    for (unsigned long r = 0; r < mat.getRows(); ++r) {
        for (unsigned long c = 0; c < mat.getCols(); ++c) {
            os << mat[r][c];

            if (c + 1 < mat.getCols()) {
                os << ' ';
            }
        }

        if (r + 1 < mat.getRows()) {
            os << '\n';
        }
    }

    return os;
}