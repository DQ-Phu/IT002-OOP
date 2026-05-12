#include <iostream>
#include <iomanip>  // Để định dạng số thập phân
#include <limits>
#include "CDate.h"

using namespace std;

int main() {
    double soTienGoc;
    double laiSuatNam;
    CDate ngayGui, ngayRut;

    while (true) {
        cout << "+ Nhap so tien gui goc (VND): ";
        cin >> soTienGoc;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } else if (soTienGoc < 0){
        cout << "So tien khong duoc am!\n";
        continue;
        }
        break;
    }

    while (true) {
        cout << "+ Nhap lai suat nam (%): ";
        cin >> laiSuatNam;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }else if (laiSuatNam < 0){
            cout << "Lai suat nam khong duoc am!\n";
            continue;
        }
        break;
    }
    cout << "\n+ Nhap ngay gui ";
    cin >> ngayGui;

    NhapLai: // Vòng lặp lệnh goto khi lỗi logic
    cout << "+ Nhap ngay rut ";
    cin >> ngayRut;

    // 3. Tính toán số ngày gửi bằng toán tử - (khoảng cách giữa 2 CDate)
    long soNgayGui = ngayRut - ngayGui;

    // Kiểm tra logic
    if (soNgayGui < 0) {
        cout << "Loi! Ngay rut khong the truoc ngay gui!" << endl;
        goto NhapLai;
    } else if (soNgayGui == 0) {
        cout << "\nLoi! Ngay rut khong the trung ngay gui!" << endl;
        goto NhapLai;
    } else {
        // Áp dụng công thức tính lãi
        double tienLai = soTienGoc * (laiSuatNam / 100.0) * (soNgayGui / 365.0);

        cout << "\n-----------------------------------------------" << endl;
        cout << "KET QUA TINH TOAN:" << endl;
        cout << "Ngay bat dau: " << ngayGui << endl;
        cout << "Ngay ket thuc: " << ngayRut << endl;
        cout << "Tong thoi gian gui: " << soNgayGui << " ngay" << endl;

        cout << fixed << setprecision(0);
        cout << "- Tien lai nhan duoc: " << tienLai << " VND" << endl;
        cout << "- Tong so tien (Goc + Lai): " << (soTienGoc + tienLai) << " VND" << endl;
        cout << "-----------------------------------------------" << endl;
    }

    // 5. Minh họa các phép toán khác của lớp CDate theo yêu cầu đề bài
    cout << "\n[CAC PHEP TOAN]:" << endl;
    CDate Date = ngayGui;
    cout << "Ngay gui ban dau:    " << Date << endl;

    Date++;
    cout << "Sau khi ++ (1 ngay): " << Date << endl;

    Date = ngayGui;
    Date--;
    cout << "Sau khi -- (1 ngay): " << Date << endl;

    Date = ngayGui;
    int n;

    while (true) {
        cout << "\nNhap so ngay can cong: ";
        cin >> n;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    Date = Date + n;
    cout << "Sau khi + " << n << " ngay:   " << Date << endl;



    return 0;
}
