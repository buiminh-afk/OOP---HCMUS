#include "Prince.h"

void Prince::nhap()
{
    cout << "Nhap so tien : ";
    cin >> tien;
    cout << "Nhap tri tue : ";
    cin >> tritue;
    cout << "Nhap suc manh : ";
    cin >> sucmanh;
}

void Prince::xuat()
{
    cout << "Suc manh : " << sucmanh << endl;
    cout << "Tien : " << tien << endl;
    cout << "Tri tue : " << tritue << endl;
}
