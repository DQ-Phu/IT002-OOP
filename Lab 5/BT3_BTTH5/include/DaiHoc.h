#ifndef DAIHOC_H
#define DAIHOC_H

#include "SinhVienCD.h"
#include "SinhVienDH.h"
#include <vector>

class DaiHoc {
private:
    vector<SinhVien*> ds;
public:
    void NhapDS();
    void XuatDS();
    void XuatDuDieuKienTN();
    void XuatKhongDuDieuKienTN();
    void TimDHMaxDTB();
    void TimCDMaxDTB();
    void ThongKeTruotTheoLoai();
    ~DaiHoc();
};
#endif
