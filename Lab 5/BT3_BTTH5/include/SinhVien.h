#ifndef SINHVIEN_H
#define SINHVIEN_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class SinhVien {
protected:
    string mssv, hoTen, diaChi;
    int tongTinChi;
    double diemTB;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual bool KiemTraTotNghiep() = 0;

    double getDiemTB() const;
    virtual ~SinhVien() {}
};

#endif
