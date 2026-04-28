#include <iostream>
#include <limits>
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
    while (1){
        cout << "\nNhap x (so thuc): ";
        cin >> x;
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra input có phải là số thực
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        break;
    }
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
