#include "CongTy.h"

int main() {
    CongTy xyz;

    // Đọc file XYZ.INP
    xyz.nhapTuFile("XYZ.INP");

    // Tính toán vào output ra file XYZ.OUT
    xyz.xuatRaFile("XYZ.OUT");

    return 0;
}
