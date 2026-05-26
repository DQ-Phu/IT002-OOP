#include "CongTy.h"

void CongTy::NhapDS() {
    int n, loai;
    cout << "Nhap so luong nhan vien: "; cin >> n;
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "\nChon cong viec cua nhan vien(1: Lap trinh vien, 2: Kiem chung vien): ";
            if (!(cin >> loai) || (loai != 1 && loai != 2)) {
                cin.clear(); cin.ignore(1000, '\n');
            } else break;
        }
        NhanVien* nv = (loai == 1) ? (NhanVien*)new LapTrinhVien() : (NhanVien*)new KiemChungVien();
        nv->Nhap();
        nv->TinhLuong();
        ds.push_back(nv);
    }
}

void CongTy::XuatDS() {
    for (auto nv : ds) nv->Xuat();
}

void CongTy::XuatLuongThapHonTrungBinh() {
    if (ds.empty()) return;
    double tong = 0;
    for (auto nv : ds) tong += nv->getTongLuong();
    double tb = tong / ds.size();
    cout << "\n--- NV luong thap hon trung binh (" << (long long)tb << ") ---\n";
    for (auto nv : ds) if (nv->getTongLuong() < tb) nv->Xuat();
}

void CongTy::TimNhanVienLuongMax() {
    if (ds.empty()) return;
    NhanVien* res = ds[0];
    for (auto nv : ds) if (nv->getTongLuong() > res->getTongLuong()) res = nv;
    cout << "\nNV luong cao nhat: "; res->Xuat();
}

void CongTy::TimNhanVienLuongMin() {
    if (ds.empty()) return;
    NhanVien* res = ds[0];
    for (auto nv : ds) if (nv->getTongLuong() < res->getTongLuong()) res = nv;
    cout << "NV luong thap nhat: "; res->Xuat();
}

void CongTy::TimLTVMaxLuong() {
    NhanVien* res = nullptr;
    for (auto nv : ds) {
        if (dynamic_cast<LapTrinhVien*>(nv)) {
            if (!res || nv->getTongLuong() > res->getTongLuong()) res = nv;
        }
    }
    if (res) { cout << "LTV luong cao nhat: "; res->Xuat(); }
}

void CongTy::TimKCVMinLuong() {
    NhanVien* res = nullptr;
    for (auto nv : ds) {
        if (dynamic_cast<KiemChungVien*>(nv)) {
            if (!res || nv->getTongLuong() < res->getTongLuong()) res = nv;
        }
    }
    if (res) { cout << "KCV luong thap nhat: "; res->Xuat(); }
}

CongTy::~CongTy() {
    for (auto nv : ds) delete nv;
}
