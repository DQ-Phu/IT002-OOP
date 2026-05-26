#ifndef BATDONGSAN_H
#define BATDONGSAN_H

#include "GiaoDichDat.h"
#include "GiaoDichNha.h"
#include "GiaoDichCanHo.h"
#include <vector>

class BatDongSan {
private:
    vector<GiaoDich*> ds;
public:
    void NhapDS();
    void XuatDS();
    void ThongKeSoLuong();
    void TrungBinhCanHo();
    void TimNhaPhoMax();
    void XuatThang12_2024();
    ~BatDongSan();
};
#endif
