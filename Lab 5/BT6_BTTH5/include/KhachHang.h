#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class KhachHang {
protected:
    string hoTen;
    long long soLuong;
    long long donGia;

public:
    virtual void docFile(ifstream &is);
    virtual void ghiFile(ofstream &os);
    virtual double tinhTien() = 0;
    virtual ~KhachHang() {}
};

#endif
