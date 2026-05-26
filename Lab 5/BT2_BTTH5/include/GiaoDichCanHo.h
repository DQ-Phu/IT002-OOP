#ifndef GIAODICHCANHO_H
#define GIAODICHCANHO_H
#include "GiaoDich.h"

class GiaoDichCanHo : public GiaoDich {
private:
    string maCan;
    int viTriTang;
public:
    void Nhap();
    void Xuat();
    void TinhThanhTien();
};
#endif
