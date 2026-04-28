#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>

using namespace std;

// Constructor
cArray::cArray() : arr(nullptr), size(0) {}

// Destructor
cArray::~cArray() {
    delete[] arr;
}

/* Hàm tạo mảng ngẫu nhiên
Đàu vào: Kích thước mảng
Đầu ra: Một mảng ngẫu nhiên */
void cArray::generateRandom(int n) {
    if (arr != nullptr) delete[] arr;
    size = n;
    arr = new int[size];
    srand(static_cast<unsigned int>(time(0))); // Tạo seed random
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Ngẫu nhiên 0-99
    }
}

/* Hàm xuất
Đàu vào: Kích thước mảng và mảng
Đầu ra: Xuất mảng */
void cArray::Xuat() const {
    if (size == 0) {
        cout << "Mang trong!" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Hàm đếm số lần xuát hiện của một số
Đàu vào: Kích thước mảng, mảng và số cần xét
Đầu ra: Số lần xuất hiện của số đang xét */
int cArray::countOccurrence(int x) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) count++;
    }
    return count;
}

/* Hàm kiểm tra mảng có được sắp xếp tăng dần
Đàu vào: Kích thước mảng và mảng
Đầu ra: True nếu mảng tăng dần, false nếu không tăng dần */
bool cArray::isAscending() const {
    if (size <= 1) return true;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

/* Hàm tìm số lẻ lớn nhất
Đàu vào: Kích thước mảng và mảng
Đầu ra: số lẻ lớn nhất nếu tìm được, nếu không tìm thấy thì trả về -1 */
int cArray::findMinOdd() const {
    int minOdd = INT_MAX;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0 && arr[i] < minOdd) {
            minOdd = arr[i];
            found = true;
        }
    }
    return found ? minOdd : -1;
}

/* Hàm tìm số nguyên tố lớn nhất
Đàu vào: Kích thước mảng và mảng
Đầu ra: Số nguyên tố lớn nhất, nếu không tìm tháy thì trả về mặt định là -1 */
int cArray::findMaxPrime() const {
    int maxPrime = -1;
    for (int i = 0; i < size; i++) {
        int val = arr[i];
        bool check = true;
        if (val < 2) check = false;
        else {
            for (int j = 2; j * j <= val; j++) {
                if (val % j == 0) {
                    check = false;
                    break;
                }
            }
        }

        if (check && val > maxPrime) {
            maxPrime = val;
        }
    }
    return maxPrime;
}

/* Hàm sắp xếp tăng dần (Quick Sort)
Đàu vào: Mảng, index bên trái cùng và bên phải cùng trong khoảng xét
Đầu ra: Mảng được sắp xếp tăng dần */
void cArray::QuickSortAscending(int l, int r) {
    if (l >= r) return;
    int x = arr[(l+r)/2];
    int i = l, j = r;
    while(i < j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    QuickSortAscending(l, j);
    QuickSortAscending(i, r);
}

/* Hàm sắp xếp giảm dần (Quick Sort)
Đàu vào: Mảng, index bên trái cùng và bên phải cùng trong khoảng xét
Đầu ra: Mảng được sắp xếp giảm dần */
void cArray::QuickSortDecending(int l, int r) {
    if (l >= r) return;
    int x = arr[(l+r)/2];
    int i = l, j = r;
    while(i < j) {
        while (arr[i] > x) i++;
        while (arr[j] < x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    QuickSortDecending(l, j);
    QuickSortDecending(i, r);
}
