#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() {
    PhanSo A;
    PhanSo B;

    cout << "--- Nhap phan so A ---" << endl;
    cin >> A;
    cout << "--- Nhap phan so B ---" << endl;
    cin >> B;

    cout << "\nHai phan so da nhap la:" << endl;;
    cout << "Phan so A: " << A << endl;
    cout << "Phan so B: " << B << endl;

    cout << "\n--- Tinh toan ---" << endl;
    cout << A << " + " << B << " = " << A + B << endl;
    cout << A << " - " << B << " = " << A - B << endl;
    cout << A << " * " << B << " = " << A * B << endl;
    cout << A << " / " << B << " = " << A / B << endl;

    cout << "\nSo sanh: ";
    if (A == B) cout << A << " bang " << B << endl;
    if (A > B)  cout << A << " lon hon " << B << endl;
    if (A < B)  cout << A << " nho hon " << B << endl;

    return 0;
}
