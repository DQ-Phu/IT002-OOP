#ifndef CDATE_H
#define CDATE_H

#include <iostream>

class CDate {
private:
    int Ngay, Thang, Nam;
    void ChuanHoa();

public:
    // Constructor với giá trị mặc định
    CDate(int d = 1, int m = 1, int y = 2024);

    friend std::istream& operator>>(std::istream& is, CDate& d);
    friend std::ostream& operator<<(std::ostream& os, const CDate& d);

    long TongSoNgay() const;

    CDate operator+(int d);
    CDate operator-(int d);

    // Toán tử ++
    CDate& operator++();    // Tiền tố
    CDate operator++(int);  // Hậu tố

    // Toán tử --
    CDate& operator--();    // Tiền tố
    CDate operator--(int);  // Hậu tố

    long operator-(const CDate& b);
};

#endif
