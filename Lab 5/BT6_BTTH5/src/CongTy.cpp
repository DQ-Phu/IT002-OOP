#include "CongTy.h"

void CongTy::nhapTuFile(string filename) {
    ifstream is(filename);
    if (!is.is_open()) return;

    is >> x >> y >> z;

    // Đọc x khách hàng loại A
    for (int i = 0; i < x; ++i) {
        KhachHang* kh = new LoaiA();
        kh->docFile(is);
        danhSach.push_back(kh);
    }
    // Đọc y khách hàng loại B
    for (int i = 0; i < y; ++i) {
        KhachHang* kh = new LoaiB();
        kh->docFile(is);
        danhSach.push_back(kh);
    }
    // Đọc z khách hàng loại C
    for (int i = 0; i < z; ++i) {
        KhachHang* kh = new LoaiC();
        kh->docFile(is);
        danhSach.push_back(kh);
    }
    is.close();
}

void CongTy::xuatRaFile(string filename) {
    ofstream os(filename);
    if (!os.is_open()) return;

    os << x << " " << y << " " << z << endl;

    for (auto kh : danhSach) {
        kh->ghiFile(os);
    }

    os << (long long)tinhTongDoanhThu();
    os.close();
}

double CongTy::tinhTongDoanhThu() {
    double tong = 0;
    for (auto kh : danhSach) {
        tong += kh->tinhTien();
    }
    return tong;
}

CongTy::~CongTy() {
    for (auto kh : danhSach) {
        delete kh;
    }
    danhSach.clear();
}
