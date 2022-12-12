#include "header.h"

ostream &operator<<(ostream &out, Fraction s)
{
    s.output();
    return out;
}
Fraction operator+(int a, Fraction &ps)
{
    return ps + a;
}
Fraction operator-(int a, Fraction &ps)
{
    return ps - a;
}
Fraction operator*(int a, Fraction &ps)
{
    return ps * a;
}

int main()
{
    Fraction ps1(10, 5);
    Fraction ps2(10, 5);

    cout << 3 + ps1;
    cout << ps1 + 3;
    return 0;
}