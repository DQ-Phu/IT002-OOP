#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>

class CMatrix {
private:
    int rows, cols;
    double** data;

public:
    CMatrix(int r = 0, int c = 0);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& other);

    double* operator[](int index);
    const double* operator[](int index) const;

    friend std::istream& operator>>(std::istream& is, CMatrix& m);
    friend std::ostream& operator<<(std::ostream& os, const CMatrix& m);

    int getRows() const { return rows; }
    int getCols() const { return cols; }
    bool isColumnVector() const { return (data != nullptr && cols == 1); }

    CMatrix operator*(const CMatrix& other) const;
};

#endif
