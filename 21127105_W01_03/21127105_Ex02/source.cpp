#include "header.h"

void Point::Input() {
    cout << "type x : "; cin >> x;
    cout << "type y : "; cin >> y;
}

void Point::Output() {
    cout << "posX : " << x << " - posY : " << y << endl;
}

float Point::distanceFrom(Point a) {
    return sqrt(pow((a.x-x),2) + pow((a.y-y),2));
}

float Point::distanceOx() {
    return y;
}

float Point::distanceOy() {
    return x;
}

void Triangle::Input() {
    cout << "Point A" << endl;
    A.Input();
    cout << "Point B" << endl;
    B.Input();
    cout << "Point C" << endl;
    C.Input();
}

void Triangle::Output() {
    cout << "Point A" << endl;
    A.Output();
    cout << "Point B" << endl;
    B.Output();
    cout << "Point C" << endl;
    C.Output();
}

bool Triangle::isValidTriangle() {
    AB = A.distanceFrom(B);
    AC = A.distanceFrom(C);
    BC = B.distanceFrom(C);
    return (AB + BC > AC && AB + AC > BC && AC + BC > AB);
}

void Triangle::TypeOfTriangle()
{
    if (!isValidTriangle()) {
        cout << "Not valid triangle";
        return; 
    }
    if (((int)sqrt((pow(AB,2) + pow(BC,2))) == (int)AC) ||
        ((int)sqrt((pow(AB,2) + pow(AC,2))) == (int)BC) ||
        ((int)sqrt((pow(AC,2) + pow(BC,2))) == (int)AB)  )
    {
        if ((AB == AC) || (AC == BC) || (AB == BC))
            cout << "Right-angled Isosceles triangle" << endl;
        else
            cout << "Right-angled triangle" << endl;
    }
    else
    {
        if (AB == AC && AC == BC)
            cout << "Equilateral triangle" << endl;
        else if (AB == AC || AC == BC || AB == BC)
            cout << "Isosceles triangle" << endl;
        else
            cout << "Scalene triangle" << endl;
    }
}

float Triangle::Perimeter() {
    return AB + BC + AC;
}

float Triangle::Area() {
    float p = (AB + BC + AC)/2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

void Triangle::CenterG() {
    float x = (A.distanceOy() + B.distanceOy() + C.distanceOy())/3;
    float y = (A.distanceOx() + B.distanceOx() + C.distanceOx())/3;
    cout << "Center G : (" << x << ", " << y << ")";
}