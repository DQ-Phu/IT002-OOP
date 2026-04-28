#include "cNhanVienSX.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
using namespace std;

// Constructor
cNhanVienSX::cNhanVienSX() {
    maNV = "";
    hoTen = "";
    ngaySinh = {0, 0, 0};
    soSP = 0;
    donGia = 0;
}

/* Hàm kiểm tra ngày sinh có hợp lệ
Đầu vào: ngày tháng năm
Đầu ra: True nếu hợp lệ, false nếu không hợp lệ*/
bool KTNgay(int d, int m, int y) {
    if (y < 1900 || y > 2026) return false; //Năm sinh hợp lệ trong khoảng (1900, 2026)
    if (m < 1 || m > 12) return false; //Kiểm tra tháng có hợp lệ

    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    // Kiểm tra năm nhuận
    if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
        daysInMonth[2] = 29;

    return d >= 1 && d <= daysInMonth[m]; //Kiểm tra ngày có hợp lệ
}

/* Hàm nhập
Đàu vào: Input người dùng
Đầu ra: Nếu hợp lệ, lưu vào biến. Ngược lại thông báo lỗi và nhập lại*/
void cNhanVienSX::nhap() {
    cin.ignore();
    //Nhập mã nhân viên
    while(1){
        cout << "Ma NV: "; getline(cin, maNV);
        if (!all_of(maNV.begin(), maNV.end(), ::isdigit)){
            cout << "Ma NV chi duoc co so!\n";
            continue;
        }
        break;
    }

    //Nhập họ tên
    while(1){
        cout << "Ho ten: "; getline(cin, hoTen);
        if (!all_of(hoTen.begin(), hoTen.end(),[](char c)
                    { return isalpha(c) || c == ' '; }))
        {
            cout << "Ho ten chi duoc chua chu cai va khoang trang!\n";
            continue;
        }
        break;
    }

    //Nhập ngày sinh
    while (1){
        cout << "Ngay sinh:\n";
        while (1){
            cout << " - Ngay: "; cin >> ngaySinh.day;
            if (cin.fail()) {
                cout << "Loi! Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // Kiểm tra input có phải là số nguyên
            else if (cin.peek() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Loi! Vui long nhap lai!\n";
                continue;
            }
            break;
        }

        while(1){
            cout << " - Thang: "; cin >> ngaySinh.month;
            if (cin.fail()) {
                cout << "Loi! Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // Kiểm tra input có phải là số nguyên
            else if (cin.peek() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Loi! Vui long nhap lai!\n";
                continue;
            }
            break;
        }

        while(1){
            cout << " - Nam (Tu 1900 den 2026): "; cin >> ngaySinh.year;
            if (cin.fail()) {
                cout << "Loi! Vui long nhap lai!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            // Kiểm tra input có phải là số nguyên
            else if (cin.peek() != '\n') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Loi! Vui long nhap lai!\n";
                continue;
            }
            break;
        }

        if (!KTNgay(ngaySinh.day, ngaySinh.month, ngaySinh.year)) {
            cout << "Ngay sinh khong hop le!\n";
            continue;
        }
        break;
    }

    while(1){
        cout << "So san pham: "; cin >> soSP;
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra input có phải là số nguyên
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        if (soSP <= 0){
            cout << "So san pham khong duoc la so am!";
            continue;
        }
        break;
    }

    while(1){
        cout << "Don gia: "; cin >> donGia;
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra input có phải là số nguyên
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        if (donGia < 0){
            cout << "Don gia khong duoc la so am!";
            continue;
        }
        break;
    }
}

/* Hàm xuất
Đàu vào: Thông tin nhân viên
Đầu ra: Xuất thông tin của nhân viên theo format*/
void cNhanVienSX::xuat() {
    cout << maNV << " \t| "
         << hoTen << " \t| "
         << ngaySinh.day << "/" << ngaySinh.month << "/" << ngaySinh.year
         << " \t| Luong: " << tinhLuong() << endl;
}

/* Hàm tính lương
Đàu vào: Thông tin nhân viên
Đầu ra: Lương của nhân viên*/
long long cNhanVienSX::tinhLuong() {
    return soSP * donGia;
}


/* Thao tác Get
Mục đích: Lấy giá trị từ private ra ngoài class để tính toán*/
Date cNhanVienSX::getNgaySinh() {
    return ngaySinh;
}
