#include "SinhVienDH.h"

void SinhVienDH::Nhap() {
    SinhVien::Nhap();
    cin.ignore(1000, '\n');
    cout << "Nhap ten luan van: "; getline(cin, tenLuanVan);
    while (true) {
        cout << "Nhap diem luan van (0-10): ";
        if (!(cin >> diemLuanVan) || diemLuanVan < 0 || diemLuanVan > 10) {
            cout << "Loi! Diem tu 0 den 10.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

bool SinhVienDH::KiemTraTotNghiep() {
    return (tongTinChi >= 170 && diemTB >= 5 && diemLuanVan >= 5);
}

void SinhVienDH::Xuat() {
    cout << "[DH] "; SinhVien::Xuat();
    cout << " | Luan van: " << tenLuanVan << " | Diem LV: " << diemLuanVan << " | " << (KiemTraTotNghiep() ? "DAU" : "TRUOT") << endl;
}
