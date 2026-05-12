#include <iostream>
#include <windows.h>
#include <limits>
#include "CTime.h"

using namespace std;

void hienThiGocManHinh(const CTime& t) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Lưu vị trí cũ của con trỏ
    COORD oldPos = csbi.dwCursorPosition;

    // Xác định vị trí góc trên bên phải (cách lề 20 ký tự cho an toàn)
    int width = csbi.dwSize.X;
    COORD corner = {(SHORT)(width - 20), 0};

    // Xóa đồng hồ cũ bằng cách in khoảng trắng
    SetConsoleCursorPosition(hConsole, corner);
    cout << "                    "; // 20 khoảng trắng để xóa sạch dòng cũ

    // In đồng hồ mới đè lên
    SetConsoleCursorPosition(hConsole, corner);
    cout << "CLOCK: [" << t << "]" << flush;

    // Quay lại vị trí cũ để tiếp tục nhập liệu
    SetConsoleCursorPosition(hConsole, oldPos);
}

int main() {
    CTime t;
    cout << "Thiet lap dong ho (Gio Phut Giay): " << endl;
    cin >> t;

    system("cls");
    int option;

    // Ẩn con trỏ nhấp nháy ở góc màn hình khi cập nhật (tùy chọn)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);

    do {
        hienThiGocManHinh(t);

        cout << "\n--- MENU DIEU KHIEN ---" << endl;
        cout << "1. ++ (Tang 1s)" << endl;
        cout << "2. -- (Giam 1s)" << endl;
        cout << "3. +  (Cong n giay)" << endl;
        cout << "4. -  (Tru n giay)" << endl;
        cout << "0. Thoat" << endl;


        // Hiện con trỏ để người dùng thấy chỗ nhập
        cursorInfo.bVisible = true;
        SetConsoleCursorInfo(hConsole, &cursorInfo);

        while (true){
            cout << "Chon: ";
            cin >> option;
            if (cin.fail() || cin.peek() != '\n') {
                cout << "\nLoi! Chi duoc nhap so nguyen!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else if (option > 4 || option < 0){
                cout << "\nKhong co lua chon nay, vui long nhap lai!\n";
                continue;
            }
            break;
        }

        if (option == 1) t++;
        else if (option == 2) t--;
        else if (option == 3) {
            int n; cout << "Nhap giay: "; cin >> n;
            t = t + n;
        }
        else if (option == 4) {
            int n; cout << "Nhap giay: "; cin >> n;
            t = t - n;
        }

    } while (option != 0);

    return 0;
}
