#ifndef CDAGIAC_H
#define CDAGIAC_H
#include "cDiem.h"

class cDaGiac
{
private:
    int n;             // số đỉnh
    cDiem *dsDiem;     // Mảng động chứa danh sách điểm

public:
    cDaGiac();
    cDaGiac(const cDaGiac&other);
    ~cDaGiac();

    void Nhap();
    void Xuat();

    double ChuVi();
    double DienTich();
    void KiemTraLoai();

    cDaGiac TinhTien(double dx, double dy);
    cDaGiac Quay(double goc);
    cDaGiac PhongTo(double k);
    cDaGiac ThuNho(double k);
};

#endif // CDAGIAC_H
