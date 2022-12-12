#pragma once
#include <iostream>
using namespace std;

class Prince
{
private:
    int tien, tritue, sucmanh;

public:
    void nhap();
    void xuat();
    int getTien()
    {
        return tien;
    };
    int getTriTue()
    {
        return tritue;
    };
    int getSucManh()
    {
        return sucmanh;
    };
    void setTien(int _x)
    {
        tien = _x;
    };
    void setSucManh(int _x)
    {
        sucmanh = _x;
    };
};