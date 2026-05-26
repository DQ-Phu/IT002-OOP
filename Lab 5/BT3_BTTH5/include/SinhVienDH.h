#ifndef SINHVIENDH_H
#define SINHVIENDH_H
#include "SinhVien.h"

class SinhVienDH : public SinhVien {
private:
    string tenLuanVan;
    double diemLuanVan;
public:
    void Nhap();
    void Xuat();
    bool KiemTraTotNghiep();
};
#endif
