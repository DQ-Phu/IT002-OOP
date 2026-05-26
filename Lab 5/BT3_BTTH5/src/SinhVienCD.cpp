#include "SinhVienCD.h"

void SinhVienCD::Nhap() {
    SinhVien::Nhap();
    while (true) {
        cout << "Nhap diem thi tot nghiep (0-10): ";
        if (!(cin >> diemThiTN) || diemThiTN < 0 || diemThiTN > 10) {
            cout << "Loi! Diem tu 0 den 10.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

bool SinhVienCD::KiemTraTotNghiep() {
    return (tongTinChi >= 120 && diemTB >= 5 && diemThiTN >= 5);
}

void SinhVienCD::Xuat() {
    cout << "[CD] "; SinhVien::Xuat();
    cout << " | Diem TN: " << diemThiTN << " | " << (KiemTraTotNghiep() ? "DAU" : "TRUOT") << endl;
}
