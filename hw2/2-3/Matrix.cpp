#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix() {
    col = 31;
    row = 31;
    elem = new int *[row];
    for(int i = 0; i < row; i ++) {
        elem[i] = new int [col];
    }
}

Matrix::Matrix(int _row, int _col) {
    col = _col;
    row = _row;
    elem = new int *[row];
    for(int i = 0; i < row; i ++) {
        elem[i] = new int [col];
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < row; i ++) {
        delete[] elem[i];
    }
}

Matrix Matrix::operator+(const Matrix& x) {
    Matrix res(x.row, x.col);
    for(int i = 0; i < this->row; i ++) {
        for(int j = 0; j < this->row; j ++) {
            res.elem[i][j] = this->elem[i][j] + x.elem[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix& x) {
    Matrix res(x.row, x.col);
    for(int i = 0; i < this->row; i ++) {
        for(int j = 0; j < this->row; j ++) {
            res.elem[i][j] = this->elem[i][j] - x.elem[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const int x) {
    Matrix res(this->row, this->col);
    for(int i = 0; i < this->row; i ++) {
        for(int j = 0; j < this->col; j ++) {
            res.elem[i][j] = x * this->elem[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix &x) {
    Matrix res(this->row, x.col);
    for(int i = 0; i < this->row; i ++) {
        for(int j = 0; j < x.col; j ++) {
            res.elem[i][j] = 0;
            for(int k = 0; k < this->col; k ++) {
                res.elem[i][j] += this->elem[i][k] * x.elem[k][j];
            }
        }
    }
    return res;
}

Matrix transpose(const Matrix &x) {
    Matrix res(x.col, x.row);
    for(int i = 0; i < x.col; i ++) {
        for(int j = 0; j < x.row; j ++) {
            res.elem[i][j] = x.elem[j][i];
        }
    }
    return res;
}

int* Matrix::operator[](int x) const {
    int* res = this->elem[x];
    return res;
}

ostream& operator<<(ostream& out, const Matrix& x) {
    for(int i = 0; i < x.row; i ++) {
        for(int j = 0; j < x.col; j ++) {
            out << x.elem[i][j] << " \n"[j == (x.col - 1)];
        }
    }
    return out;
}

istream& operator>>(istream& in, Matrix& x) {
    in >> x.row >> x.col;
    for(int i = 0; i < x.row; i ++) {
        for(int j = 0; j < x.col; j ++) {
            in >> x.elem[i][j];
        }
    }
    return in;
}