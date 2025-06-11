//CSCI335: Software Analysis and Design III
//GISSELLE SAGASTUME{Project \#1}
//Date: June 8th, 2025}


#ifndef MATRIXNM_H
#define MATRIXNM_H

#include <iostream>
#include <vector>

class MatrixNM {
private:
    std::vector<std::vector<double>> data;
    int rows, cols;

public:
    MatrixNM(int n, int m);  // Constructor

    double& operator()(int i, int j);             // Non-const accessor
    const double& operator()(int i, int j) const; // Const accessor

    friend std::ostream& operator<<(std::ostream& out, const MatrixNM& mat);
    friend std::istream& operator>>(std::istream& in, MatrixNM& mat);
};

#endif
