//
// Created by Caerwyn on 27/06/2026.
//

#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// ==========================================
// CLASS MEMBER FUNCTIONS
// ==========================================

Matrix::Matrix(const unsigned long r, const unsigned long c)
    : matrix(r, vector<double>(c, 0.0)) {}

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

vector<double>& Matrix::operator[](const unsigned long i) {
    return matrix[i];
}

const vector<double>& Matrix::operator[](const unsigned long i) const {
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
        throw invalid_argument("Error: Matrices cannot be added!\n");
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
        throw invalid_argument("Error: Matrices cannot be subtracted!\n");
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
        throw invalid_argument("Error: Matrices cannot be multiplied!\n");
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

Matrix& Matrix::operator+=(const Matrix& other) {
    (*this) = (*this) + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    (*this) = (*this) - other;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    (*this) = (*this) * other;
    return *this;
}

Matrix& Matrix::operator*=(const double scalar) {
    (*this) = (*this) * scalar;
    return *this;
}

Matrix& Matrix::operator/=(const double scalar) {
    (*this) = (*this) / scalar;
    return *this;
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

double matrixDeterminant(const Matrix& mat) {
    if (mat.getRows() != mat.getCols()) {
        throw invalid_argument("Matrix must be square to calculate its determinant.");
    }

    unsigned long n = mat.getRows();
    if (n == 0) return 1.0; // Determinant of an empty matrix is conventionally 1

    Matrix temp = mat;
    double det = 1.0;
    int sign = 1;

    for (unsigned long i = 0; i < n; ++i) {
        // Find the largest absolute value in the current column below the diagonal
        unsigned long pivot_row = i;
        for (unsigned long j = i + 1; j < n; ++j) {
            if (abs(temp[j][i]) > abs(temp[pivot_row][i])) {
                pivot_row = j;
            }
        }

        // If the pivot value is effectively zero, the determinant is zero
        if (constexpr double epsilon = 1e-9; abs(temp[pivot_row][i]) < epsilon) {
            return 0.0;
        }

        // Swap rows if a better pivot row was discovered down the column
        if (pivot_row != i) {
            swap(temp[i], temp[pivot_row]);     // Swaps vectors internally (efficient O(1) swap)
            sign *= -1;                                   // Flipping rows flips the determinant's sign
        }

        // Multiply running total by the chosen pivot value
        det *= temp[i][i];

        // Form zeros beneath the current diagonal item
        for (unsigned long j = i + 1; j < n; ++j) {
            const double factor = temp[j][i] / temp[i][i];
            for (unsigned long k = i; k < n; ++k) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    return sign * det;
}

ostream& operator<<(ostream& os, const Matrix& mat) {
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