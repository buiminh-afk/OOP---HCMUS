#include "Fraction.h"
#include "FractionArray.h"
int main()
{
    FractionArray test;
    test.LoadFromFile("frac.txt");
    Fraction ans = test.Max();
    ans.output();
    return 0;
}