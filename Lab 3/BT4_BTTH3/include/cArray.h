#ifndef CARRAY_H
#define CARRAY_H

class cArray {
private:
    int* arr;
    int size;

public:
    cArray();
    ~cArray();

    void Nhap();
    void generateRandom(int n);
    void Xuat() const;

    int countOccurrence(int x) const;
    bool isAscending() const;
    int findMinOdd() const;
    int findMaxPrime() const;
    void QuickSortAscending(int l, int r);
    void QuickSortDecending(int l, int r);
};

#endif // CARRAY_H
