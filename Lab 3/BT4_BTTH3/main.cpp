#include <iostream>
#include <limits>
#include "cArray.h"

using namespace std;

int main() {
    cArray A;
    int n;

    // Nhập kích thước mảng
    while (true){
        cout << "Nhap so luong phan tu n (n > 0): ";
        cin >> n;
        //Kiểm tra có kí tự trong input
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        // Kiểm tra input có phải là số nguyên
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        if (n <= 0){
            cout << "So luong phan tu khong hop le!\n";
            continue;
        }
        break;
    }

    // Tạo mảng
    A.generateRandom(n);

    cout << "------------------------\n";
    // Xuất mảng
    cout << "Mang ngau nhien duoc tao: \n";
    A.Xuat();

    // Đếm số lần giá trị x được nhập xuát hiện
    int x;
    cout << "\nNhap gia tri x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << A.countOccurrence(x) << endl;

    cout << "------------------------\n";

    // Kiểm tra mảng có tăng dần
    if (A.isAscending())
        cout << "Mang dang o trang thai tang dan.\n";
    else
        cout << "Mang khong o trang thai tang dan.\n";

    cout << "------------------------\n";

    // Số lẻ nhỏ nhất trong mảng
    int minOdd = A.findMinOdd();
    if (minOdd != -1)
        cout << "Phan tu le nho nhat: " << minOdd << endl;
    else
        cout << "Khong co phan tu le trong mang.\n";

    cout << "------------------------\n";

    // Số nguyên tố lớn nhất trong mảng
    int maxP = A.findMaxPrime();
    if (maxP != -1)
        cout << "So nguyen to lon nhat: " << maxP << endl;
    else
        cout << "Khong co so nguyen to trong mang.\n";

    cout << "------------------------\n";

    //Sắp xếp mảng
    cout << "\nMang sau khi sap xep tang dan: \n";
    A.QuickSortAscending(0, n-1);
    A.Xuat();

    cout << "\nMang sau khi sap xep giam dan: \n";
    A.QuickSortDecending(0, n-1);
    A.Xuat();

    return 0;
}
