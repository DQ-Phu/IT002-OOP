#include "NhanVien.h"

void NhanVien::Nhap() {
    // Xử lí họ tên
    while (true) {
        cout << "Nhap ho ten (chi chu cai): ";
        getline(cin, hoTen);
        bool hopLe = !hoTen.empty();
        for (char c : hoTen) {
            if (!isalpha(c) && !isspace(c)) { hopLe = false; break; }
        }
        if (hopLe) break;
        cout << "Loi! Ten khong hop le.\n";
    }

    // Xử lí năm
    while (true) {
        cout << "Nhap nam sinh (1900-2024): ";
        if (!(cin >> nam) || cin.peek() != '\n' || nam < 1900 || nam > 2024) {
            cout << "Loi! Nhap nam tu 1900-2024.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    // Xử lí tháng
    while (true) {
        cout << "Nhap thang sinh (1-12): ";
        if (!(cin >> thang) || cin.peek() != '\n' || thang < 1 || thang > 12) {
            cout << "Loi! Nhap thang 1-12.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    // Xử lí ngày
    int maxNgay = 31;
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) maxNgay = 30;
    else if (thang == 2) {
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) maxNgay = 29;
        else maxNgay = 28;
    }
    while (true) {
        cout << "Nhap ngay sinh (1-" << maxNgay << "): ";
        if (!(cin >> ngay) || cin.peek() != '\n' || ngay < 1 || ngay > maxNgay) {
            cout << "Loi! Ngay khong hop le cho thang nay.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << hoTen << " | Ngay sinh: "
         << (ngay < 10 ? "0" : "") << ngay << "/"
         << (thang < 10 ? "0" : "") << thang << "/" << nam
         << " | Luong: " << (long long)luong;
}
