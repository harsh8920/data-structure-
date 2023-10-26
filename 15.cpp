#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a non-zero element
struct SparseElement {
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix {
    int rows;
    int cols;
    vector<SparseElement> elements;
};

// Function to add two sparse matrices
SparseMatrix addSparseMatrices(const SparseMatrix& matrix1, const SparseMatrix& matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    SparseMatrix result;
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;

    for (const SparseElement& elem1 : matrix1.elements) {
        result.elements.push_back(elem1);
    }

    for (const SparseElement& elem2 : matrix2.elements) {
        result.elements.push_back(elem2);
    }

    return result;
}

// Function to print a sparse matrix
void printSparseMatrix(const SparseMatrix& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            bool isNonZero = false;
            for (const SparseElement& elem : matrix.elements) {
                if (elem.row == i && elem.col == j) {
                    cout << elem.value << " ";
                    isNonZero = true;
                    break;
                }
            }
            if (!isNonZero) {
                std::cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    SparseMatrix matrix1{3, 3, {{0, 0, 1}, {0, 1, 2}, {1, 1, 3}}};
    SparseMatrix matrix2{3, 3, {{0, 1, 4}, {1, 1, 5}, {2, 2, 6}}};

    cout << "Matrix 1:" << endl;
    printSparseMatrix(matrix1);

    cout << "Matrix 2:" << endl;
    printSparseMatrix(matrix2);

    SparseMatrix sum = addSparseMatrices(matrix1, matrix2);
    cout << "Sum of matrices:" << endl;
    printSparseMatrix(sum);

    return 0;
}
