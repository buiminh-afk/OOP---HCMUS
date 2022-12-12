#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Fraction
{
private:
    int Numerator, Denominator;

public:
    void setNum(int);
    bool setDeno(int);
    int getNum();
    int getDeno();

    Fraction();
    Fraction(int);
    Fraction(int, int);
    Fraction(string);

    void input();
    void output();

    void LoadFromFile(string);
    void SaveToFile(string);

    Fraction operator+(Fraction);
    int Compare(Fraction);
    bool isPositive();
    bool isNegative();
    bool isZero();
};