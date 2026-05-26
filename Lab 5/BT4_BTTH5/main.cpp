#include "CongTy.h"

int main() {
    CongTy cty;
    cty.NhapDS();

    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    cty.XuatDS();

    cty.XuatLuongThapHonTrungBinh();

    cout << "\n--- THONG KE ---\n";
    cty.TimNhanVienLuongMax();
    cty.TimNhanVienLuongMin();
    cty.TimLTVMaxLuong();
    cty.TimKCVMinLuong();

    return 0;
}
