#ifndef CDIEM_H
#define CDIEM_H


class cDiem
{
public:
    double x, y;

    cDiem();
    cDiem(double x, double y);

    void Nhap();
    void Xuat();

    double KhoangCach(cDiem b);

    cDiem TinhTien(double dx, double dy);
    cDiem Quay(double goc);
    cDiem PhongTo(double k);
    cDiem ThuNho(double k);
};

#endif // CDIEM_H
