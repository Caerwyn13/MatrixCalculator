#ifndef MATRIXALGEBRA_MATRIX_H
#define MATRIXALGEBRA_MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
    std::vector<std::vector<double>> matrix;

public:
    Matrix(unsigned long r, unsigned long c);

    static Matrix zeroMatrix(unsigned long r, unsigned long c);
    static Matrix oneMatrix(unsigned long r, unsigned long c);
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

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(double       scalar);
    Matrix& operator/=(double       scalar);
};

Matrix matrixTranspose(const Matrix& matrix);
Matrix matrixPower(Matrix base, unsigned long exp);
double matrixDeterminant(const Matrix& mat);
std::ostream& operator<<(std::ostream& os, const Matrix& mat);

#endif //MATRIXALGEBRA_MATRIX_H
