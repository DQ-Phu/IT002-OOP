#ifndef CDATHUC_H
#define CDATHUC_H
#include <iostream>

class cDaThuc {
private:
    int n;
    double* a;

public:
    cDaThuc();
    cDaThuc(int bac);
    cDaThuc(const cDaThuc& other);
    ~cDaThuc();

    cDaThuc& operator=(const cDaThuc& other);

    void Nhap();
    void Xuat() const;
    double TinhGiaTri(double x) const;

    cDaThuc operator+(const cDaThuc& other) const;
    cDaThuc operator-(const cDaThuc& other) const;
};

#endif // CDATHUC_H
