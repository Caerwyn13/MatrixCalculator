#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    vector<vector<double>> matrix;
public:
    Matrix(const unsigned long r, const unsigned long c) {
        matrix.resize(r);

        for (int i = 0; i < r; i++) {
            matrix[i].resize(c, 0);
        }
    }

    vector<double>& operator[](const int i) {
        return matrix[i];
    }

    [[nodiscard]] unsigned long getRows() const { return matrix.size(); }
    [[nodiscard]] unsigned long getCols() const { return matrix[0].size(); }
};

void displayMatrix(Matrix mat) {
    const unsigned long rows = mat.getRows();
    const unsigned long cols = mat.getCols();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << mat[r][c] << ' ';
        }
        cout << endl;
    }
}

Matrix addMatrix(Matrix mat1, Matrix &mat2) {
    // Ensure matrices can be added
    if (mat1.getRows() != mat2.getRows() || mat1.getCols() != mat2.getCols()) {
        cout << "Error: Matrices cannot be added!" << endl;
        return {0, 0};
    }

    // Matrices can be added, so add them
    // Resulting matrix
    Matrix result(mat1.getRows(), mat1.getCols());

    for (int r = 0; r < mat1.getRows(); r++) {
        for (int c = 0; c < mat1.getCols(); c++) {
            result[r][c] = mat1[r][c] + mat2[r][c];
        }
    }

    return result;
}

int main() {
    //TODO: Add user matrix inputs
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
    Matrix testMatrix2 = testMatrix1;   // Simplify testing

    displayMatrix(testMatrix1);
    cout << endl;
    displayMatrix(addMatrix(testMatrix1, testMatrix2));

    return 0;
}
