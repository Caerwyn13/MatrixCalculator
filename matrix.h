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

    std::vector<double>& operator[](unsigned long i);
    const std::vector<double>& operator[](unsigned long i) const;

    [[nodiscard]] unsigned long getRows() const;
    [[nodiscard]] unsigned long getCols() const;
};

void displayMatrix(const Matrix& mat);
Matrix addMatrix(const Matrix& mat1, const Matrix& mat2);

#endif //MATRIXALGEBRA_MATRIX_H
