#include "NVSX.h"

void NVSX::Nhap() {
    NhanVien::Nhap();
    while (true) {
        cout << "Nhap luong can ban: ";
        if (!(cin >> luongCB) || cin.peek() != '\n' || luongCB < 0) {
            cout << "Loi! Nhap so tien duong.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    while (true) {
        cout << "Nhap so san pham: ";
        if (!(cin >> soSP) || cin.peek() != '\n' || soSP < 0) {
            cout << "Loi! Nhap so luong duong.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
}

double NVSX::TinhLuong(){
    return luong = luongCB + (soSP * 5000.0);
}

void NVSX::Xuat() {
    cout << "[San Xuat ] ";
    NhanVien::Xuat();
    cout << " | San pham: " << soSP << endl;
}
