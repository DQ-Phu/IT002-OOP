#include "SinhVien.h"
#include <cctype>

void SinhVien::Nhap() {
    // Xử lí MSSV
    while (true) {
        cout << "Nhap MSSV (chi chua so): ";
        cin >> mssv;

        bool hopLe = !mssv.empty();
        for (char c : mssv) {
            if (!isdigit(c)) {
                hopLe = false;
                break;
            }
        }

        if (hopLe) {
            cin.ignore(1000, '\n');
            break;
        }

        cout << "Loi! MSSV khong hop le (chi duoc nhap so).\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Xử lí họ tên
    while (true) {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        bool hopLe = !hoTen.empty();
        for (char c : hoTen) {
            if (!isalpha(c) && !isspace(c)) {
                hopLe = false;
                break;
            }
        }

        if (hopLe) break;
        cout << "Loi! Ho ten chi duoc chua chu cai va khoang trang.\n";
    }

    // Nhập địa chỉ
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);

    // Xử lí tổng tín chỉ
    while (true) {
        cout << "Nhap tong so tin chi: ";
        if (!(cin >> tongTinChi) || tongTinChi < 0) {
            cout << "Loi! So tin chi phai la so nguyen duong.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    }

    // Xử lí điểm TB
    while (true) {
        cout << "Nhap diem trung binh (0-10): ";
        if (!(cin >> diemTB) || diemTB < 0 || diemTB > 10) {
            cout << "Loi! Diem phai trong khoang tu 0 den 10.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        } else break;
    }
}

void SinhVien::Xuat() {
    cout << "MSSV: " << mssv << " | Ten: " << hoTen
         << " | TC: " << tongTinChi << " | DTB: " << diemTB;
}

double SinhVien::getDiemTB() const {
    return diemTB;
}
