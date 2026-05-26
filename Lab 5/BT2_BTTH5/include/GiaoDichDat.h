#ifndef GIAODICHDAT_H
#define GIAODICHDAT_H
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
private:
    char loaiDat;
public:
    void Nhap();
    void Xuat();
    void TinhThanhTien();
};
#endif
