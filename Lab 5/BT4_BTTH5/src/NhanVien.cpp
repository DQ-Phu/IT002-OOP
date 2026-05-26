#include "NhanVien.h"

void NhanVien::Nhap() {
    cout << "Nhap ma nhan vien: "; cin >> maNV;
    cin.ignore(1000, '\n');

    while (true) {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        bool hopLe = !hoTen.empty();
        for (char c : hoTen) {
            if (!isalpha(c) && !isspace(c)) { hopLe = false; break; }
        }
        if (hopLe) break;
        cout << "Loi! Ho ten chi chua chu cai.\n";
    }

    while (true) {
        cout << "Nhap tuoi: ";
        if (!(cin >> tuoi) || tuoi < 18 || tuoi > 65) {
            cout << "Loi! Tuoi phai tu 18 - 65.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }

    while (true) {
        cout << "Nhap so dien thoai: ";
        cin >> sdt;
        bool hopLe = true;
        for (char c : sdt) { if (!isdigit(c)) { hopLe = false; break; } }
        if (hopLe) break;
        cout << "Loi! SDT chi chua so.\n";
    }

    cout << "Nhap email: "; cin >> email;

    while (true) {
        cout << "Nhap luong co ban: ";
        if (!(cin >> luongCoBan) || luongCoBan < 0) {
            cout << "Loi! Luong phai >= 0.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

void NhanVien::Xuat() {
    cout << "Ma: " << maNV << " | Ten: " << hoTen << " | Tuoi: " << tuoi
         << " | SDT: " << sdt << " | Email: " << email
         << " | Luong: " << (long long)tongLuong;
}
