#include "BatDongSan.h"

void BatDongSan::NhapDS() {
    int n, loai;
    cout << "Nhap so luong giao dich: "; cin >> n;
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "\nChon loai (1: Dat, 2: Nha Pho, 3: Can ho): ";
            if (!(cin >> loai) || loai < 1 || loai > 3) {
                cin.clear(); cin.ignore(1000, '\n');
            } else break;
        }
        GiaoDich* gd = nullptr;
        if (loai == 1) gd = new GiaoDichDat();
        else if (loai == 2) gd = new GiaoDichNha();
        else gd = new GiaoDichCanHo();

        gd->Nhap();
        gd->TinhThanhTien();
        ds.push_back(gd);
    }
}

void BatDongSan::XuatDS() {
    for (auto gd : ds) gd->Xuat();
}

void BatDongSan::ThongKeSoLuong() {
    int d = 0, n = 0, c = 0;
    for (auto gd : ds) {
        if (dynamic_cast<GiaoDichDat*>(gd)) d++;
        else if (dynamic_cast<GiaoDichNha*>(gd)) n++;
        else if (dynamic_cast<GiaoDichCanHo*>(gd)) c++;
    }
    cout << "\n--- SO LUONG GIAO DICH ---\n";
    cout << "Dat: " << d << " | Nha: " << n << " | Can ho: " << c << endl;
}

void BatDongSan::TrungBinhCanHo() {
    double tong = 0; int count = 0;
    for (auto gd : ds) {
        if (dynamic_cast<GiaoDichCanHo*>(gd)) {
            tong += gd->getThanhTien();
            count++;
        }
    }
    if (count > 0) cout << "Trung binh thanh tien Can ho: " << (long long)(tong / count) << endl;
}

void BatDongSan::TimNhaPhoMax() {
    GiaoDich* maxGD = nullptr;
    for (auto gd : ds) {
        if (dynamic_cast<GiaoDichNha*>(gd)) {
            if (!maxGD || gd->getThanhTien() > maxGD->getThanhTien()) maxGD = gd;
        }
    }
    if (maxGD) { cout << "Nha pho tri gia cao nhat: "; maxGD->Xuat(); }
}

void BatDongSan::XuatThang12_2024() {
    cout << "\n--- GIAO DICH THANG 12/2024 ---\n";
    for (auto gd : ds) {
        if (gd->getThang() == 12 && gd->getNam() == 2024) gd->Xuat();
    }
}

BatDongSan::~BatDongSan() {
    for (auto gd : ds) delete gd;
}
