#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    float x, y;
public:
    void Input();
    void Output();
    float distanceFrom(Point);
    float distanceOx();
    float distanceOy();
};

class Triangle : public Point {
private:
    Point A, B, C, G;
    float AB, BC, AC;
public:
    void Input();
    void Output();
    bool isValidTriangle();
    void TypeOfTriangle();
    float Perimeter();
    float Area();
    void CenterG();
};
