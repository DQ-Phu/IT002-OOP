#ifndef CDIEM_H
#define CDIEM_H


class cDiem
{
    private:
        double x;
        double y;
    public:
        cDiem(double x = 0, double y = 0);
        void Nhap();
        void Xuat();

        double KhoangCach(cDiem b);
        cDiem TinhTien(double dx, double dy);
        cDiem PhongTo(double k);
        cDiem ThuNho(double k);
        cDiem Quay(double goc);
};

#endif // CDIEM_H
