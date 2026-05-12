#include "DaThuc.h"
#include <cmath>
#include <algorithm>
#include <limits>

// Khởi tạo đa thức bậc n
DaThuc::DaThuc(int n) {
    bac = n;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) heSo[i] = 0;
}

// Copy Constructor (Deep copy) - Quan trọng để tránh lỗi vùng nhớ khi truyền tham số
DaThuc::DaThuc(const DaThuc& other) {
    bac = other.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; ++i) {
        heSo[i] = other.heSo[i];
    }
}

// Destructor
DaThuc::~DaThuc() {
    delete[] heSo;
}

// Toán tử gán
DaThuc& DaThuc::operator=(const DaThuc& other) {
    if (this != &other) {
        delete[] heSo; // Giải phóng bộ nhớ cũ
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; ++i) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}

// Toán tử nhập
std::istream& operator>>(std::istream& is, DaThuc& dt) {
    while (true){
        std::cout << "Nhap bac cua da thuc: ";
        is >> dt.bac;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Loi! Chi duoc nhap so nguyen!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }
    delete[] dt.heSo; // Xóa dữ liệu cũ nếu có
    dt.heSo = new double[dt.bac + 1];
    for (int i = dt.bac; i >= 0; --i) {
        while (true){
            std::cout << "Nhap he so bac " << i << ": ";
            is >> dt.heSo[i];
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Loi! Chi duoc nhap so thuc!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }
    }
    return is;
}

// Toán tử xuất
std::ostream& operator<<(std::ostream& os, const DaThuc& dt) {
    bool first = true;
    for (int i = dt.bac; i >= 0; --i) {
        if (dt.heSo[i] == 0) continue;

        if (!first && dt.heSo[i] > 0) os << " + ";
        if (dt.heSo[i] < 0) os << " - ";

        double val = std::abs(dt.heSo[i]);
        if (val != 1 || i == 0) os << val;

        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;

        first = false;
    }
    if (first) os << "0";
    return os;
}

/* Toán tử cộng 2 đa thức
Đầu vào hệ số và bậc của 2 đa thức
Đầu ra là tổng 2 đa thức */
DaThuc DaThuc::operator+(const DaThuc& other) const {
    int maxBac = std::max(bac, other.bac);
    DaThuc ketQua(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= other.bac) ? other.heSo[i] : 0;
        ketQua.heSo[i] = a + b;
    }
    return ketQua;
}

/* Toán tử trừ 2 đa thức
Đầu vào hệ số và bậc của 2 đa thức
Đầu ra là hiệu 2 đa thức */
DaThuc DaThuc::operator-(const DaThuc& other) const {
    int maxBac = std::max(bac, other.bac);
    DaThuc ketQua(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= other.bac) ? other.heSo[i] : 0;
        ketQua.heSo[i] = a - b;
    }
    return ketQua;
}

/* Toán tử nhân 2 đa thức
Đầu vào hệ số và bậc của 2 đa thức
Đầu ra là tích 2 đa thức */
DaThuc DaThuc::operator*(const DaThuc& other) const {
    DaThuc ketQua(bac + other.bac);
    for (int i = 0; i <= bac; ++i) {
        for (int j = 0; j <= other.bac; ++j) {
            ketQua.heSo[i + j] += heSo[i] * other.heSo[j];
        }
    }
    return ketQua;
}

// Hàm tính giá trị đa thức khi biết x
double DaThuc::tinhGiaTri(double x) const {
    double res = heSo[bac];
    for (int i = bac - 1; i >= 0; --i) {
        res = res * x + heSo[i];
    }
    return res;
}
