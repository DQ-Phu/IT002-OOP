#include <iostream>
#include <cTamGiac.h>
#include <limits>
using namespace std;

int main() {
    cTamGiac tg;

    tg.Nhap();

    // Xuất  tọa độ, loại tam giác, chu vi, diện tích
    cout << "\nThong tin tam giac:\n";
    cout << "Toa do cac diem: ";
    tg.Xuat();

    cout << "\nDay la: ";
    tg.KiemTraLoai();

    cout << "\nChu vi: " << tg.ChuVi() << endl;
    cout << "Dien tich: " << tg.DienTich() << endl;
    cout << "------------------------\n";

    //Nhập vector tịnh tiến và xuất điểm tam giác sau khi tịnh tiến
    double a = 0, b = 0;
    while(true){
        cout << "Nhap vecto tinh tien v = (a, b): \n";

        cout << "a = "; cin >> a;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }

        cout << "b = "; cin >> b;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        //Nếu thỏa mãn thì break
        break;
    }
    cout << "\nTinh tien vecto (" << a << ", " << b << "):\n";
    cTamGiac TT = tg.TinhTien(a, b);
    TT.Xuat();
    cout << "------------------------\n";

    //Nhập tỉ số phóng to và xuất tam giác sau khi phóng to
    double k = 0;
    while(true){
        cout << "Nhap ti le phong to: ";

        cin >> k;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        //Nếu thỏa mãn thì break
        break;
    }
    cout << "\nPhong to " << k << " lan:\n";
    cTamGiac PT = tg.PhongTo(k);
    PT.Xuat();
    cout << "------------------------\n";


    //Nhập tỉ số thu nhỏ và xuất tam giác sau khi thu nhỏ
    while(true){
        cout << "Nhap ti le thu nho: ";

        cin >> k;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        if (k == 0) {
            cout << "Ti so thu nho phai khac 0!\n";
            continue;
        }
        //Nếu thỏa mãn thì break
        break;
    }
    cout << "\nThu nho " << k << " lan:\n";
    cTamGiac TN = tg.ThuNho(k);
    TN.Xuat();
    cout << "------------------------\n";

    //Nhập góc quay theo độ và xuất tam giác sau khi quay
    while(true){
        cout << "Nhap goc quay (don vi la do/degree): ";

        cin >> k;
        // Kiểm tra có kí tự trong input không
        if (cin.fail()) {
            cout << "Loi! Vui long nhap lai!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Loi! Vui long nhap lai!\n";
            continue;
        }
        //Nếu thỏa mãn thì break
        break;
    }
    cout << "\nQuay " << k << " do:\n";
    cTamGiac Q = tg.Quay(k);
    Q.Xuat();

    return 0;
}
