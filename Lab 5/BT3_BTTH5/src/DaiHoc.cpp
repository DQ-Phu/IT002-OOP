#include "DaiHoc.h"

void DaiHoc::NhapDS() {
    int n, loai;
    cout << "Nhap so luong sinh vien: "; cin >> n;
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "\nChon loai (1: Cao dang, 2: Dai hoc): ";
            if (!(cin >> loai) || (loai != 1 && loai != 2)) {
                cin.clear(); cin.ignore(1000, '\n');
            } else break;
        }
        SinhVien* sv = (loai == 1) ? (SinhVien*)new SinhVienCD() : (SinhVien*)new SinhVienDH();
        sv->Nhap();
        ds.push_back(sv);
    }
}

void DaiHoc::XuatDS() {
    for (auto sv : ds) sv->Xuat();
}

void DaiHoc::XuatDuDieuKienTN() {
    cout << "\n--- SINH VIEN DU DIEU KIEN TOT NGHIEP ---\n";
    for (auto sv : ds) if (sv->KiemTraTotNghiep()) sv->Xuat();
}

void DaiHoc::XuatKhongDuDieuKienTN() {
    cout << "\n--- SINH VIEN CHUA DU DIEU KIEN TOT NGHIEP ---\n";
    for (auto sv : ds) if (!sv->KiemTraTotNghiep()) sv->Xuat();
}

void DaiHoc::TimDHMaxDTB() {
    SinhVien* maxSV = nullptr;
    for (auto sv : ds) {
        if (dynamic_cast<SinhVienDH*>(sv)) {
            if (!maxSV || sv->getDiemTB() > maxSV->getDiemTB()) maxSV = sv;
        }
    }
    if (maxSV) { cout << "SV Dai hoc co DTB cao nhat: "; maxSV->Xuat(); }
}

void DaiHoc::TimCDMaxDTB() {
    SinhVien* maxSV = nullptr;
    for (auto sv : ds) {
        if (dynamic_cast<SinhVienCD*>(sv)) {
            if (!maxSV || sv->getDiemTB() > maxSV->getDiemTB()) maxSV = sv;
        }
    }
    if (maxSV) { cout << "SV Cao dang co DTB cao nhat: "; maxSV->Xuat(); }
}

void DaiHoc::ThongKeTruotTheoLoai() {
    int cd = 0, dh = 0;
    for (auto sv : ds) {
        if (!sv->KiemTraTotNghiep()) {
            if (dynamic_cast<SinhVienCD*>(sv)) cd++;
            else dh++;
        }
    }
    cout << "\n--- SO SV CHUA TOT NGHIEP ---\n";
    cout << "Cao dang: " << cd << " | Dai hoc: " << dh << endl;
}

DaiHoc::~DaiHoc() {
    for (auto sv : ds) delete sv;
}
