#include "cTamGiac.h"
#include "cDiem.h"
#include <iostream>
#include <cmath>
using namespace std;

cTamGiac::cTamGiac(){};
cTamGiac::cTamGiac(cDiem a, cDiem b, cDiem c) : A(a), B(b), C(c) {}

void cTamGiac::DoDaiCanh(double &a, double &b, double &c){
    a = A.KhoangCach(B);
    b = B.KhoangCach(C);
    c = C.KhoangCach(A);
}

bool cTamGiac::HopLe() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    return (a + b > c && a + c > b && b + c > a);
}

void cTamGiac::Nhap() {
    while(1){
        cout << "Nhap diem A: "; A.Nhap();
        cout << "Nhap diem B: "; B.Nhap();
        cout << "Nhap diem C: "; C.Nhap();
        if (!HopLe()) cout << "Tam giac khong hop le, vui long nhap lai\n";
        else break;
    }
}

void cTamGiac::Xuat() {
    cout << "A"; A.Xuat();
    cout << " B"; B.Xuat();
    cout << " C"; C.Xuat();
    cout << endl;
}


void cTamGiac::KiemTraLoai() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)
        cout << "Tam giac deu\n";
    else if (fabs(a - b) < 1e-6 || fabs(b - c) < 1e-6 || fabs(a - c) < 1e-6)
        cout << "Tam giac can\n";
    else if (fabs(a*a + b*b - c*c) < 1e-6 ||
                fabs(a*a + c*c - b*b) < 1e-6 ||
                fabs(b*b + c*c - a*a) < 1e-6)
        cout << "Tam giac vuong\n";
    else
        cout << "Tam giac thuong\n";
}

double cTamGiac::ChuVi() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    return a + b + c;
}

double cTamGiac::DienTich() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    double p = ChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

cTamGiac cTamGiac::TinhTien(double dx, double dy) {
    return cTamGiac(
        A.TinhTien(dx, dy),
        B.TinhTien(dx, dy),
        C.TinhTien(dx, dy)
    );
}

cTamGiac cTamGiac::PhongTo(double k) {
    return cTamGiac(
        A.PhongTo(k),
        B.PhongTo(k),
        C.PhongTo(k)
    );
}

cTamGiac cTamGiac::ThuNho(double k) {
    return cTamGiac(
        A.ThuNho(k),
        B.ThuNho(k),
        C.ThuNho(k)
    );
}

cTamGiac cTamGiac::Quay(double goc) {
    return cTamGiac(
        A.Quay(goc),
        B.Quay(goc),
        C.Quay(goc)
    );
}
