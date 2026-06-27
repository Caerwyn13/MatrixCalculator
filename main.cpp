#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> matrix;
public:
    Matrix(const int r, const int c) {
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

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    const Matrix userMatrix(rows, cols);
    displayMatrix(userMatrix);

    return 0;
}