#include "BatDongSan.h"

int main() {
    BatDongSan bds;
    bds.NhapDS();

    cout << "\n--- DANH SACH GIAO DICH ---\n";
    bds.XuatDS();

    bds.ThongKeSoLuong();
    bds.TrungBinhCanHo();
    bds.TimNhaPhoMax();
    bds.XuatThang12_2024();

    return 0;
}
