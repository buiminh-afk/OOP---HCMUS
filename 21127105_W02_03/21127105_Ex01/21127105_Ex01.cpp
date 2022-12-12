#include <iostream>
#include "header.h"
using namespace std;

int main() {
    Fraction a,b;
    a.Input();
    b.Input();
    // a.Output();
    // a = a.Add(b);
    // a.Output();
    a = a.Subtract(b);
    a.Output();
    // a = a.Multiply(b);
    // a.Output();
    // a = a.Divide(b);
    // a.Output();
    a.Compare(b);
    if (a.IsNegative()) cout << "a is Negative" << endl;
    if (a.IsPositive()) cout << "a is Positive" << endl;
    if (a.IsZero()) cout << "a is 0" << endl;
    return 0;
}