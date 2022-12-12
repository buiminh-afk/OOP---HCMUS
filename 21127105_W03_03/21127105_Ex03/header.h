#pragma once
#include <iostream>

using namespace std;

class IntArray
{
private:
    int *arr;
    int size;

public:
    ~IntArray()
    {
        delete[] arr;
    };
    void Input();
    int getSize()
    {
        return this->size;
    }
    int *getArr()
    {
        return this->arr;
    }
    void setSize(int);
    friend istream &operator>>(istream &, IntArray &);
    friend ostream &operator<<(ostream &, IntArray);
    void operator=(IntArray);
    operator int() const;
    const int operator[](int) const;
    const int operator=(int) const;
};