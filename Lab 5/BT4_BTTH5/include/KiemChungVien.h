#ifndef KIEMCHUNGVIEN_H
#define KIEMCHUNGVIEN_H
#include "NhanVien.h"

class KiemChungVien : public NhanVien {
private:
    int soLoiPhatHien;
public:
    void Nhap();
    void Xuat();
    double TinhLuong();
};
#endif
