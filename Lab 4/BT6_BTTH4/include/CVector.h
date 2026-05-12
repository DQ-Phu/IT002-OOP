#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>

class CVector {
private:
    int n;              // Số chiều của vector
    double* data;       // Mảng động chứa các thành phần của vector

public:
    // Nhóm khởi tạo và hủy
    CVector(int dimensions = 0);           // Khởi tạo vector n chiều
    CVector(const CVector& other);         // Copy Constructor (Deep copy)
    ~CVector();                            // Destructor

    // Toán tử gán
    CVector& operator=(const CVector& other);

    friend std::istream& operator>>(std::istream& is, CVector& v);
    friend std::ostream& operator<<(std::ostream& os, const CVector& v);

    CVector operator+(const CVector& other) const;
    CVector operator-(const CVector& other) const;

    CVector operator*(double scalar) const;
    double operator*(const CVector& other) const;

    // Truy cập phần tử
    double& operator[](int index);
    const double& operator[](int index) const;

    // Hàm bổ trợ
    int getDimension() const;
    double length() const;
};

#endif
