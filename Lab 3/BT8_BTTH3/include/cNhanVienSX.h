#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    Date ngaySinh;
    int soSP;
    double donGia;

public:
    // Constructor
    cNhanVienSX();

    // Nhập/Xuất
    void nhap();
    void xuat();

    // Hàm xử lí
    long long tinhLuong();

    // Hàm get
    Date getNgaySinh();
};

#endif // CNHANVIENSX_H
