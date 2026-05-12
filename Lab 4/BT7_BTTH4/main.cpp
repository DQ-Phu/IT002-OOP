#include <iostream>
#include <limits>
#include "CMatrix.h"

using namespace std;

int main() {
    CMatrix A, V, B;

    cout << "--- NHAP MA TRAN A ---\n";
    cin >> A;

    cout << "\n--- NHAP VECTOR V (n * 1) ---\n";
    while (true) {
        cin >> V;
        if (V.isColumnVector() && A.getCols() == V.getRows()) {
            break;
        } else if (A.getCols() != V.getRows()){
            cout << "\nKich thuoc A (" << A.getCols() << " hang) va V (" << V.getRows() << " cot) khong khop! Nhap lai.\n";
        } else {
            cout << "Loi! Day khong phai la Vector cot (So cot phai bang 1). Nhap lai!\n";
        }
    }

    // Matrix * Vector
    cout << "\nKet qua A * V (Vector):\n" << (A * V);

    cout << "\n--- NHAP MA TRAN B DE NHAN (A * B) ---\n";
    while (true) {
        cin >> B;
        if (A.getCols() == B.getRows()) {
            break;
        } else {
            cout << "LOI: So hang cua B phai bang " << A.getCols() << ". Nhap lai!\n";
        }
    }

    cout << "\nKet qua A * B:\n" << (A * B);

    return 0;
}
