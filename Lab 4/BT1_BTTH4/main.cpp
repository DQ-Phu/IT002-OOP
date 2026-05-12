#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main() {
    SoPhuc a;
    SoPhuc b;

    cout << "--- Nhap so phuc A ---" << endl;
    cin >> a;

    cout << "--- Nhap so phuc B ---" << endl;
    cin >> b;

    cout << "\nHai so phuc da nhap la:" << endl;;
    cout << "So Phuc A: " << a << endl;
    cout << "So Phuc B: " << b << endl;

    cout << "\n--- Tinh toan ---" << endl;
    cout << "(" << a << ") + (" << b << ") = " << a + b << endl;
    cout << "(" << a << ") - (" << b << ") = " << a - b << endl;
    cout << "(" << a << ") * (" << b << ") = " << a * b << endl;
    cout << "(" << a << ") / (" << b << ") = " << a / b << endl;

    cout << "\nSo sanh: ";
    if (a == b) cout << a << " bang " << b << endl;
    if (a != b) cout << a << " khac " << b << endl;

    return 0;
}
