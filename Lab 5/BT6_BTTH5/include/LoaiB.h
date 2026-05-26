#ifndef LOAIB_H
#define LOAIB_H
#include "KhachHang.h"

class LoaiB : public KhachHang {
private:
    int soNamThanThiet;
public:
    void docFile(ifstream &is) override;
    double tinhTien() override;
};
#endif
