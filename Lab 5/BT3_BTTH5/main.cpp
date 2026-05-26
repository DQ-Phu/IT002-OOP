#include "DaiHoc.h"

int main() {
    DaiHoc uit;
    uit.NhapDS();

    cout << "\n--- DANH SACH SINH VIEN ---\n";
    uit.XuatDS();

    uit.XuatDuDieuKienTN();
    uit.XuatKhongDuDieuKienTN();

    cout << "\n--- SINH VIEN UU TU ---\n";
    uit.TimDHMaxDTB();
    uit.TimCDMaxDTB();

    uit.ThongKeTruotTheoLoai();

    return 0;
}
