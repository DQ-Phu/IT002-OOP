#ifndef NVVP_H
#define NVVP_H
#include "NhanVien.h"

class NVVP : public NhanVien {
    int soNgay;
public:
    void Nhap();
    double TinhLuong() override;
    void Xuat();
};
#endif
