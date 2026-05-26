#include "GiaoDichNha.h"

void GiaoDichNha::Nhap() {
    GiaoDich::Nhap();
    cin.ignore(1000, '\n');
    while (true) {
        cout << "Nhap loai nha (cao cap / thuong): "; getline(cin, loaiNha);
        if (loaiNha == "cao cap" || loaiNha == "thuong") break;
        cout << "Loi! Nhap dung 'cao cap' hoac 'thuong'.\n";
    }
    cout << "Nhap dia chi: "; getline(cin, diaChi);
}

void GiaoDichNha::TinhThanhTien() {
    if (loaiNha == "cao cap") thanhTien = dienTich * donGia;
    else thanhTien = dienTich * donGia * 0.9;
}

void GiaoDichNha::Xuat() {
    cout << "[NHA] "; GiaoDich::Xuat();
    cout << " | Loai: " << loaiNha << " | DC: " << diaChi << endl;
}
