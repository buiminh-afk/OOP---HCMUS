#pragma once
#include "Prince.h"
#include <iostream>
using namespace std;

class Gate
{
public:
    virtual void nhap() = 0;
    virtual bool quaCong(Prince &) = 0;
};

class BusinessGate : public Gate
{
private:
    int dongia, soluong;

public:
    BusinessGate() = default;
    void nhap();
    bool quaCong(Prince &);
};

class AcademicGate : public Gate
{
private:
    int tritue;

public:
    AcademicGate() = default;
    void nhap();
    bool quaCong(Prince &);
};

class PowerGate : public Gate
{
private:
    int sucmanh;

public:
    PowerGate() = default;
    void nhap();
    bool quaCong(Prince &);
};