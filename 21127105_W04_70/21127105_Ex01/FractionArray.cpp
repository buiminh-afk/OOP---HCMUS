#include "FractionArray.h"

FractionArray::FractionArray()
{
    fracArr.clear();
}

FractionArray::FractionArray(int _n)
{
    Fraction f;
    for (int i = 0; i < _n; i++)
        fracArr.push_back(f);
}

FractionArray::FractionArray(Fraction a[], int _n)
{
    for (int i = 0; i < _n; i++)
        fracArr.push_back(a[i]);
}

FractionArray::FractionArray(vector<Fraction> a)
{
    for (int i = 0; i < a.size(); i++)
        fracArr[i] = a[i];
}

FractionArray::FractionArray(string str)
{
    stringstream ss(str);
    string ts, ms;
    string ps;
    while (ss >> ps)
    {
        stringstream _ps(ps);
        getline(ss, ps, ' ');
        getline(_ps, ts, '/');
        getline(_ps, ms);
        Fraction tmp(stoi(ts), stoi(ms));
        fracArr.push_back(tmp);
    }
}

void FractionArray::input()
{
    int num, tu, mau;
    cout << "Nhap so phan so : ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Nhap tu so thu " << i + 1 << " : ";
        cin >> tu;
        cout << "Nhap mau so thu " << i + 1 << " : ";
        cin >> mau;
        Fraction temp(tu, mau);
        fracArr.push_back(temp);
    }
}

void FractionArray::output()
{
    for (int i = 0; i < fracArr.size(); i++)
    {
        fracArr[i].output();
        cout << endl;
    }
}

void FractionArray::LoadFromFile(string fileName)
{
    ifstream fi(fileName);
    while (!fi.eof())
    {
        string tmp;
        fi >> tmp;
        Fraction ps(tmp);
        fracArr.push_back(ps);
    }
    fi.close();
}

void FractionArray::SaveToFile(string fileName)
{
    ofstream fo(fileName);
    for (int i = 0; i < fracArr.size(); i++)
    {
        fo << fracArr[i].getNum() << " / " << fracArr[i].getDeno() << endl;
    }
    fo.close();
}

Fraction FractionArray::Sum()
{
    Fraction ans;
    for (int i = 0; i < fracArr.size(); i++)
    {
        ans = ans + fracArr[i];
    }
    return ans;
}

Fraction FractionArray::Max()
{
    Fraction ans;
    for (int i = 0; i < fracArr.size(); i++)
    {
        if (ans.Compare(fracArr[i]) == -1)
        {
            ans = fracArr[i];
        }
    }
    return ans;
}

int FractionArray::numberOfNegative()
{
    int ans = 0;
    for (int i = 0; i < fracArr.size(); i++)
        if (fracArr[i].isNegative())
            ans++;
    return ans;
}

int FractionArray::numberOfPositive()
{
    int ans = 0;
    for (int i = 0; i < fracArr.size(); i++)
        if (fracArr[i].isPositive())
            ans++;
    return ans;
}

int FractionArray::numberOfZero()
{
    int ans = 0;
    for (int i = 0; i < fracArr.size(); i++)
        if (fracArr[i].isZero())
            ans++;
    return ans;
}