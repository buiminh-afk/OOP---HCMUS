#include "Math.h"

double Math::absOOP(double x) { return abs(x); }

long double Math::powOOP(double x, double y) { return pow(x, y); }

double Math::sqrtOOP(double x) { return sqrt(x); }

double Math::cbrtOOP(double x) { return cbrt(x); }

double Math::hypotOOP(double x, double y) { return hypot(x, y); }

int Math::ceilOOP(double x) { return ceil(x); }

int Math::floorOOP(double x) { return floor(x); }

int Math::roundOOP(double x) { return round(x); }

int Math::truncOOP(double x) { return trunc(x); }

double Math::logOOP(double x) { return log(x); }

double Math::log2OOP(double x) { return log2(x); }

double Math::log10OOP(double x) { return log10(x); }

double Math::sinOOP(double x) { return sin(x * PI / 180); }

double Math::cosOOP(double x) { return cos(x * PI / 180); }

double Math::tanOOP(double x) { return tan(x * PI / 180); }
