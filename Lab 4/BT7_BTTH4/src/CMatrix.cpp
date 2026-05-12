#include "CMatrix.h"
#include <limits>

using namespace std;

CMatrix::CMatrix(int r, int c) : rows(r), cols(c) {
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) data[i][j] = 0;
        }
    } else data = nullptr;
}

CMatrix::CMatrix(const CMatrix& other) : rows(other.rows), cols(other.cols) {
    if (rows > 0 && cols > 0) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) data[i][j] = other.data[i][j];
        }
    } else data = nullptr;
}

CMatrix::~CMatrix() {
    if (data) {
        for (int i = 0; i < rows; ++i) delete[] data[i];
        delete[] data;
    }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        if (data) {
            for (int i = 0; i < rows; ++i) delete[] data[i];
            delete[] data;
        }
        rows = other.rows; cols = other.cols;
        if (rows > 0 && cols > 0) {
            data = new double*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new double[cols];
                for (int j = 0; j < cols; ++j) data[i][j] = other.data[i][j];
            }
        } else data = nullptr;
    }
    return *this;
}

// Toán tử nhập
istream& operator>>(istream& is, CMatrix& m) {
    int r, c;
    while (true) {
        cout << "Nhap so hang va so cot: ";
        if (!(is >> r >> c) || cin.peek() != '\n') {
            cout << "Loi! Chi duoc nhap so nguyen!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (r <= 0 || c <= 0) {
            cout << "Kich thuoc phai lon hon 0!\n";
            continue;
        }
        break;
    }

    if (m.data) {
        for (int i = 0; i < m.rows; ++i) delete[] m.data[i];
        delete[] m.data;
    }

    m.rows = r; m.cols = c;
    m.data = new double*[m.rows];
    for (int i = 0; i < m.rows; ++i) {
        m.data[i] = new double[m.cols];
        for (int j = 0; j < m.cols; ++j) {
            while (true) {
                cout << "  Phan tu [" << i << "][" << j << "] = ";
                if (!(is >> m.data[i][j]) || cin.peek() != '\n') {
                    cout << "  Loi! Phai nhap so thuc!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                break;
            }
        }
    }
    return is;
}

//Toán tử xuất
ostream& operator<<(ostream& os, const CMatrix& m) {
    if (!m.data) return os << "[]" << endl;
    for (int i = 0; i < m.rows; ++i) {
        os << "| ";
        for (int j = 0; j < m.cols; ++j) os << m.data[i][j] << "\t";
        os << "|" << endl;
    }
    return os;
}

//Lấy dữ liệu từ pivate ra ngoài
double* CMatrix::operator[](int index) { return data[index]; }
const double* CMatrix::operator[](int index) const { return data[index]; }


/* Toán tử nhân 2 ma trận
Đầu vào: Thông số 2 ma trận
Đầu ra là tích 2  trận */
CMatrix CMatrix::operator*(const CMatrix& other) const {
    if (this->cols != other.rows) return CMatrix(0, 0);
    CMatrix res(this->rows, other.cols);
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < this->cols; ++k) {
                res.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return res;
}

