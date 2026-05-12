#include <iostream>
#include <limits>
#include "CVector.h"

using namespace std;

int main() {
    CVector v1, v2;

    cout << "Nhap vector v1:\n";
    cin >> v1;
    cout << "Nhap vector v2:\n";
    cin >> v2;

    cout << "\nv1 = " << v1;
    cout << "\nv2 = " << v2;

    if (v1.getDimension() == v2.getDimension()) {
        cout << "\nv1 + v2 = " << (v1 + v2);
        cout << "\nv1 - v2 = " << (v1 - v2);
        cout << "\nTich vo huong v1 * v2 = " << (v1 * v2);
    } else {
        cout << "\nHai vector khong cung so chieu!";
    }

    cout << "\n\nDo dai v1 = " << v1.length() << endl;
    cout << "Do dai v2 = " << v2.length() << endl;

    double k;
    while (true){
        cout << "\n\nNhap so thuc k de tinh vi * k: ";
        cin >> k;
        if (cin.fail() || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so thuc!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    cout << "v1 * " << k << " = " << (v1 * k);
    cout << "v2 * " << k << " = " << (v2 * k);

    return 0;
}
