#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class NhanVien {
protected:
    string hoTen;
    int ngay, thang, nam;
    double luong;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual double TinhLuong() = 0;

    double getLuong() const { return luong; }
    int getNam() const { return nam; }
    int getThang() const { return thang; }
    int getNgay() const { return ngay; }

    virtual ~NhanVien() {}
};

#endif
