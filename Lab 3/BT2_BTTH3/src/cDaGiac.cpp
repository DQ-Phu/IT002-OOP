#include "cDaGiac.h"
#include "cDiem.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Constructor
cDaGiac::cDaGiac() {
    n = 0;
    dsDiem = nullptr;
}

// Constructor sao chép lớp
 cDaGiac::cDaGiac(const cDaGiac &temp) {
    this->n = temp.n;
    this->dsDiem = new cDiem[this->n];
    for (int i = 0; i < n; i++) {
        this->dsDiem[i] = temp.dsDiem[i];
    }
}

// Destructor
cDaGiac::~cDaGiac() {
    delete[] dsDiem;
}

/* Hàm nhập
Đàu vào: Input số đỉnh rồi input tọa độ các đỉnh qua .Nhap()
Đầu ra: Các đỉnh đã có tọa độ và hợp lệ
Nếu Input sai, sẽ phải nhập lại*/
void cDaGiac::Nhap() {
    while(true){
        cout << "Nhap so dinh cua da giac (n > 2): ";
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

        if (n <= 2) {
            cout << "So dinh khong hop le. Vui long nhap lai!\n";
            continue;
        }
        break;
    }


    // Xóa dữ liệu khi nhập sai
    if (dsDiem != nullptr) delete[] dsDiem;

    dsDiem = new cDiem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap dinh " << i + 1 << ":";
        dsDiem[i].Nhap();
    }
}

/* Hàm xuất
Đàu vào: Các đỉnh đa giác
Đầu ra: Tọa độ từng đỉnh qua .Xuat()*/
void cDaGiac::Xuat() {
    cout << "Da giac " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        dsDiem[i].Xuat();
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

/* Hàm kiểm tra loại đa giác
Đàu vào: Các đỉnh đa giác
Đầu ra: Loại đa giác tùy vào điều kiện thỏa mãn */
void cDaGiac::KiemTraLoai() {
    if (n == 3) cout << "Day la da giac." << endl;
    else if (n == 4) cout << "Day la tu giac." << endl;
    else cout << "Day la da giac " << n << " canh." << endl;
}

/* Hàm tính chu vi
Đàu vào: Các đỉnh đa giác
Đầu ra: Chu vi đa giác */
double cDaGiac::ChuVi() {
    double chuVi = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        chuVi += dsDiem[i].KhoangCach(dsDiem[next]);
    }
    return chuVi;
}

/* Hàm tính diện tích
Đàu vào: Các đỉnh đa giác
Đầu ra: Diện tích đa giác */
double cDaGiac::DienTich() {
    double dienTich = 0;
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        dienTich += (dsDiem[i].x * dsDiem[next].y);
        dienTich -= (dsDiem[next].x * dsDiem[i].y);
    }
    return fabs(dienTich) / 2.0;
}

/* Hàm tính tịnh tiến
Đàu vào: Các đỉnh đa giác, tọa độ vector tịnh tiến
Đầu ra: Đỉnh đa giác sau khi tịnh tiến */
cDaGiac cDaGiac::TinhTien(double dx, double dy) {
    cDaGiac ketQua(*this); // Tạo một bản sao từ đa giác hiện tại
    for (int i = 0; i < n; i++) {
        // Cập nhật trên bản sao, không phải trên đối tượng gốc
        ketQua.dsDiem[i] = ketQua.dsDiem[i].TinhTien(dx, dy);
    }
    return ketQua; // Trả về bản sao đã di chuyển
}

/* Hàm thu nhỏ
Đàu vào: Các đỉnh đa giác, tỉ số thu nhỏ
Đầu ra: Điểm đa giác sau khi thu nhỏ */
cDaGiac cDaGiac::ThuNho(double k) {
    cDaGiac ketQua(*this);
    if (k != 0) {
        for (int i = 0; i < n; i++) {
            ketQua.dsDiem[i] = ketQua.dsDiem[i].ThuNho(k);
        }
    }
    return ketQua;
}

/* Hàm phóng to
Đàu vào: Các đỉnh đa giác, tỉ số phóng to
Đầu ra: Điểm đa giác sau khi phóng to */
cDaGiac cDaGiac::PhongTo(double k) {
    cDaGiac ketQua(*this);
    for (int i = 0; i < n; i++) {
        ketQua.dsDiem[i] = ketQua.dsDiem[i].PhongTo(k);
    }
    return ketQua;
}

/* Hàm quay
Đàu vào: Các đỉnh đa giác, góc quay theo đơn vị độ
Đầu ra: Điểm đa giác sau khi quay */
cDaGiac cDaGiac::Quay(double goc) {
    cDaGiac ketQua(*this);
    for (int i = 0; i < n; i++) {
        ketQua.dsDiem[i] = ketQua.dsDiem[i].Quay(goc);
    }
    return ketQua;
}
