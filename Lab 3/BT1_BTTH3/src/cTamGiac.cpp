#include "cTamGiac.h"
#include "cDiem.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
cTamGiac::cTamGiac(){};
cTamGiac::cTamGiac(cDiem a, cDiem b, cDiem c) : A(a), B(b), C(c) {}

/* Hàm tính độ dài cạnh
Đàu vào: Biến để lưu độ dài, điểm
Đầu ra: Độ dài cạnh */
void cTamGiac::DoDaiCanh(double &a, double &b, double &c){
    a = A.KhoangCach(B);
    b = B.KhoangCach(C);
    c = C.KhoangCach(A);
}

/* Hàm kiểm tra tam giác có hợp lệ
Đàu vào: Các điểm tam giác
Đầu ra: True nếu tam giác hợp lệ, False nếu ngược lại */
bool cTamGiac::HopLe() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    return (a + b > c && a + c > b && b + c > a);
}

/* Hàm nhập
Đàu vào: Được input qua .Nhap()
Đầu ra: Các điểm đã có tọa độ và hợp lệ
Nếu Input sai, sẽ phải nhập lại*/
void cTamGiac::Nhap() {
    while(1){
        cout << "Nhap diem A: "; A.Nhap();
        cout << "Nhap diem B: "; B.Nhap();
        cout << "Nhap diem C: "; C.Nhap();
        //Kiểm tra tam giác có hợp lệ
        if (!HopLe()) cout << "Tam giac khong hop le, vui long nhap lai\n";
        else break; // Nếu thỏa mãn thì break, kết thúc vòng lặp
    }
}

/* Hàm xuất
Đàu vào: Các điểm tam giác
Đầu ra: Tọa độ từng điểm qua .Xuat()*/
void cTamGiac::Xuat() {
    cout << "A"; A.Xuat();
    cout << " B"; B.Xuat();
    cout << " C"; C.Xuat();
    cout << endl;
}

/* Hàm kiểm tra loại tam giác
Đàu vào: Các điểm tam giác
Đầu ra: Loại tam giác tùy vào điều kiện thỏa mãn */
void cTamGiac::KiemTraLoai() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6) // Kiểm tra 3 cạnh có bằng nhau hay không
        cout << "Tam giac deu\n";
    else if (fabs(a - b) < 1e-6 || fabs(b - c) < 1e-6 || fabs(a - c) < 1e-6) // kiểm tra 2 cạnh bên có bằng nhau (VD: AB - BC = 0 => AB = BC)
        cout << "Tam giac can\n";
    else if (fabs(a*a + b*b - c*c) < 1e-6 ||
                fabs(a*a + c*c - b*b) < 1e-6 ||
                fabs(b*b + c*c - a*a) < 1e-6) //Kiểm tra cách cạnh theo định lý Pythagore đảo
        cout << "Tam giac vuong\n";
    else
        cout << "Tam giac thuong\n";
}

/* Hàm tính chu vi
Đàu vào: Các điểm tam giác
Đầu ra: Chu vi tam giác */
double cTamGiac::ChuVi() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    return a + b + c;
}

/* Hàm tính diện tích
Đàu vào: Các điểm tam giác
Đầu ra: Diện tích tam giác */
double cTamGiac::DienTich() {
    double a, b, c;
    DoDaiCanh(a, b, c);

    double p = ChuVi() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/* Hàm tính tịnh tiến
Đàu vào: Các điểm tam giác, tọa độ vector tịnh tiến
Đầu ra: Diểm tam giác sau khi tịnh tiến */
cTamGiac cTamGiac::TinhTien(double dx, double dy) {
    return cTamGiac(
        A.TinhTien(dx, dy),
        B.TinhTien(dx, dy),
        C.TinhTien(dx, dy)
    );
}

/* Hàm phóng to
Đàu vào: Các điểm tam giác, tỉ số phóng to
Đầu ra: Điểm tam giác sau khi phóng to */
cTamGiac cTamGiac::PhongTo(double k) {
    return cTamGiac(
        A.PhongTo(k),
        B.PhongTo(k),
        C.PhongTo(k)
    );
}

/* Hàm thu nhỏ
Đàu vào: Các điểm tam giác, tỉ số thu nhỏ
Đầu ra: Điểm tam giác sau khi thu nhỏ */
cTamGiac cTamGiac::ThuNho(double k) {
    return cTamGiac(
        A.ThuNho(k),
        B.ThuNho(k),
        C.ThuNho(k)
    );
}

/* Hàm quay
Đàu vào: Các điểm tam giác, góc quay theo đơn vị độ
Đầu ra: Điểm tam giác sau khi quay */
cTamGiac cTamGiac::Quay(double goc) {
    return cTamGiac(
        A.Quay(goc),
        B.Quay(goc),
        C.Quay(goc)
    );
}
