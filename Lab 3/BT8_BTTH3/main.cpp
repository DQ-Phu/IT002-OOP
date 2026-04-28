#include "cNhanVienSX.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/* Hàm Quick Sort sắp xếp tăng dần
Đàu vào: Thông tin nhân viên, index bên trái cùng và bên phải cùng
Mục đích: sắp xếp danh sách nhân viên theo chiều tăng dần lương của nhân viên*/
void QuickSort(vector<cNhanVienSX>& ds, int l, int r) {
    int i = l, j = r;
    double x = ds[(l + r) / 2].tinhLuong();

    while (i <= j) {
        while (ds[i].tinhLuong() < x) i++;
        while (ds[j].tinhLuong() > x) j--;

        if (i <= j) {
            swap(ds[i], ds[j]);
            i++;
            j--;
        }
    }

    if (l < j) QuickSort(ds, l, j);
    if (i < r) QuickSort(ds, i, r);
}

/* Hàm so sánh năm sinh
Đàu vào: Thông tin của 2 nhân viên
Đầu ra: True nếu nhân viên 1 lớn tuổi hơn nhân viên 2. Ngược lại thì false
So sánh băng cách đối chiếu ngày sinh*/
bool SoSanhTuoi(cNhanVienSX a, cNhanVienSX b) {
    Date A = a.getNgaySinh();
    Date B = b.getNgaySinh();

    if (A.year != B.year) return A.year < B.year;
    if (A.month != B.month) return A.month < B.month;
    return A.day < B.day;
}

int main() {
    int n;

    while(1){
        cout << "Nhap so luong nhan vien : ";
        cin >> n;
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
        if (n <= 0){
            cout << "So luong nhan vien phai lon hon 0!\n";
            continue;
        }
        break;
    }
    vector<cNhanVienSX> ds(n);

    // Nhập
    for (int i = 0; i < n; i++) {
        cout << "\nNhap nhan vien thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Xuất
    cout << "\nDanh sach:\n";
    for (auto &nv : ds) {
        nv.xuat();
    }

    // Tìm lương thấp nhất
    long long minLuong = ds[0].tinhLuong();
    for (auto &nv : ds)
        if (nv.tinhLuong() < minLuong)
            minLuong = nv.tinhLuong();
    cout << "\nNhan vien luong thap nhat:\n";
    for (auto &nv : ds)
        if (nv.tinhLuong() == minLuong)
            nv.xuat();

    // Tìm tổng lương công ty phải trả
    long long tong = 0;
    for (auto &nv : ds)
        tong += nv.tinhLuong();
    cout << "\nTong luong: " << tong << endl;

    // Tìm nhân viên lớn tuổi nhất
    cNhanVienSX oldest = ds[0];
    for (auto &nv : ds) {
        if (SoSanhTuoi(nv, oldest)) {
            oldest = nv;
        }
    }
    cout << "\nNhan vien lon tuoi nhat:\n";
    oldest.xuat();

    // Sắp xếp danh sách nhân viên theo lương tăng dần
    QuickSort(ds, 0, ds.size() - 1);
    cout << "\nDanh sach sau sap xep:\n";
    for (auto &nv : ds)
        nv.xuat();

    return 0;
}
