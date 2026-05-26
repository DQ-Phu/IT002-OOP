#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>

using namespace std;

class NhanVien {
protected:
    string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan, tongLuong;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;

    double getTongLuong() const { return tongLuong; }
    string getHoTen() const { return hoTen; }

    virtual ~NhanVien() {}
};

#endif
