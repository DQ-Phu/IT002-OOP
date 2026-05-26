#include "CongTy.h"

void CongTy::NhapDS() {
    int n;
    while (true) {
        cout << "Nhap so luong nhan vien: ";
        if (!(cin >> n) || cin.peek() != '\n' || n < 0) {
            cout << "Loi! Nhap so duong.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore();
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhan vien " << i + 1 << " ---\n";
        int loai;
        while (true) {
            cout << "Chon cong viec nhan vien (1: Van phong, 2: San xuat): ";
            if (!(cin >> loai) || cin.peek() != '\n' || (loai != 1 && loai != 2)) {
                cout << "Loi! Chi chon 1 hoac 2.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore();
                break;
            }
        }
        NhanVien* nv = (loai == 1) ? (NhanVien*)new NVVP() : (NhanVien*)new NVSX();
        nv->Nhap();
        nv->TinhLuong();
        ds.push_back(nv);
    }
}

void CongTy::XuatDS() {
    for (auto nv : ds) nv->Xuat();
}

double CongTy::TongLuong() {
    double tong = 0;
    for (auto nv : ds) {
        tong += nv->getLuong();
    }
    return tong;
}

void CongTy::TimNVSXLuongThapNhat() {
    NhanVien* minSX = nullptr;
    for (auto nv : ds) {
        if (dynamic_cast<NVSX*>(nv)) {
            if (!minSX || nv->getLuong() < minSX->getLuong()) {
                minSX = nv;
            }
        }
    }
    if (minSX) {
        cout << "NVSX luong thap nhat: ";
        minSX->Xuat();
    } else {
        cout << "Khong co nhan vien san xuat trong danh sach.\n";
    }
}

void CongTy::TimNVVPTuoiCaoNhat() {
    NhanVien* oldestVP = nullptr;
    for (auto nv : ds) {
        if (dynamic_cast<NVVP*>(nv)) {
            if (!oldestVP) {
                oldestVP = nv;
            } else {
                // Kiểm tra năm (Nếu năm nhỏ hơn thì lớn tuổi hơn
                if (nv->getNam() < oldestVP->getNam()) {
                    oldestVP = nv;
                }
                // Nếu cùng năm thì kiêm tra tháng
                else if (nv->getNam() == oldestVP->getNam() && nv->getThang() < oldestVP->getThang()) {
                    oldestVP = nv;
                }
                // Nếu cùng năm và tháng thì kiểm tra ngày
                else if (nv->getNam() == oldestVP->getNam() && nv->getThang() == oldestVP->getThang() && nv->getNgay() < oldestVP->getNgay()) {
                    oldestVP = nv;
                }
            }
        }
    }
    if (oldestVP) {
        cout << "NVVP tuoi cao nhat: ";
        oldestVP->Xuat();
    } else {
        cout << "Khong co nhan vien van phong trong danh sach.\n";
    }
}

CongTy::~CongTy() {
    for (auto nv : ds) delete nv;
}
