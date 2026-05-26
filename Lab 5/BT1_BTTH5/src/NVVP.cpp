#include "NVVP.h"

void NVVP::Nhap() {
    NhanVien::Nhap();
    while (true) {
        cout << "Nhap so ngay lam viec: ";
        if (!(cin >> soNgay) || cin.peek() != '\n' || soNgay < 0) {
            cout << "Loi! Nhap so nguyen duong.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
}

double NVVP::TinhLuong(){
    return luong = soNgay * 100000.0;
}

void NVVP::Xuat() {
    cout << "[Van Phong] ";
    NhanVien::Xuat();
    cout << " | So ngay: " << soNgay << endl;
}
