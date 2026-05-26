#include "LoaiB.h"

void LoaiB::docFile(ifstream &is) {
    KhachHang::docFile(is);
    is >> soNamThanThiet;
}

double LoaiB::tinhTien() {
    double phanTramKM = max(soNamThanThiet * 0.05, 0.5);
    double tienSauGiam = (soLuong * donGia) * (1.0 - phanTramKM);
    return tienSauGiam * 1.1;
}
