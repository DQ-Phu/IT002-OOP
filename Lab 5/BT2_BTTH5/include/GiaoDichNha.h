#ifndef GIAODICHNHA_H
#define GIAODICHNHA_H
#include "GiaoDich.h"

class GiaoDichNha : public GiaoDich {
private:
    string loaiNha, diaChi;
public:
    void Nhap();
    void Xuat();
    void TinhThanhTien();
};
#endif
