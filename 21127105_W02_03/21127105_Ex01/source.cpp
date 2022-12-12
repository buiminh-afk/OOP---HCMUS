#include <iostream>
#include "header.h"

using namespace std;

Fraction::Fraction() {
    Numerator = 0;
    Denominator = 1;
}

int Fraction::getDenominator() {
    return Denominator;
}

int Fraction::getNumerator() {
    return Numerator;
}

void Fraction::Input() {
    cout << "type numerator : "; cin >> Numerator;
    do {
        cout << "type denominator : "; cin >> Denominator;
    } while (Denominator == 0);
}

void Fraction::Output() {
    cout << "numerator : " << getNumerator() << " - denominator : " << getDenominator() << endl;
}

Fraction Fraction::Add(Fraction a) {
    Fraction ans;
    if (Denominator == a.Denominator) {
        ans.Numerator = Numerator + a.Numerator;
        ans.Denominator = Denominator;
    } else {
        ans.Numerator = Numerator * a.Denominator + a.Numerator * Denominator;
        ans.Denominator = Denominator * a.Denominator;
    }
    ans.Reduce();
    return ans;
}

int LCM(int a, int b) {
    int temp = 0;
    while (b != 0) {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

void Fraction::Reduce() {
    int lcm = LCM(Numerator, Denominator);
    Numerator /= lcm;
    Denominator /= lcm;
}

bool Fraction::IsPositive() {
    return Numerator * Denominator > 0;
}

bool Fraction::IsNegative() {
    return Numerator * Denominator < 0;
}

bool Fraction::IsZero() {
    return Numerator == 0;
}

Fraction Fraction::Subtract(Fraction a) {
    Fraction ans;
    if (Denominator == a.Denominator)
    {
        ans.Numerator = Numerator - a.Numerator;
        ans.Denominator = Denominator;
    }
    else
    {
        ans.Numerator = Numerator * a.Denominator - a.Numerator * Denominator;
        ans.Denominator = Denominator * a.Denominator;
    }
    ans.Reduce();
    return ans;
}

Fraction Fraction::Multiply(Fraction a) {
    Fraction ans;
    ans.Numerator = Numerator * a.Numerator;
    ans.Denominator = Denominator * a.Denominator;
    ans.Reduce();
    return ans;
}

Fraction Fraction::Divide(Fraction a) {
    Fraction ans;
    if (a.Numerator == 0)
    {
        cout << "Can not divide by 0" << endl;
        return ans;
    }
    ans.Numerator = Numerator * a.Denominator;
    ans.Denominator = Denominator * a.Numerator;
    ans.Reduce();
    return ans;
}

void Fraction::Compare(Fraction a)
{
    Fraction temp = Subtract(a);
    if (temp.Numerator < 0)
        cout << "-1" << endl;
    else if (temp.Numerator > 0)
        cout << "1" << endl;
    else
        cout << "0" << endl;
}