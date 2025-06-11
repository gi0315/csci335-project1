//CSCI335: Software Analysis and Design III
//GISSELLE SAGASTUME{Project \#1}
//Date: June 8th, 2025}

#include "matrix_nm.h"
using namespace std;

MatrixNM::MatrixNM(int n, int m) : rows(n), cols(m) {
    data.resize(n, std::vector<double>(m, 0.0));
}

double& MatrixNM::operator()(int i, int j) {
    return data[i][j];
}

const double& MatrixNM::operator()(int i, int j) const {
    return data[i][j];
}

ostream& operator<<(ostream& out, const MatrixNM& mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++)
            out << mat.data[i][j] << " ";
        out << endl;
    }
    return out;
}

istream& operator>>(istream& in, MatrixNM& mat) {
    for (int i = 0; i < mat.rows; i++)
        for (int j = 0; j < mat.cols; j++)
            in >> mat.data[i][j];
    return in;
}
