#include "CTime.h"
#include <iostream>
#include <limits>

using namespace std;

// Constructor
CTime::CTime(int h, int m, int s) : gio(h), phut(m), giay(s) {
    ChuanHoa();
}

// Toán tử nhập
istream& operator>>(istream& is, CTime& t) {
    while (true){
        cout << "Nhap gio: ";
        is >> t.gio;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (t.gio > 24 || t.gio < 0){
            cout << "Loi! Gio khong hop le!\n";
            continue;
        }
        break;
    }

    while (true){
        cout << "Nhap phut: ";
        is >> t.phut;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (t.phut > 59 || t.phut < 0){
            cout << "Loi! Phut khong hop le!\n";
            continue;
        }
        break;
    }

    while(true){
        cout << "Nhap giay: ";
        is >> t.giay;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (t.giay > 59 || t.giay < 0){
            cout << "Loi! Giay khong hop le!\n";
            continue;
        }
        break;
    }

    t.ChuanHoa();
    return is;
}

// Toán tử xuất
ostream& operator<<(ostream& os, const CTime& t) {
    os << setfill('0') << setw(2) << t.gio << ":"
       << setw(2) << t.phut << ":"
       << setw(2) << t.giay;
    return os;
}

// Hàm chuẩn hóa
void CTime::ChuanHoa() {
    long tongGiay = (long)gio * 3600 + phut * 60 + giay;
    if (tongGiay < 0) {
        tongGiay = 86400 + (tongGiay % 86400);
    }
    tongGiay %= 86400;
    gio = tongGiay / 3600;
    phut = (tongGiay % 3600) / 60;
    giay = tongGiay % 60;
}

/* Toán tử +
Đầu vào thoi gian hiên tại và số giây cần cộng
Đầu ra là thoi gian sau khi cộng thêm s giây*/
CTime CTime::operator+(int s) {
    return CTime(gio, phut, giay + s);
}

/* Toán tử -
Đầu vào thoi gian hiên tại và số giây cần trừ
Đầu ra là thoi gian sau khi trừ đi s giây*/
CTime CTime::operator-(int s) {
    return CTime(gio, phut, giay - s);
}

/* Toán tử ++
Đầu vào thoi gian hiên tại
Đầu ra là thoi gian sau khi cong them 1 giây*/
CTime& CTime::operator++() {
    giay++;
    ChuanHoa();
    return *this;
}
CTime CTime::operator++(int) {
    CTime temp = *this;
    ++(*this);
    return temp;
}

/* Toán tử --
Đầu vào thoi gian hiên tại
Đầu ra là thoi gian sau khi trừ đi 1 giây*/
CTime& CTime::operator--() {
    giay--;
    ChuanHoa();
    return *this;
}
CTime CTime::operator--(int) {
    CTime temp = *this;
    --(*this);
    return temp;
}
