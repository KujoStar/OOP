#pragma once
#include <iostream>
using namespace std;

class Matrix {
private:
    int** elem;
    int col, row;
    
public:
    Matrix();
    Matrix(int _row, int _col);
    ~Matrix();

    Matrix operator+(const Matrix& x);
    Matrix operator-(const Matrix& x);
    Matrix operator*(const int x);
    Matrix operator*(const Matrix& x);
    friend Matrix transpose(const Matrix& x);
    int* operator[](int x) const;
    friend ostream& operator<<(ostream& out, const Matrix& x);
    friend istream& operator>>(istream& in, Matrix& x);
};
