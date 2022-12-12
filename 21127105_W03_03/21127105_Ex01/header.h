#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction();
    Fraction(int);
    Fraction(int, int);
    Fraction(string);
    ~Fraction(){};
    int getNumerator() { return this->numerator; };
    int getDenominator() { return this->denominator; };
    void setNumerator(int);
    bool setDenominator(int);
    void Input();
    void output();
    void loadFromFile(string);
    void Reduce();
    Fraction operator+(Fraction);
    Fraction operator+(int);
    Fraction operator+=(Fraction);

    Fraction operator-(Fraction);
    Fraction operator-(int);
    Fraction operator-=(Fraction);

    Fraction operator*(Fraction);
    Fraction operator*(int);
    Fraction operator*=(Fraction);

    Fraction operator/(Fraction);
    Fraction operator/(int);
    Fraction operator/=(Fraction);
    void operator=(Fraction);
    bool operator==(Fraction);
    bool operator!=(Fraction);
    bool operator>(Fraction);
    bool operator>=(Fraction);
    bool operator<(Fraction);
    bool operator<=(Fraction);
    Fraction operator++(int);
    Fraction &operator++();
    Fraction operator--(int);
    Fraction &operator--();
    friend Fraction operator/(int, Fraction &);
    operator float() const;
};