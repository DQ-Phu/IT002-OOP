#include "CVector.h"
#include <cmath>

// Constructor
CVector::CVector(int dimensions) : n(dimensions) {
    if (n > 0) {
        data = new double[n];
        for (int i = 0; i < n; ++i) data[i] = 0;
    } else {
        data = nullptr;
    }
}

// Copy Constructor
CVector::CVector(const CVector& b) : n(b.n) {
    if (n > 0) {
        data = new double[n];
        for (int i = 0; i < n; ++i) data[i] = b.data[i];
    } else {
        data = nullptr;
    }
}

// Destructor
CVector::~CVector() {
    delete[] data;
}

// Toán tử gán
CVector& CVector::operator=(const CVector& b) {
    if (this != &b) {
        delete[] data; // Giải phóng bộ nhớ cũ
        n = b.n;
        if (n > 0) {
            data = new double[n];
            for (int i = 0; i < n; ++i) data[i] = b.data[i];
        } else {
            data = nullptr;
        }
    }
    return *this;
}

// Nhập vector
std::istream& operator>>(std::istream& is, CVector& v) {
    while (true){
        std::cout << "Nhap so chieu: ";
        is >> v.n;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Loi! Chi duoc nhap so nguyen!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        } else if (v.n < 0){
            std::cout << "Loi! So chieu phai lon hon 0!";
            continue;
        }
        break;
    }
    delete[] v.data;
    v.data = new double[v.n];
    for (int i = 0; i < v.n; ++i) {
        while (true){
            std::cout << "  Phan tu [" << i << "]: ";
            is >> v.data[i];
            if (std::cin.fail() || std::cin.peek() != '\n') {
                std::cout << "Loi! Chi duoc nhap so nguyen!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }
    }
    return is;
}

// Xuất vector
std::ostream& operator<<(std::ostream& os, const CVector& v) {
    os << "(";
    for (int i = 0; i < v.n; ++i) {
        os << v.data[i] << (i == v.n - 1 ? "" : ", ");
    }
    os << ")";
    return os;
}

/* Toán tử cộng 2 vector
Đầu vào 2 vector
Đầu ra là tổng 2 vector */
CVector CVector::operator+(const CVector& b) const {
    if (n != b.n) return CVector(0); // Lỗi kích thước
    CVector kq(n);
    for (int i = 0; i < n; ++i) kq.data[i] = data[i] + b.data[i];
    return kq;
}

/* Toán tử trừ 2 vector
Đầu vào 2 vector
Đầu ra là hiệu 2 vector */
CVector CVector::operator-(const CVector& b) const {
    if (n != b.n) return CVector(0);
    CVector kq(n);
    for (int i = 0; i < n; ++i) kq.data[i] = data[i] - b.data[i];
    return kq;
}

// Hàm nhân với số thực
// Đầu vào: Vector và một số thực
// Đầu ra: Vector sau khi nhân vơi số thực
CVector CVector::operator*(double k) const {
    CVector kq(n);
    for (int i = 0; i < n; ++i) kq.data[i] = data[i] * k;
    return kq;
}

/* Toán tử nhân 2 vector (tích vô hướng 2 vector)
Đầu vào 2 vector
Đầu ra là tích 2 vector */
double CVector::operator*(const CVector& b) const {
    if (n != b.n) return 0;
    double kq = 0;
    for (int i = 0; i < n; ++i) kq += data[i] * b.data[i];
    return kq;
}

// Truy cập phần tử
double& CVector::operator[](int index) { return data[index]; }
const double& CVector::operator[](int index) const { return data[index]; }

int CVector::getDimension() const { return n; }

// Hàm tính độ dài vector
double CVector::length() const {
    double sum = 0;
    for (int i = 0; i < n; ++i) sum += data[i] * data[i];
    return std::sqrt(sum);
}
