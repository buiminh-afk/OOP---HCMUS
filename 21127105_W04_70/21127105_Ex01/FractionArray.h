#pragma once

#include <iostream>
#include "Fraction.h"
#include <vector>
#include <sstream>

class FractionArray : public Fraction
{
private:
    vector<Fraction> fracArr;

public:
    FractionArray();
    FractionArray(int);
    FractionArray(Fraction[], int);
    FractionArray(vector<Fraction>);
    FractionArray(string);
    void input();
    void output();
    void LoadFromFile(string);
    void SaveToFile(string);
    Fraction Sum();
    Fraction Max();
    int numberOfNegative();
    int numberOfPositive();
    int numberOfZero();
};
