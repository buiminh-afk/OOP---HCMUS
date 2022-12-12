#include "Castle.h"
#include "Prince.h"
int main()
{
    Castle game;
    Prince bui;
    bui.nhap();
    game.nhapDS();
    if (game.cuuCongChua(bui))
    {
        cout << "Ban da chien thang" << endl;
        bui.xuat();
    }
    else
    {
        cout << "Ban thua roi";
    }
    return 0;
}