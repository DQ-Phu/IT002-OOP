#ifndef GIAODICH_H
#define GIAODICH_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class GiaoDich {
protected:
    string maGD;
    int ngay, thang, nam;
    double donGia, dienTich, thanhTien;

public:
    virtual void Nhap();
    virtual void Xuat();
    virtual void TinhThanhTien() = 0;

    double getThanhTien() const;
    int getThang() const;
    int getNam() const;

    virtual ~GiaoDich() {}
};

#endif
