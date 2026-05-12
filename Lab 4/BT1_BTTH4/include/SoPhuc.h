#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>

class SoPhuc {
private:
    double iThuc;
    double iAo;

public:
    SoPhuc(double r = 0, double i = 0);

    friend std::ostream& operator<<(std::ostream& os, const SoPhuc& sp);
    friend std::istream& operator>>(std::istream& is, SoPhuc& sp);

    SoPhuc operator+(const SoPhuc& b) const;
    SoPhuc operator-(const SoPhuc& b) const;
    SoPhuc operator*(const SoPhuc& b) const;
    SoPhuc operator/(const SoPhuc& b) const;

    bool operator==(const SoPhuc& b) const;
    bool operator!=(const SoPhuc& b) const;
};
#endif // SOPHUC_H
