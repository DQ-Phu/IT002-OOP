#ifndef SINHVIENCD_H
#define SINHVIENCD_H
#include "SinhVien.h"

class SinhVienCD : public SinhVien {
private:
    double diemThiTN;
public:
    void Nhap();
    void Xuat();
    bool KiemTraTotNghiep();
};
#endif
