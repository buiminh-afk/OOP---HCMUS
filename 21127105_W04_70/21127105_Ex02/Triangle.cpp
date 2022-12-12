#include "Triangle.h"

Triangle::Triangle()
{
    A.setX(0);
    A.setY(0);
    B.setX(0);
    B.setY(1);
    C.setX(1);
    C.setY(0);
}

Triangle::Triangle(double xA, double yA, double xB, double yB, double xC, double yC)
{
    A.setX(xA);
    A.setY(yA);
    B.setX(xB);
    B.setY(yB);
    C.setX(xC);
    C.setY(yC);
}

Triangle::Triangle(Point pA, Point pB, Point pC)
{
    A = pA;
    B = pB;
    C = pC;
}

Triangle::Triangle(string str)
{
    stringstream ss(str);
    string diem;
    ss >> diem;
    Point pA(diem);
    A = pA;
    ss >> diem;
    Point pB(diem);
    B = pB;
    ss >> diem;
    Point pC(diem);
    C = pC;
}

void Triangle::input()
{
    int x, y;
    cout << "Nhap diem A" << endl;
    cout << "Nhap toa do x : ";
    cin >> x;
    cout << "Nhap toa do y : ";
    cin >> y;
    A.setX(x);
    A.setY(y);
    cout << "Nhap diem B" << endl;
    cout << "Nhap toa do x : ";
    cin >> x;
    cout << "Nhap toa do y : ";
    cin >> y;
    B.setX(x);
    B.setY(y);
    cout << "Nhap diem C" << endl;
    cout << "Nhap toa do x : ";
    cin >> x;
    cout << "Nhap toa do y : ";
    cin >> y;
    C.setX(x);
    C.setY(y);
}

void Triangle::output()
{
    cout << "Toa do 3 dinh la : ";
    A.output();
    B.output();
    C.output();
}

bool Triangle::isValidTriangle()
{
    double AB = A.distanceFrom(B);
    double AC = A.distanceFrom(C);
    double BC = B.distanceFrom(C);
    return (AB + BC > AC && AB + AC > BC && AC + BC > AB);
}

void Triangle::typeOfTriangle()
{
    double AB = A.distanceFrom(B);
    double AC = A.distanceFrom(C);
    double BC = B.distanceFrom(C);
    if (!isValidTriangle())
    {
        cout << "Not valid triangle";
        return;
    }
    if (((int)sqrt((pow(AB, 2) + pow(BC, 2))) == (int)AC) ||
        ((int)sqrt((pow(AB, 2) + pow(AC, 2))) == (int)BC) ||
        ((int)sqrt((pow(AC, 2) + pow(BC, 2))) == (int)AB))
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

double Triangle::perimeter()
{
    double AB = A.distanceFrom(B);
    double AC = A.distanceFrom(C);
    double BC = B.distanceFrom(C);
    return AB + BC + AC;
}

double Triangle::area()
{
    double AB = A.distanceFrom(B);
    double AC = A.distanceFrom(C);
    double BC = B.distanceFrom(C);
    double p = (AB + BC + AC) / 2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

void Triangle::LoadFromFile(string fileName)
{
    ifstream fi(fileName);
    string A, B, C;
    fi >> A >> B >> C;
    Point ptA(A), ptB(B), ptC(C);
    this->A = ptA;
    this->B = ptB;
    this->C = ptC;
    fi.close();
}

void Triangle::SaveToFile(string fileName)
{
    ofstream fo(fileName);
    fo << "(" << this->A.getX() << "," << this->A.getY() << ") ";
    fo << "(" << this->B.getX() << "," << this->B.getY() << ") ";
    fo << "(" << this->C.getX() << "," << this->C.getY() << ") ";
    fo.close();
}