#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <vector>

class DaThuc {
private:
    int bac;
    double* heSo;
public:
    DaThuc(int n = 0);               // Khởi tạo đa thức bậc n
    DaThuc(const DaThuc& other);     // Copy constructor (Deep copy)
    ~DaThuc();                       // Destructor

    DaThuc& operator=(const DaThuc& other);

    friend std::istream& operator>>(std::istream& is, DaThuc& dt);
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& dt);

    DaThuc operator+(const DaThuc& other) const;
    DaThuc operator-(const DaThuc& other) const;
    DaThuc operator*(const DaThuc& other) const;

    double tinhGiaTri(double x) const;
};

#endif
