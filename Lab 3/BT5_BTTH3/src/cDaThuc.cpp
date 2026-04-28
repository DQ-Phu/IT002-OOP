#include "cDaThuc.h"
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

// Khởi tạo đa thức bậc 0
cDaThuc::cDaThuc() {
    n = 0;
    a = new double[1];
    a[0] = 0;
}

// Khởi tạo đa thức với bậc cụ thể
cDaThuc::cDaThuc(int bac) {
    n = bac;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) a[i] = 0;
}

// Copy Constructor
cDaThuc::cDaThuc(const cDaThuc& other) {
    n = other.n;
    a = new double[n + 1];
    for (int i = 0; i <= n; i++) a[i] = other.a[i];
}

// Destructor
cDaThuc::~cDaThuc() {
    delete[] a;
}

/* Toán tử gán
Đầu vào: 1 đối tượng được gán vào và đối tượng truyền dư liệu
Đầu ra: Đối tượng được gán có dữ liệu cúa đối tượng truyền */
cDaThuc& cDaThuc::operator=(const cDaThuc& other) {
    if (this != &other) { //Kiểm tra 2 đối tượng có khác địa chỉ (tránh tự gán đối tượng vào chính nó).
        delete[] a;
        n = other.n;
        a = new double[n + 1];
        for (int i = 0; i <= n; i++) a[i] = other.a[i];
    }
    return *this;
}

void cDaThuc::Nhap() {
    while (1){
        cout << "Nhap bac cua da thuc (so nguyen): ";
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
        break;
    }
    delete[] a;
    a = new double[n + 1]; //Tạo mảng
    for (int i = n; i >= 0; i--) {
        while (1){
            cout << "Nhap he so cua x^" << i << " (so thuc): ";
            cin >> a[i];
            //Kiểm tra có kí tự trong input
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
    }
}

/* Hàm xuất
Đàu vào: Kích thước mảng và mảng
Đầu ra: Xuất mảng theo kiểu một đa thức*/
void cDaThuc::Xuat() const {
    bool first = true; // Số đầu tiên
    for (int i = n; i >= 0; i--) {
        //Nếu hệ số a = 0 thì bỏ qua vì 0*x^n = 0
        if (a[i] == 0) continue;

        //Xác định dấu và xuất dấu
        if (!first && a[i] > 0) cout << " + ";
        if (a[i] < 0) cout << " - ";
        else if (first && a[i] < 0) cout << "-";

        /* Xuất hệ số, vì đã xuất nên xuất giá trị tuyệt đối
        Nếu hệ số = 1 hoặc = 0 thì không xuất*/
        double val = abs(a[i]);
        if (val != 1 || i == 0) cout << val;

        /*Kiểm tra bậc để quyết định việc xuất x và số mũ
        Vì ax^0 = a và ax^1 = ax */
        if (i > 0) cout << "x";
        if (i > 1) cout << "^" << i;

        first = false;
    }
    //Nếu đa thức = 0
    if (first) cout << "0";
    cout << endl;
}

/*Hàm tính giá trị
Đầu vào: Kích thước mảng, mảng của 2 đa thức và giá trị x
Đầu ra: Giá trị của đa thức khi thay x vào*/
double cDaThuc::TinhGiaTri(double x) const {
    double result = 0;
    for (int i = 0; i <= n; i++) {
        result += a[i] * pow(x, i);
    }
    return result;
}

/*Toán tử cộng
Đầu vào: Kích thước mảng và mảng của 2 đa thức
Đầu ra: Tổng 2 đa thức*/
cDaThuc cDaThuc::operator+(const cDaThuc& other) const {
    int maxBac = max(this->n, other.n); //Tìm bậc lớn nhất giữa 2 đa thức
    cDaThuc result(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double h1 = (i <= this->n) ? this->a[i] : 0; //Kiểm tra bậc đa thức với bậc đang xét
        double h2 = (i <= other.n) ? other.a[i] : 0; //Nếu bậc đang xét lớn hơn thì = 0, ngược lại thì bằng hệ số đa thức
        result.a[i] = h1 + h2;
    }
    return result;
}

/*Toán tử trừ
Đầu vào: Kích thước mảng và mảng của 2 đa thức
Đầu ra: Hiệu 2 đa thức*/
cDaThuc cDaThuc::operator-(const cDaThuc& other) const {
    int maxBac = max(this->n, other.n);
    cDaThuc result(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double h1 = (i <= this->n) ? this->a[i] : 0; //Kiểm tra bậc đa thức với bậc đang xét
        double h2 = (i <= other.n) ? other.a[i] : 0; //Nếu bậc đang xét lớn hơn thì = 0, ngược lại thì bằng hệ số đa thức
        result.a[i] = h1 - h2;
    }
    return result;
}
