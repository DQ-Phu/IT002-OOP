#ifndef CONGTY_H
#define CONGTY_H

#include <vector>
#include "KhachHang.h"
#include "LoaiA.h"
#include "LoaiB.h"
#include "LoaiC.h"

class CongTy {
private:
    vector<KhachHang*> danhSach;
    int x, y, z;

public:
    void nhapTuFile(string filename);
    void xuatRaFile(string filename);
    double tinhTongDoanhThu();
    ~CongTy();
};

#endif
