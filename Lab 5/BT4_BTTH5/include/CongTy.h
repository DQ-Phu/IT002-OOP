#ifndef CONGTY_H
#define CONGTY_H
#include "LapTrinhVien.h"
#include "KiemChungVien.h"
#include <vector>

class CongTy {
private:
    vector<NhanVien*> ds;
public:
    void NhapDS();
    void XuatDS();
    void XuatLuongThapHonTrungBinh();
    void TimNhanVienLuongMax();
    void TimNhanVienLuongMin();
    void TimLTVMaxLuong();
    void TimKCVMinLuong();
    ~CongTy();
};
#endif
