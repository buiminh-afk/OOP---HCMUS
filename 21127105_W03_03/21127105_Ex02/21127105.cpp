#include "header.h"

ostream &operator<<(ostream &out, Date &d)
{
    out << d.getDay() << " / " << d.getMonth() << " / " << d.getYear() << endl;
    return out;
}

int main()
{
    Date d1, d2, d3;
    d1.Input();
    // d2.Input();
    cout << (int)d1 << endl;
    cout << d1;
    // cout << d1 << d2;
    // cout << (d1 > d2) << endl;
    // cout << (d1 < d2) << endl;
    // cout << (d1 >= d2) << endl;
    // cout << (d1 <= d2) << endl;
    // d1 = d1 + 1;
    // cout << d1;
    // cout << d1;

    // cout << d1;
    // cout << (long)d1;
    return 0;
}