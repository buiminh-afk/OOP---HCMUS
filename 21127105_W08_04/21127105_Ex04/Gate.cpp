#include "Gate.h"

void BusinessGate::nhap()
{
    cout << "Nhap don gia : ";
    cin >> this->dongia;
    cout << "Nhap so luong : ";
    cin >> this->soluong;
}

void AcademicGate::nhap()
{
    cout << "Nhap tri tue : ";
    cin >> this->tritue;
}

void PowerGate::nhap()
{
    cout << "Nhap suc manh : ";
    cin >> this->sucmanh;
}

bool BusinessGate::quaCong(Prince &bui)
{
    if (bui.getTien() >= (dongia * soluong))
    {
        bui.setTien(bui.getTien() - dongia * soluong);
        return true;
    }
    return false;
}

bool AcademicGate::quaCong(Prince &bui)
{
    return bui.getTriTue() >= tritue;
}

bool PowerGate::quaCong(Prince &bui)
{
    if (bui.getSucManh() >= sucmanh)
    {
        bui.setSucManh(bui.getSucManh() - sucmanh);
        return true;
    }
    return false;
}