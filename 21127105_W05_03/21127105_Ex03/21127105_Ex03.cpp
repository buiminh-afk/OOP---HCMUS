#include "Math.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Absolute of -100 : " << Math::absOOP(-100) << endl;
    cout << "2 to the power of 10 : " << Math::powOOP(2, 10) << endl;
    cout << "Square root of 64 : " << Math::sqrtOOP(64) << endl;
    cout << "Cubic root of 27 : " << Math::absOOP(27) << endl;
    cout << "Absolute : " << Math::absOOP(-100) << endl;
    cout << "Hypotenuse of a right-angled triangle whose legs are 3 and 4 : " << Math::hypotOOP(3, 4) << endl;
    cout << "Ceil : " << Math::ceilOOP(2.3) << endl;
    cout << "Floor : " << Math::floorOOP(2.3) << endl;
    cout << "Trunc : " << Math::truncOOP(2.3) << endl;
    cout << "Log of 100 : " << Math::logOOP(100) << endl;
    cout << "Log 100 to the base 10 : " << Math::log10OOP(100) << endl;
    cout << "Log 100 to the base 2 : " << Math::log2OOP(100) << endl;
    cout << "Sin(30) : " << Math::sinOOP(30) << endl;
    cout << "Cos(30) : " << Math::cosOOP(30) << endl;
    cout << "Tan(30) : " << Math::tanOOP(30) << endl;
    return 0;
}