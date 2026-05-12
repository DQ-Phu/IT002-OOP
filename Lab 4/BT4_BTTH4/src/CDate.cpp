#include "CDate.h"
#include <iostream>
#include <limits>
using namespace std;

/* Hàm kiểm tra năm nhuận
Đàu vào: Năm
Đầu ra: True nếu là năm nhuận, ngược lại thì False */
bool leapCheck (int Nam)
{
    if ((Nam % 4 == 0 && Nam % 100 != 0) || Nam % 400 == 0)
        return true;
    return false;
}

/*Hàm kiểm tra số ngày trong tháng
Đàu vào: Tháng, Năm
Đầu ra: Số ngày trong tháng đó */
int howManyDays(int Thang, int Nam)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (Thang == 2 && leapCheck(Nam)) //Kiểm tra tháng 2 năm nhuận
        return 29;
    return days[Thang - 1];
}

void CDate::ChuanHoa(){
    while (Ngay > howManyDays(Thang, Nam)) // check nếu ngày vược quá số ngày trong tháng
    {
        Ngay = (Ngay - howManyDays(Thang, Nam));
        Thang++;  // thêm 1 tháng
        if (Thang > 12) { // check nếu tháng vược quá 12
            Thang = 1;
            Nam++; // thêm 1 năm
        }
    }
}

CDate::CDate(int d, int m, int y) : Ngay(d), Thang(m), Nam(y) {
    ChuanHoa();
}

// Toán tử nhập
istream& operator>>(istream& is, CDate& d) {
    while (true) {
        cout << "Nhap theo dinh dang ngay/thang/nam: \n";
        is >> d.Ngay >> d.Thang >> d.Nam;

        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long chi nhap so!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Kiểm tra việc nhập ngày tháng năm có hợp lệ
        if (d.Nam <= 0 || d.Thang < 1 || d.Thang > 12 || d.Ngay < 1) {
            cout << "Loi! Ngay thang nam khong hop le!\n";
            continue;
        }

        // Kiểm tra số ngày có nhiều hơn số ngày trong từng tháng
        if (d.Ngay > howManyDays(d.Thang, d.Nam)) {
            cout << "Loi! Ngay vuoc qua so ngay trong thang!\n";
            continue;
        }

        // Khi thỏa hết điều kiện
        break;
    }
    return is;
}

// Toán tử xuất
ostream& operator<<(ostream& os, const CDate& d) {
    cout << d.Ngay << "/" << d.Thang << "/" << d.Nam << endl;
    return os;
}

//Hàm tính tổng số ngày
// VD: ngày 01/01/0000 có 1 ngày
long CDate::TongSoNgay() const {
    long total = Ngay;
    for (int y = 1; y < Nam; y++) {
        if (leapCheck(y)) total += 366;
        else total += 365;
    }
    for (int m = 1; m < Thang; m++) {
        total += howManyDays(m, Nam);
    }
    return total;
}

/* Toán tử cộng thêm d ngày
Đầu vào ngày tháng năm hiên tại và số ngày cần cộng
Đầu ra là ngày tháng năm sau khi được cộng */
CDate CDate::operator+(int d) {
    return CDate(Ngay + d, Thang, Nam);
}

/* Toán tử trừ d ngày
Đầu vào ngày tháng năm hiên tại và số ngày cần trừ
Đầu ra là ngày tháng năm sau khi được trừ */
CDate CDate::operator-(int d) {
    return CDate(Ngay - d, Thang, Nam);
}

/* Toán tử ++
Đầu vào ngày tháng năm hiên tại
Đầu ra là ngày tháng năm sau khi được cộng thêm 1 ngày*/
CDate& CDate::operator++() {
    Ngay++;
    ChuanHoa();
    return *this;
}
CDate CDate::operator++(int) {
    CDate temp = *this;
    ++(*this);
    return temp;
}

/* Toán tử --
Đầu vào ngày tháng năm hiên tại
Đầu ra là ngày tháng năm sau khi trừ đi 1 ngày*/
CDate& CDate::operator--() {
    Ngay--;
    ChuanHoa();
    return *this;
}
CDate CDate::operator--(int) {
    CDate temp = *this;
    --(*this);
    return temp;
}

//Toán tử trừ tính khoảng cách ngày giữa 2 thời điểm
long CDate::operator-(const CDate& b) {
    return this->TongSoNgay() - b.TongSoNgay();
}
