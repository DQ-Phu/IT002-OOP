#ifndef CONGTY_H
#define CONGTY_H
#include "NhanVien.h"
#include "NVVP.h"
#include "NVSX.h"
#include <vector>

class CongTy {
private:
    vector<NhanVien*> ds;
public:
    void NhapDS();
    void XuatDS();
    double TongLuong();
    void TimNVSXLuongThapNhat();
    void TimNVVPTuoiCaoNhat();
    ~CongTy();
};
#endif
