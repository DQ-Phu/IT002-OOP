#include "GiaoDichDat.h"

void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();
    while (true) {
        cout << "Nhap loai dat (A/B/C): "; cin >> loaiDat;
        loaiDat = toupper(loaiDat);
        if (loaiDat == 'A' || loaiDat == 'B' || loaiDat == 'C') break;
        cout << "Loi! Chi nhap A, B, hoac C.\n";
    }
}

void GiaoDichDat::TinhThanhTien() {
    if (loaiDat == 'A') thanhTien = dienTich * donGia * 1.5;
    else thanhTien = dienTich * donGia;
}

void GiaoDichDat::Xuat() {
    cout << "[DAT] "; GiaoDich::Xuat();
    cout << " | Loai: " << loaiDat << endl;
}
