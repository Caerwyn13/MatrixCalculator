//
// Created by Caerwyn on 27/06/2026.
//

#ifndef MATRIXALGEBRA_MATRIX_H
#define MATRIXALGEBRA_MATRIX_H

#pragma once
#include <vector>

class Matrix {
    std::vector<std::vector<double>> matrix;

public:
    Matrix(unsigned long r, unsigned long c);
    //TODO: Implement filling matrix with 0s, 1s, and random values
    static Matrix identity(unsigned long n);

    std::vector<double>& operator[](unsigned long i);
    const std::vector<double>& operator[](unsigned long i) const;

    [[nodiscard]] unsigned long getRows() const;
    [[nodiscard]] unsigned long getCols() const;
    [[nodiscard]] double getElement(unsigned long row, unsigned long col) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar)       const;
    Matrix operator/(double scalar)       const;

    //TODO: Add determinant an inverses (using Gaussian elimination and Gauss-Jordan elimination respectively)
};

//TODO: Implement transpositioning
Matrix matrixPower(const Matrix& base, unsigned long exp);
void displayMatrix(const Matrix& mat);

#endif //MATRIXALGEBRA_MATRIX_H
