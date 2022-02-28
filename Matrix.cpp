//
// Created by jakubb on 28.02.2022.
//

#include "Matrix.h"

Matrix::Matrix(const Matrix &matrix) {
    n=matrix.n;
    m=matrix.m;
    tab = new double* [n];
    for(int i=0;i<n;i++)tab[i]=new double[m];
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++)tab[i][j]=matrix.tab[i][j];
    }
}

Matrix::Matrix(Matrix &&matrix) :
        tab(std::move(matrix.tab)),
        n(std::exchange(matrix.n,0))
{}

Matrix::~Matrix() {
    for(int i=0;i<n;i++)delete tab[i];
    delete tab;
}

Matrix::Matrix(int n, int m, double **tab) :n(n),m(m){
    tab = new double* [n];
    for(int i=0;i<n;i++)tab[i] = new double [m];
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if(n!=matrix.n||m!=matrix.m){
        for(int i=0;i<n;i++)delete tab[i];
        delete tab;
        n=matrix.n;
        m=matrix.m;
        tab=new double *[n];
        for(int i=0;i<n;i++)tab[i]=new double [m];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)tab[i][j]=matrix.tab[i][j];
    }
    return *this;
}
