#pragma once

#include "Point.h"
#include <sstream>

class Triangle : public Point
{
private:
    Point A, B, C;

public:
    Triangle();
    Triangle(double, double, double, double, double, double);
    Triangle(Point, Point, Point);
    Triangle(string);

    void input();
    void output();

    void LoadFromFile(string);
    void SaveToFile(string);

    bool isValidTriangle();
    void typeOfTriangle();

    double perimeter();
    double area();

    Point pointA()
    {
        return A;
    };
    Point pointB()
    {
        return B;
    };
    Point pointC()
    {
        return C;
    };
};