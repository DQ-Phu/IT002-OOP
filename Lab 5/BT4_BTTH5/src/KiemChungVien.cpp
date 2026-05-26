#include "KiemChungVien.h"

void KiemChungVien::Nhap() {
    NhanVien::Nhap();
    while (true) {
        cout << "Nhap so loi phat hien: ";
        if (!(cin >> soLoiPhatHien) || soLoiPhatHien < 0) {
            cout << "Loi! So loi phat hien phai >= 0.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

double KiemChungVien::TinhLuong() {
    tongLuong = luongCoBan + (soLoiPhatHien * 50000.0);
    return tongLuong;
}

void KiemChungVien::Xuat() {
    cout << "[KCV] "; NhanVien::Xuat();
    cout << " | So loi: " << soLoiPhatHien << endl;
}
