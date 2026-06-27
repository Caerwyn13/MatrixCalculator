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
    static Matrix identity(unsigned long n);

    std::vector<double>& operator[](unsigned long i);
    const std::vector<double>& operator[](unsigned long i) const;

    [[nodiscard]] unsigned long getRows() const;
    [[nodiscard]] unsigned long getCols() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar)       const;
};


Matrix matrixPower(const Matrix& base, unsigned long exp);
void displayMatrix(const Matrix& mat);

#endif //MATRIXALGEBRA_MATRIX_H
