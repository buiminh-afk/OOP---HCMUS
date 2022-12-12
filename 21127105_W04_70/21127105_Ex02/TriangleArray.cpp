#include "TriangleArray.h"

TriangleArray::TriangleArray()
{
    Array = nullptr;
    num = 0;
}

TriangleArray::TriangleArray(int n)
{
    num = n;
    Array = new Triangle[n];
}

TriangleArray::TriangleArray(Triangle a[], int n)
{
    num = n;
    Array = new Triangle[n];
    for (int i = 0; i < n; i++)
        Array[i] = a[i];
}

TriangleArray::TriangleArray(vector<Triangle> a)
{
    num = a.size();
    Array = new Triangle[num];
    for (int i = 0; i < a.size(); i++)
        Array[i] = a[i];
}

TriangleArray::TriangleArray(string str)
{
    num = 1;
    string tmp = "";
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ';')
            num++;
    Array = new Triangle[num];
    int index = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ';' || i == str.length() - 1)
        {
            tmp.erase(0, 1);
            if (str[i] == ';')
                tmp.erase(tmp.length() - 1, 1);
            else
                tmp.erase(tmp.length(), 1);
            Triangle temp(tmp);
            Array[index] = temp;
            index++;
            tmp = "";
        }
        else
        {
            tmp += str[i];
        }
    }
}

void TriangleArray::input()
{
    cout << "Nhap so tam giac : ";
    cin >> num;
    Array = new Triangle[num];
    for (int i = 0; i < num; i++)
    {
        Triangle tmp;
        cout << "Tam giac " << i + 1 << " :" << endl;
        tmp.input();
        Array[i] = tmp;
    }
}

void TriangleArray::output()
{
    for (int i = 0; i < num; i++)
    {
        Array[i].output();
        cout << endl;
    }
}

void TriangleArray::LoadFromFile(string fileName)
{
    ifstream fi(fileName);
    string tmp;
    fi >> num;
    Array = new Triangle[num];
    int index = 0;
    fi.ignore();
    while (!fi.eof())
    {
        getline(fi, tmp, '\n');
        Triangle a(tmp);
        Array[index] = a;
        index++;
    }
    fi.close();
}

void TriangleArray::SaveToFile(string fileName)
{
    ofstream fo(fileName);
    for (int i = 0; i < this->getNum(); i++)
    {
        fo << "Tam giac thu " << i + 1 << " co toa do la : ";
        fo << "(" << this->getArr()[i].pointA().getX() << "," << this->getArr()[i].pointA().getY() << ") ";
        fo << "(" << this->getArr()[i].pointB().getX() << "," << this->getArr()[i].pointB().getY() << ") ";
        fo << "(" << this->getArr()[i].pointC().getX() << "," << this->getArr()[i].pointC().getY() << ")" << endl;
    }
    fo.close();
}

void TriangleArray::AllValidTriangle()
{
    for (int i = 0; i < this->getNum(); i++)
    {
        if (this->getArr()[i].isValidTriangle())
            this->getArr()[i].output();
        cout << endl;
    }
}

double TriangleArray::MaxArea()
{
    double max = 0;
    for (int i = 0; i < this->getNum(); i++)
    {
        if (this->getArr()[i].area() > max)
            max = this->getArr()[i].area();
    }
    return max;
}

void TriangleArray::numberOfEachType()
{
    for (int i = 0; i < this->getNum(); i++)
    {
        this->getArr()[i].typeOfTriangle();
        cout << endl;
    }
}