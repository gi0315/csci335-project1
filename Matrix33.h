//CSCI335: Software Analysis and Design III
//GISSELLE SAGASTUME{Project \#1}
//Date: June 8th, 2025}

#ifndef MATRIX33_H
#define MATRIX33_H

#include <iostream>

class Matrix33 {
private:
    double** data;

public:
    Matrix33();                         // Default constructor
    Matrix33(double arr[3][3]);         // Constructor with 2D array
    Matrix33(const Matrix33& other);    // Copy constructor
    Matrix33(Matrix33&& other);         // Move constructor
    Matrix33& operator=(const Matrix33& other);  // Copy assignment
    Matrix33& operator=(Matrix33&& other);       // Move assignment
    ~Matrix33();                        // Destructor
   double operator()(int row, int col) const;

    Matrix33 operator*(const Matrix33& other);  // Matrix * Matrix
    Matrix33 operator*(double scalar);          // Matrix * Scalar
    Matrix33 operator+(const Matrix33& other);  // Matrix + Matrix

    double determinant();               // Determinant

    friend std::ostream& operator<<(std::ostream& out, const Matrix33& mat);
    friend std::istream& operator>>(std::istream& in, Matrix33& mat);
};

#endif
