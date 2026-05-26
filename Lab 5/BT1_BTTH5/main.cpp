#include "CongTy.h"

int main() {
    CongTy cty;
    cty.NhapDS();

    cout << "\n--- DANH SACH NHAN VIEN ---\n";
    cty.XuatDS();

    cout << "\n--- THONG KE TAI CHINH ---\n";
    cout << "Tong luong cong ty phai tra: " << (long long)cty.TongLuong() << " VND" << endl;

    cout << "\n--- THONG TIN THEM ---\n";
    cty.TimNVSXLuongThapNhat();
    cty.TimNVVPTuoiCaoNhat();

    return 0;
}
