#pragma once
#include <iostream>

using namespace std;

class Fraction {
private:
    int Numerator, Denominator;
public:
    Fraction();
    void Input();
    int getNumerator();
    int getDenominator();
    void Output();
    Fraction Add(Fraction);
    Fraction Subtract(Fraction);
    Fraction Multiply(Fraction);
    Fraction Divide(Fraction);
    void Reduce();
    void Compare(Fraction);
    bool IsPositive();
    bool IsNegative();
    bool IsZero();
};