#pragma once

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class Point
{
private:
    double x, y;

public:
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setX(double _x)
    {
        this->x = _x;
    }
    void setY(double _y)
    {
        this->y = _y;
    }

    Point();
    Point(double);
    Point(double, double);
    Point(string);

    void input();
    void output();

    void LoadFromFile(string);
    void SaveToFile(string);

    double distanceFrom(Point);
};