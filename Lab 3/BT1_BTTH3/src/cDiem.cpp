#include "cDiem.h"
#include "cTamGiac.h"
#include <iostream>
#include <cmath>
using namespace std;


cDiem::cDiem(double x, double y) : x(x), y(y) {}

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
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nLoi! Vui long nhap lai!\n";
            continue;
        }
        //Nếu thỏa mãn thì break
        break;
    }
}

void cDiem::Xuat() {
    double tx = (fabs(x) < 1e-9) ? 0 : x;
    double ty = (fabs(y) < 1e-9) ? 0 : y;

    cout << "(" << tx << ", " << ty << ")";
}

double cDiem::KhoangCach(cDiem b) {
    return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
}

cDiem cDiem::TinhTien(double dx, double dy) {
    return cDiem(x + dx, y + dy);
}

cDiem cDiem::PhongTo(double k) {
    return cDiem(x * k, y * k);
}

cDiem cDiem::ThuNho(double k) {
    return cDiem(x / k, y / k);
}

cDiem cDiem::Quay(double goc) {
    double rad = goc * M_PI / 180;
    double nx = x * cos(rad) - y * sin(rad);
    double ny = x * sin(rad) + y * cos(rad);
    return cDiem(nx, ny);
}
