#ifndef NVSX_H
#define NVSX_H
#include "NhanVien.h"

class NVSX : public NhanVien {
    double luongCB;
    int soSP;
public:
    void Nhap();
    double TinhLuong() override;
    void Xuat();
};
#endif
