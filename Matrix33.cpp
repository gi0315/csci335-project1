//CSCI335: Software Analysis and Design III
//GISSELLE SAGASTUME{Project \#1}
//Date: June 8th, 2025}

#include "Matrix33.h"
#include <iostream>
using namespace std;


Matrix33::Matrix33() {
    // Time: O(1), Space: O(1) — allocating fixed-size 3x3 array
    data = new double*[3];
    for (int i = 0; i < 3; i++)
        data[i] = new double[3]; // Not initializing values
}

Matrix33::Matrix33(double arr[3][3]) {
    // Time: O(1), Space: O(1) — copying 9 fixed values
    data = new double*[3];
    for (int i = 0; i < 3; i++) {
        data[i] = new double[3];
        for (int j = 0; j < 3; j++)
            data[i][j] = arr[i][j];
    }
}

Matrix33::Matrix33(const Matrix33& other) {
    // Time: O(1), Space: O(1) — copying 3x3 matrix
    data = new double*[3];
    for (int i = 0; i < 3; i++) {
        data[i] = new double[3];
        for (int j = 0; j < 3; j++)
            data[i][j] = other.data[i][j];
    }
}

Matrix33::Matrix33(Matrix33&& other) {
    // Time: O(1), Space: O(1) — pointer transfer only
    data = other.data;
    other.data = nullptr;
}

double Matrix33::operator()(int row, int col) const {
    // Time: O(1), Space: O(1) — constant-time access
    return data[row][col];
}

Matrix33& Matrix33::operator=(const Matrix33& other) {
    // Time: O(1), Space: O(1) — delete and copy fixed-size data
    if (this == &other) return *this;

    for (int i = 0; i < 3; i++) delete[] data[i];
    delete[] data;

    data = new double*[3];
    for (int i = 0; i < 3; i++) {
        data[i] = new double[3];
        for (int j = 0; j < 3; j++)
            data[i][j] = other.data[i][j];
    }

    return *this;
}

Matrix33& Matrix33::operator=(Matrix33&& other) {
    // Time: O(1), Space: O(1) — release and assign pointer
    if (this == &other) return *this;

    for (int i = 0; i < 3; i++) delete[] data[i];
    delete[] data;

    data = other.data;
    other.data = nullptr;

    return *this;
}

Matrix33::~Matrix33() {
    // Time: O(1), Space: O(1) — deallocating fixed-size memory
    if (data) {
        for (int i = 0; i < 3; i++) delete[] data[i];
        delete[] data;
    }
}

Matrix33 Matrix33::operator*(const Matrix33& other) {
    // Time: O(1), Space: O(1) — 27 operations (3x3 matrix multiply)
    Matrix33 result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < 3; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];
        }
    return result;
}

Matrix33 Matrix33::operator*(double scalar) {
    // Time: O(1), Space: O(1) — scalar multiplication of 9 elements
    Matrix33 result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result.data[i][j] = data[i][j] * scalar;
    return result;
}

Matrix33 Matrix33::operator+(const Matrix33& other) {
    // Time: O(1), Space: O(1) — adding 9 elements
    Matrix33 result;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

double Matrix33::determinant() {
    // Time: O(1), Space: O(1) — hardcoded 3x3 determinant formula
    double a = data[0][0], b = data[0][1], c = data[0][2];
    double d = data[1][0], e = data[1][1], f = data[1][2];
    double g = data[2][0], h = data[2][1], i = data[2][2];
    return a * (e * i - f * h) -
           b * (d * i - f * g) +
           c * (d * h - e * g);
}

ostream& operator<<(ostream& out, const Matrix33& mat) {
    // Time: O(1), Space: O(1) — printing fixed-size 3x3 matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            out << mat.data[i][j] << " ";
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, Matrix33& mat) {
    // Time: O(1), Space: O(1) — reading 9 inputs
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            in >> mat.data[i][j];
    return in;
}
