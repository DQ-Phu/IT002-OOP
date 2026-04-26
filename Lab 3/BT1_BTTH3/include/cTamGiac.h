#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include "cDiem.h"


class cTamGiac
{
    private:
        cDiem A, B, C;
    public:
        cTamGiac();
        cTamGiac(cDiem a, cDiem b, cDiem c);

        void DoDaiCanh(double &a, double &b, double &c);
        bool HopLe();

        void Nhap();
        void Xuat();

        void KiemTraLoai();
        double ChuVi();
        double DienTich();
        cTamGiac TinhTien(double dx, double dy);
        cTamGiac Quay(double goc);
        cTamGiac PhongTo(double k);
        cTamGiac ThuNho(double k);
};

#endif // CTAMGIAC_H
