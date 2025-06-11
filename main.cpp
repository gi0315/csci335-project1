//CSCI335: Software Analysis and Design III
//GISSELLE SAGASTUME{Project \#1}
//Date: June 8th, 2025}

#include <iostream>
#include "Matrix33.h"
#include "vector3.h"
#include "matrix_nm.h" 

using namespace std;

// Multiply Matrix A (3x3) with Vector x (3x1): result is Vector b
Vector3 matrixVectorMultiply(const Matrix33& A, Vector3& x) {
    double b0 = A(0, 0)*x(0) + A(0, 1)*x(1) + A(0, 2)*x(2);
    double b1 = A(1, 0)*x(0) + A(1, 1)*x(1) + A(1, 2)*x(2);
    double b2 = A(2, 0)*x(0) + A(2, 1)*x(1) + A(2, 2)*x(2);
    return Vector3(b0, b1, b2);
}

int main() {
    int choice;
    cout << "Select problem to run:\n";
    cout << "1. Matrix33 (3x3) * Vector3\n";
    cout << "2. MatrixNM (n x m)\n";
    cout << "Enter a choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        Matrix33 A;
        Vector3 x;

        cout << "Enter a 3x3 matrix:\n";
        cin >> A;

        cin >> x;

        Vector3 b = matrixVectorMultiply(A, x);

        cout << "Result of Ax = b is: " << b;
    }
    else if (choice == 2) {
        int rows, cols;
        cout << "Enter number of rows:";
        cin >> rows;
        cout<< "Enter number of columns:";
        cin>> cols;

        MatrixNM A(rows, cols);
        cout << "Enter " << rows * cols << " numbers (row by row):\n";
        cin >> A;

        cout << "You entered the matrix:\n";
        cout << A;

        // Now prompt for a vector of size `cols`
        vector<double> x(cols);
        cout << "Enter a vector of size " << cols << ":\n";
        for (int i = 0; i < cols; ++i)
        {
            cin >> x[i];
        }

        // Multiply A * x to get b
        vector<double> b(rows, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                b[i] += A(i, j) * x[j];
            }
        }

        cout << "Result of Ax = b is: (";
        for (int i = 0; i < rows; ++i) {
            cout << b[i];
            if (i != rows - 1) cout << ", ";
        }
        cout << ")\n";
    }

    return 0;
}
