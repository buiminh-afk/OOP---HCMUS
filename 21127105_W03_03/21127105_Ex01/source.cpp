#include "header.h"

Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(int _x)
{
    this->numerator = _x;
    this->denominator = 1;
}

Fraction::Fraction(int _x, int _y)
{
    this->numerator = _x;
    if (_y == 0)
        _y = 1;
    this->denominator = _y;
}

Fraction::Fraction(string _s)
{
    stringstream ss(_s);
    string tuso, mauso;
    getline(ss, tuso, '/');
    getline(ss, mauso);
    if (mauso == "0")
        mauso = "1";
    this->numerator = stoi(tuso);
    this->denominator = stoi(mauso);
}

void Fraction::setNumerator(int _x)
{
    this->numerator = _x;
}

bool Fraction::setDenominator(int _x)
{
    if (_x == 0)
        return false;
    this->denominator = _x;
    return true;
}

void Fraction::Input()
{
    int x;
    cout << "Nhap tu so : ";
    cin >> x;
    setNumerator(x);
    cout << "Nhap mau so : ";
    cin >> x;
    while (!setDenominator(x))
    {
        cout << "Nhap mau so khac 0 :";
        cin >> x;
    }
}

void Fraction::output()
{
    cout << "Phan so la : " << this->getNumerator() << "/" << this->getDenominator();
}

void Fraction::loadFromFile(string fileName)
{
    fstream fs(fileName, ios::in);
    int tu, mau;
    fs >> tu >> mau;
    this->setNumerator(tu);
    this->setDenominator(mau);
    fs.close();
}

