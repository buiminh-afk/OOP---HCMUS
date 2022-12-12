#include "Point.h"

Point::Point()
{
    this->setX(0);
    this->setY(0);
}

Point::Point(double _x)
{
    this->setX(_x);
    this->setY(_x);
}

Point::Point(double _x, double _y)
{
    this->setX(_x);
    this->setY(_y);
}

Point::Point(string str)
{
    string x, y;
    int find = str.find(',');
    x = str.substr(1, find - 1);
    y = str.substr(find + 1, str.length() - 2 - find);
    this->setX(stod(x));
    this->setY(stod(y));
}

void Point::input()
{
    double x, y;
    cout << "Nhap toa do x : ";
    cin >> x;
    cout << "Nhap toa do y : ";
    cin >> y;
    this->setX(x);
    this->setY(y);
}

void Point::output()
{
    cout << "(" << this->getX() << "," << this->getY() << ") ";
}

void Point::LoadFromFile(string fileName)
{
    ifstream fi(fileName);
    double x, y;
    fi >> x >> y;
    this->setX(x);
    this->setY(y);
    fi.close();
}

void Point::SaveToFile(string fileName)
{
    ofstream fo(fileName);
    fo << "Toa do cua diem la : (" << this->getX() << "," << this->getY() << ")" << endl;
    fo.close();
}

double Point::distanceFrom(Point a)
{
    double ans;
    ans = sqrt(pow(abs(this->getX() - a.getX()), 2) + pow(abs(this->getY() - a.getY()), 2));
    return ans;
}
