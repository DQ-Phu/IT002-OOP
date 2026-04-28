#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main() {
    cDaThuc dt1, dt2, dtTong, dtHieu;

    cout << "--- Da thuc 1 ---\n";
    dt1.Nhap();

    cout << "\n--- Da thuc 2 ---\n";
    dt2.Nhap();

    cout << "\n--------------------------";
    cout << "\nDa thuc 1: "; dt1.Xuat();
    cout << "Da thuc 2: "; dt2.Xuat();

    cout << "--------------------------";
    double x;
    cout << "\nNhap x (so thuc): ";
    cin >> x;
    cout << "Gia tri cua da thuc 1 khi x = " << x << " la: " << dt1.TinhGiaTri(x) << endl;
    cout << "Gia tri cua da thuc 2 khi x = " << x << " la: " << dt2.TinhGiaTri(x) << endl;

    cout << "--------------------------";
    dtTong = dt1 + dt2;
    cout << "\nTong hai da thuc: ";
    dtTong.Xuat();

    dtHieu = dt1 - dt2;
    cout << "Hieu hai da thuc (dt1 - dt2): ";

    dtHieu.Xuat();

    return 0;
}
