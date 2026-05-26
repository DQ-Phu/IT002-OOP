#include "GiaoDich.h"

void GiaoDich::Nhap() {
    cout << "Nhap ma giao dich: "; cin >> maGD;

    // Xử lí năm
    while (true) {
        cout << "Nhap nam giao dich (1900-2024): ";
        if (!(cin >> nam) || cin.peek() != '\n' || nam < 1900 || nam > 2024) {
            cout << "Loi! Nhap nam tu 1900-2024.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    // Xử lí tháng
    while (true) {
        cout << "Nhap thang giao dich (1-12): ";
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
        cout << "Nhap ngay giao dich (1-" << maxNgay << "): ";
        if (!(cin >> ngay) || cin.peek() != '\n' || ngay < 1 || ngay > maxNgay) {
            cout << "Loi! Ngay khong hop le cho thang nay.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    while (true) {
        cout << "Nhap don gia: ";
        if (!(cin >> donGia) || donGia < 0) {
            cout << "Loi don gia! Nhap lai.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
    while (true) {
        cout << "Nhap dien tich: ";
        if (!(cin >> dienTich) || dienTich < 0) {
            cout << "Loi dien tich! Nhap lai.\n";
            cin.clear(); cin.ignore(1000, '\n');
        } else break;
    }
}

void GiaoDich::Xuat() {
    cout << "Ma: " << maGD << " | Ngay: " << (ngay < 10 ? "0" : "") << ngay
         << "/" << (thang < 10 ? "0" : "") << thang << "/" << nam
         << " | Don gia: " << (long long)donGia << " | DT: " << dienTich
         << " | Thanh tien: " << (long long)thanhTien;
}

double GiaoDich::getThanhTien() const { return thanhTien; }
int GiaoDich::getThang() const { return thang; }
int GiaoDich::getNam() const { return nam; }
