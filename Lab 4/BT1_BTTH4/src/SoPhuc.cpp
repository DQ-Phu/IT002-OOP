#include "SoPhuc.h"
#include <iostream>
#include <limits>
using namespace std;

//Cóntructor
SoPhuc::SoPhuc(double r, double i) : iThuc(r), iAo(i) {}

// Toán tử nhập >>
istream& operator>>(istream& is, SoPhuc& sp) {
    while(true){
        cout << "Nhap phan thuc: ";
        is >> sp.iThuc;

        // Kiểm tra có kí tự trong input không
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi nhap so thuc!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Nhap phan ao: ";
        is >> sp.iAo;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi nhap so thuc!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    return is;
}

// Toán tử xuất <<
ostream& operator<<(ostream& os, const SoPhuc& sp) {
    os << sp.iThuc;
    if (sp.iAo >= 0) os << " + " << sp.iAo << "i";
    else os << " - " << abs(sp.iAo) << "i";
    return os;
}

/* Toán tử cộng 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là tổng 2 số phức */
SoPhuc SoPhuc::operator+(const SoPhuc& b) const {
        return SoPhuc(iThuc + b.iThuc, iAo + b.iAo);
}

/* Toán tử trừ 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là hiệu 2 số phức */
SoPhuc SoPhuc::operator-(const SoPhuc& b) const {
        return SoPhuc(iThuc - b.iThuc, iAo - b.iAo);
}

/* Toán tử nhân 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là tích 2 số phức */
SoPhuc SoPhuc::operator*(const SoPhuc& b) const {
        return SoPhuc(iThuc * b.iThuc - iAo * b.iAo,
                      iThuc * b.iAo + iAo * b.iThuc);
}

/* Toán tử chia 2 số phức
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là thương 2 số phức */
SoPhuc SoPhuc::operator/(const SoPhuc& b) const {
        double mau = b.iThuc * b.iThuc + b.iAo * b.iAo;
        if (mau == 0) {
            cout << "Khong the chia cho so phuc bang 0" << endl;
            return SoPhuc(0, 0);
        }
        return SoPhuc((iThuc * b.iThuc + iAo * b.iAo) / mau,
                      (iAo * b.iThuc - iThuc * b.iAo) / mau);
}

/* Toán tử so sánh bằng
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là true nếu 2 số phức bằng nhau, false nếu ngược lại */
bool SoPhuc::operator==(const SoPhuc& b) const {
    return (iThuc == b.iThuc && iAo == b.iAo);
}

/* Toán tử so sánh khác
Đầu vào phần thực và phần ảo của 2 số phức
Đầu ra là true nếu 2 số phức không bằng nhau, false nếu ngược lại */
bool SoPhuc::operator!=(const SoPhuc& b) const {
        return !(iThuc == b.iThuc && iAo == b.iAo);
}
