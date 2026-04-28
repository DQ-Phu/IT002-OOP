#include "cDiem.h"
#include "cTamGiac.h"
#include <iostream>
#include <limits>
#include <cmath>

#define PI 3.14159265358979323846
using namespace std;

// Constructor
cDiem::cDiem(double x, double y) : x(x), y(y) {}

/* Hàm nhập
Đàu vào: Input tọa độ điểm */
void cDiem::Nhap() {
    cout << endl;
    while(true){
        cout << "x = "; cin >> x;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra input có phải là số thực
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }

        cout << "y = "; cin >> y;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra input có phải là số thực
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nLoi! Vui long nhap lai!\n";
            continue;
        }
        //Nếu thỏa mãn thì break
        break;
    }
}

/* Hàm xuất
Đàu vào: Thông tin tọa độ điểm x, y
Đầu ra: Xuất tọa độ điểm */
void cDiem::Xuat() {
    // Làm tròn số khi số gần  bằng 0
    double tx = (fabs(x) < 1e-9) ? 0 : x;
    double ty = (fabs(y) < 1e-9) ? 0 : y;

    cout << "(" << tx << ", " << ty << ")";
}

/* Hàm tinh khoảng cách giữa 2 điểm
Đàu vào: 2 điểm
Đầu ra: Khoảng cách giưa 2 điểm */
double cDiem::KhoangCach(cDiem b) {
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

/* Hàm tịnh tiến
Đàu vào: Tọa độ vector tịnh tiến, tọa độ điểm
Đầu ra: Tọa độ điểm sau khi tịnh tiến */
cDiem cDiem::TinhTien(double dx, double dy) {
    return cDiem(x + dx, y + dy);
}

/* Hàm phóng to
Đàu vào: Tỷ số phóng to, tọa độ điểm
Đầu ra: Tọa độ điểm sau khi phóng to */
cDiem cDiem::PhongTo(double k) {
    return cDiem(x * k, y * k);
}

/* Hàm thu nhỏ
Đàu vào: Tỷ số thu nhỏ, tọa độ điểm
Đầu ra: Tọa độ điểm sau khi thu nhỏ */
cDiem cDiem::ThuNho(double k) {
    return cDiem(x / k, y / k);
}

/* Hàm quay
Đàu vào: Góc quay theo độ, tọa độ điểm
Đầu ra: Tọa độ điểm sau khi quay */
cDiem cDiem::Quay(double goc) {
    double rad = goc * PI / 180; // chuyển đơn vị độ sang radian
    double nx = x * cos(rad) - y * sin(rad);
    double ny = x * sin(rad) + y * cos(rad);
    return cDiem(nx, ny);
}
