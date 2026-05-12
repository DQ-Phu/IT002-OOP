#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>

class PhanSo {
private:
    long long tu, mau;
    void rutGon();
public:
    /* Constructor
    PhanSo() -> 0/1
    PhanSo(5) -> 5/1 (Số nguyên như một phân số đặc biệt)
    PhanSo(1, 2) -> 1/2 */
    PhanSo(long long t = 0, long long m = 1);

    friend std::ostream& operator<<(std::ostream& os, const PhanSo& ps);
    friend std::istream& operator>>(std::istream& is, PhanSo& ps);

    PhanSo operator+(const PhanSo& b) const;
    PhanSo operator-(const PhanSo& b) const;
    PhanSo operator*(const PhanSo& b) const;
    PhanSo operator/(const PhanSo& b) const;

    bool operator==(const PhanSo& b) const;
    bool operator>(const PhanSo& b) const;
    bool operator<(const PhanSo& b) const;
};

#endif
