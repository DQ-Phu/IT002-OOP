#include "KhachHang.h"

void KhachHang::docFile(ifstream &is) {
    is.ignore();
    getline(is, hoTen);
    is >> soLuong >> donGia;
}

void KhachHang::ghiFile(ofstream &os) {
    os << hoTen << endl;
    os << (long long)tinhTien() << endl;
}
