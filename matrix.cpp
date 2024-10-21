#include <iostream>
#include <iomanip> // For std::setw

using namespace std;

void printMatrix(int matrix[3][3], int rows, int cols) {
    cout << endl; // Opening bracket for the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(3) << matrix[i][j]; // Print each element with formatting
        }
        cout<< endl; // Closing bracket for each row
    }
    cout << endl; // Closing bracket for the matrix
}

void rowEchelonForm(int matrix[3][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        // Make the leading coefficient 1 by dividing the row by the leading coefficient
        if (matrix[i][i] != 0) {
            int pivot = matrix[i][i];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] /= pivot;
            }
        }
        
        // Eliminate the leading coefficients of the rows below the current row
        for (int k = i + 1; k < rows; k++) {
            int factor = matrix[k][i];
            for (int j = 0; j < cols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

int main() {
    // Define a 3x3 matrix
    int matrix[3][3] = {
        {2, 4, -2},
        {-3, -1, 3},
        {1, 1, 2}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, 3, 3);

    rowEchelonForm(matrix, 3, 3);

    cout << "Row Echelon Form (REF):" << endl;
    printMatrix(matrix, 3, 3);

    return 0;
}
