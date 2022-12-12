#include "header.h"

void IntArray::Input()
{
    int size;
    cout << "Nhap so luong phan tu : ";
    cin >> size;
    int *res = new int(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Nhap phan tu thu " << i << " : ";
        cin >> res[i];
    }
    this->arr = res;
    this->size = size;
}

istream &operator>>(istream &inDev, IntArray &arr)
{
    arr.Input();
    return inDev;
}

ostream &operator<<(ostream &outDev, IntArray arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr.getArr()[i] << " ";
    }
    cout << endl;
    return outDev;
}

void IntArray::setSize(int _size)
{
    this->size = _size;
    this->arr = new int[size];
}

void IntArray::operator=(IntArray arr)
{
    int size = arr.getSize();
    this->size = size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++)
        this->arr[i] = arr.getArr()[i];
}

IntArray::operator int() const
{
    return size;
}

const int IntArray::operator[](int _x) const
{
    if (_x >= 0 && _x < size)
        return arr[_x];
    return 0;
}

const int IntArray::operator=(int _x) const
{
    cout << *this;
}