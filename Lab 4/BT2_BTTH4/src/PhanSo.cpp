#include "PhanSo.h"
#include <iostream>
#include <limits>

using namespace std;

/* Hàm tìm ước chung lớn nhất
Đầu vào: 2 số nguyên
Đầu ra: Ước chung lớn nhất của 2 số*/
int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

/* Hàm rút gọn phân số
Đầu vào: tử và mẫu của phân số
Đầu ra: Phân số đã được rút gọn*/
void PhanSo::rutGon() {
    if (mau == 0) return;
    if (mau < 0) { // Luôn giữ dấu ở tử số
        tu = -tu;
        mau = -mau;
    }
    long long GCD = UCLN(abs(tu), abs(mau));
    tu /= GCD;
    mau /= GCD;
}

// Constructor
PhanSo::PhanSo(long long t, long long m) : tu(t), mau(m) {
    if (mau == 0) {
        cerr << "Mau so phai khac 0. Gan mau = 1." << endl;
        mau = 1;
    }
    rutGon();
}

// Toán tử nhập >>
istream& operator>>(istream& is, PhanSo& ps) {
    while (true){
        cout << "Nhap tu so: ";
        is >> ps.tu;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cout << "Nhap mau so (khac 0): ";
        is >> ps.mau;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        //Nếu mẫu bằng 0 thì coi như người dùng nhập số nguyên
        else if (ps.mau == 0){
            cout << "Mau so phai khac 0. Gan mau = 1" << endl;
            ps.mau = 1;
        }
        break;
    }
    ps.rutGon();
    return is;
}

// Toán tử xuất <<
ostream& operator<<(ostream& os, const PhanSo& ps) {
    if (ps.mau == 1) os << ps.tu; // Nếu mẫu = 1 thì in như số nguyên
    else os << ps.tu << "/" << ps.mau;
    return os;
}

/* Toán tử cộng 2 phân số
Đầu vào tử và mẫu của 2 phân số
Đầu ra là tổng 2 phân số */
PhanSo PhanSo::operator+(const PhanSo& b) const {
    return PhanSo(tu * b.mau + b.tu * mau, mau * b.mau);
}

/* Toán tử trừ 2 phân số
Đầu vào tử và mẫu của 2 phân số
Đầu ra là hiệu 2 phân số */
PhanSo PhanSo::operator-(const PhanSo& b) const {
    return PhanSo(tu * b.mau - b.tu * mau, mau * b.mau);
}

/* Toán tử nhân 2 phân số
Đầu vào tử và mẫu của 2 phân số
Đầu ra là tích 2 phân số */
PhanSo PhanSo::operator*(const PhanSo& b) const {
    return PhanSo(tu * b.tu, mau * b.mau);
}

/* Toán tử chia 2 phân số
Đầu vào tử và mẫu của 2 phân số
Đầu ra là thương 2 phân số */
PhanSo PhanSo::operator/(const PhanSo& b) const {
    return PhanSo(tu * b.mau, mau * b.tu);
}

/* Toán tử so sánh bằng
Đầu vào tử và mẫu của 2 phân số
Đầu ra là true nếu 2 phân số bằng nhau, false nếu ngược lại */
bool PhanSo::operator==(const PhanSo& b) const {
    return (tu == b.tu && mau == b.mau);
}

/* Toán tử so sánh lớn hơn
Đầu vào tử và mẫu của 2 phân số
Đầu ra là true nếu phân số A lớn hơn phân số B, false nếu ngược lại */
bool PhanSo::operator>(const PhanSo& b) const {
    return (double)tu/mau > (double)b.tu/b.mau;
}

/* Toán tử so sánh bé hơn
Đầu vào tử và mẫu của 2 phân số
Đầu ra là true nếu phân số A bé hơn phân số B, false nếu ngược lại */
bool PhanSo::operator<(const PhanSo& b) const {
    return (double)tu/mau < (double)b.tu/b.mau;
}



