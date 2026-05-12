#ifndef CTIME_H
#define CTIME_H

#include <iostream>
#include <iomanip>

class CTime {
private:
    int gio, phut, giay;
    void ChuanHoa();

public:
    // Khởi tạo
    CTime(int h = 0, int m = 0, int s = 0);

    // Các phép toán nhập xuất (Đặt dưới constructor)
    friend std::istream& operator>>(std::istream& is, CTime& t);
    friend std::ostream& operator<<(std::ostream& os, const CTime& t);

    // Các phép toán cộng trừ
    CTime operator+(int s);
    CTime operator-(int s);

    // Phép toán ++
    CTime& operator++();    // Tiền tố
    CTime operator++(int);  // Hậu tố

    // Phép toán --
    CTime& operator--();    // Tiền tố
    CTime operator--(int);  // Hậu tố
};

#endif
