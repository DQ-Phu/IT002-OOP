#include <iostream>
#include <limits>
#include "DaThuc.h"

using namespace std;

int main() {
    DaThuc p1, p2;

    cout << "Nhap da thuc P1:\n";
    cin >> p1;
    cout << "Nhap da thuc P2:\n";
    cin >> p2;

    cout << "\nP1 = " << p1;
    cout << "\nP2 = " << p2;

    DaThuc tong = p1 + p2;
    cout << "\nP1 + P2 = " << tong;

    DaThuc tich = p1 * p2;
    cout << "\nP1 * P2 = " << tich;

    double x;
    cout << "\n\n";
    while (true){
        cout << "Nhap x de tinh gia tri cua 2 da thuc: ";
        cin >> x;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so thuc!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    cout << "P1(" << x << ") = " << p1.tinhGiaTri(x) << endl;
    cout << "P2(" << x << ") = " << p2.tinhGiaTri(x) << endl;

    return 0;
}
