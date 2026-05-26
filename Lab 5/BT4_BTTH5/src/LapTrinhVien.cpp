#include "LapTrinhVien.h"

void LapTrinhVien::Nhap() {
    NhanVien::Nhap();
    while (true) {
        cout << "Nhap so gio overtime: ";
        if (!(cin >> soGioOvertime) || soGioOvertime < 0) {
            cout << "Loi! So gio phai >= 0.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

double LapTrinhVien::TinhLuong() {
    tongLuong = luongCoBan + (soGioOvertime * 200000.0);
    return tongLuong;
}

void LapTrinhVien::Xuat() {
    cout << "[LTV] "; NhanVien::Xuat();
    cout << " | Gio OT: " << soGioOvertime << endl;
}
