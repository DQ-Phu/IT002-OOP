#include "GiaoDichCanHo.h"

void GiaoDichCanHo::Nhap() {
    GiaoDich::Nhap();
    cout << "Nhap ma can ho: "; cin >> maCan;
    while (true) {
        cout << "Nhap vi tri tang: ";
        if (!(cin >> viTriTang)) {
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

void GiaoDichCanHo::TinhThanhTien() {
    if (viTriTang == 1) thanhTien = dienTich * donGia * 2.0;
    else if (viTriTang >= 15) thanhTien = dienTich * donGia * 1.2;
    else thanhTien = dienTich * donGia;
}

void GiaoDichCanHo::Xuat() {
    cout << "[CH ] "; GiaoDich::Xuat();
    cout << " | Ma can: " << maCan << " | Tang: " << viTriTang << endl;
}
