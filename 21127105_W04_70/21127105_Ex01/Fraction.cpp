#include "Fraction.h"

int Fraction::getDeno()
{
    return this->Denominator;
}

int Fraction::getNum()
{
    return this->Numerator;
}

bool Fraction::setDeno(int _x)
{
    if (_x == 0)
        return false;
    this->Denominator = _x;
    return true;
}

void Fraction::setNum(int _x)
{
    this->Numerator = _x;
}

Fraction::Fraction()
{
    this->setNum(0);
    this->setDeno(1);
}

Fraction::Fraction(int _x)
{
    this->setNum(_x);
    this->setDeno(1);
}

Fraction::Fraction(int _x, int _y)
{
    this->setNum(_x);
    this->setDeno(_y);
}

Fraction::Fraction(string str)
{
    stringstream ss(str);
    string tu, mau;
    getline(ss, tu, '/');
    getline(ss, mau);
    this->setNum(stoi(tu));
    this->setDeno(stoi(mau));
}

void Fraction::output()
{
    cout << this->getNum() << " / " << this->getDeno();
}

void Fraction::LoadFromFile(string fileName)
{
    ifstream fi(fileName);
    int tu, mau;
    fi >> tu >> mau;
    this->setNum(tu);
    while (!this->setDeno(mau))
    {
        cout << "Nhap lai mau : ";
        cin >> mau;
    }
    fi.close();
}

void Fraction::SaveToFile(string fileName)
{
    ofstream fo(fileName);
    fo << this->getNum() << " / " << this->getDeno();
    fo.close();
}

Fraction Fraction::operator+(Fraction ps)
{
    Fraction ans;
    ans.setDeno(ps.getDeno() * this->getDeno());
    ans.setNum(this->getNum() * ps.getDeno() + this->getDeno() * ps.getNum());
    return ans;
}

int Fraction::Compare(Fraction ps)
{
    int vt = ps.getDeno() * this->getNum();
    int vp = ps.getNum() * this->getDeno();
    if (vt > vp)
    {
        return 1;
    }
    else if (vt < vp)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

bool Fraction::isPositive()
{
    return (this->getDeno() * this->getNum()) > 0;
}

bool Fraction::isNegative()
{
    return (this->getDeno() * this->getNum()) < 0;
}

bool Fraction::isZero()
{
    return this->getNum() == 0;
}
