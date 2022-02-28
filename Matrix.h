//
// Created by jakubb on 28.02.2022.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H


#include <utility>

class Matrix {
private:
    double ** tab;
    int n,m;
public:
    Matrix(int n,int m, double **tab);
    Matrix(const Matrix& matrix);
    Matrix(Matrix && matrix);
    virtual ~Matrix();
    Matrix& operator=(const Matrix& matrix);

};


#endif //MATRIX_MATRIX_H