int GCD(int a, int b)
{
    int temp = 0;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::Reduce()
{
    int gcd = GCD(this->getNumerator(), this->getDenominator());
    this->setNumerator(this->getNumerator() / gcd);
    this->setDenominator(this->getDenominator() / gcd);
}

Fraction Fraction::operator+(Fraction phanso)
{
    Fraction ans;
    int tu, mau;
    mau = this->getDenominator() * phanso.getDenominator();
    tu = this->getNumerator() * phanso.getDenominator() + this->getDenominator() * phanso.getNumerator();
    ans.setDenominator(mau);
    ans.setNumerator(tu);
    return ans;
}

Fraction Fraction::operator+=(Fraction phanso)
{
    int tu, mau;
    mau = this->getDenominator() * phanso.getDenominator();
    tu = this->getNumerator() * phanso.getDenominator() + this->getDenominator() * phanso.getNumerator();
    this->setNumerator(tu);
    this->setDenominator(mau);
    return *this;
}

Fraction Fraction::operator+(int _x)
{
    Fraction phanso(_x);
    Fraction ans;
    int tu, mau;
    mau = this->getDenominator() * phanso.getDenominator();
    tu = this->getNumerator() * phanso.getDenominator() + this->getDenominator() * phanso.getNumerator();
    ans.setDenominator(mau);
    ans.setNumerator(tu);
    return ans;
}

Fraction Fraction::operator-(int _x)
{
    Fraction phanso(_x);
    Fraction ans;
    if (this->getDenominator() == phanso.getDenominator())
    {
        ans.setNumerator(this->getNumerator() - phanso.getNumerator());
        ans.setDenominator(this->getDenominator());
    }
    else
    {
        int tu = this->getNumerator() * phanso.getDenominator() - phanso.getNumerator() * this->getDenominator();
        ans.setNumerator(tu);
        ans.setDenominator(this->getDenominator() * phanso.getDenominator());
    }
    return ans;
}

Fraction Fraction::operator*(int _x)
{
    Fraction phanso(_x);
    Fraction ans;
    ans.setNumerator(this->getNumerator() * phanso.getNumerator());
    ans.setDenominator(this->getDenominator() * phanso.getDenominator());
    return ans;
}

Fraction Fraction::operator/(int _x)
{
    Fraction phanso(_x);
    Fraction ans;
    if (phanso.getNumerator() == 0)
    {
        cout << "Can not divide by 0";
        return ans;
    }
    ans.setNumerator(this->getNumerator() * phanso.getDenominator());
    ans.setDenominator(this->getDenominator() * phanso.getNumerator());
    return ans;
}

void Fraction::operator=(Fraction phanso)
{
    this->setNumerator(phanso.getNumerator());
    this->setDenominator(phanso.getDenominator());
}

Fraction Fraction::operator-(Fraction a)
{
    Fraction ans;
    if (this->getDenominator() == a.getDenominator())
    {
        ans.setNumerator(this->getNumerator() - a.getNumerator());
        ans.setDenominator(this->getDenominator());
    }
    else
    {
        int tu = this->getNumerator() * a.getDenominator() - a.getNumerator() * this->getDenominator();
        ans.setNumerator(tu);
        ans.setDenominator(this->getDenominator() * a.getDenominator());
    }
    return ans;
}

Fraction Fraction::operator-=(Fraction phanso)
{
    Fraction ans;
    if (this->getDenominator() == phanso.getDenominator())
    {
        ans.setNumerator(this->getNumerator() - phanso.getNumerator());
        ans.setDenominator(this->getDenominator());
    }
    else
    {
        int tu = this->getNumerator() * phanso.getDenominator() - phanso.getNumerator() * this->getDenominator();
        ans.setNumerator(tu);
        ans.setDenominator(this->getDenominator() * phanso.getDenominator());
    }
    this->setDenominator(ans.getDenominator());
    this->setNumerator(ans.getNumerator());
    return *this;
}

Fraction Fraction::operator*(Fraction phanso)
{
    Fraction ans;
    ans.setNumerator(this->getNumerator() * phanso.getNumerator());
    ans.setDenominator(this->getDenominator() * phanso.getDenominator());
    return ans;
}

Fraction Fraction::operator*=(Fraction phanso)
{
    Fraction ans;
    ans.setNumerator(this->getNumerator() * phanso.getNumerator());
    ans.setDenominator(this->getDenominator() * phanso.getDenominator());
    this->setDenominator(ans.getDenominator());
    this->setNumerator(ans.getNumerator());
    return *this;
}

Fraction Fraction::operator/(Fraction phanso)
{
    Fraction ans;
    if (phanso.getNumerator() == 0)
    {
        cout << "Can not divide by 0";
        return ans;
    }
    ans.setNumerator(this->getNumerator() * phanso.getDenominator());
    ans.setDenominator(this->getDenominator() * phanso.getNumerator());
    return ans;
}

Fraction Fraction::operator/=(Fraction phanso)
{
    Fraction ans;
    if (phanso.getNumerator() == 0)
    {
        cout << "Can not divide by 0";
        return ans;
    }
    ans.setNumerator(this->getNumerator() * phanso.getDenominator());
    ans.setDenominator(this->getDenominator() * phanso.getNumerator());
    this->setDenominator(ans.getDenominator());
    this->setNumerator(ans.getNumerator());
    return *this;
}

bool Fraction::operator==(Fraction phanso)
{
    return this->getNumerator() * phanso.getDenominator() == this->getDenominator() * phanso.getNumerator();
}

bool Fraction::operator!=(Fraction phanso)
{
    return this->getNumerator() * phanso.getDenominator() != this->getDenominator() * phanso.getNumerator();
}

bool Fraction::operator>(Fraction phanso)
{
    return this->getNumerator() * phanso.getDenominator() > this->getDenominator() * phanso.getNumerator();
}

bool Fraction::operator>=(Fraction phanso)
{
    return this->getNumerator() * phanso.getDenominator() >= this->getDenominator() * phanso.getNumerator();
}

bool Fraction::operator<(Fraction phanso)
{
    return this->getNumerator() * phanso.getDenominator() < this->getDenominator() * phanso.getNumerator();
}

bool Fraction::operator<=(Fraction phanso)
{
    return this->getNumerator() * phanso.getDenominator() <= this->getDenominator() * phanso.getNumerator();
}

Fraction &Fraction::operator++()
{
    int x = 1;
    Fraction a;
    a.setNumerator(x * this->getDenominator());
    a.setDenominator(this->getDenominator());
    this->setNumerator(this->getNumerator() + a.getNumerator());
    this->setDenominator(this->getDenominator());
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp = *this;
    ++*this;
    return *this;
}

Fraction &Fraction::operator--()
{
    int x = -1;
    Fraction a;
    a.setNumerator(x * this->getDenominator());
    a.setDenominator(this->getDenominator());
    this->setNumerator(this->getNumerator() + a.getNumerator());
    this->setDenominator(this->getDenominator());
    return *this;
}

Fraction Fraction::operator--(int)
{
    Fraction temp = *this;
    --*this;
    return *this;
}

Fraction ::operator float() const
{
    float ans = (float)numerator / (float)denominator;
    return ans;
}

Fraction operator/(int a, Fraction &ps)
{
    return ps / a;
}