#pragma once

#include <iostream>

using namespace std;

class Date
{
private:
    int day, month, year = 2022;

public:
    void Input();
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    ///////////////////////////////
    int getDay();
    int getMonth();
    int getYear();
    ///////////////////////////////
    Date Tomorrow();
    Date Yesterday();
    ///////////////////////////////
    bool operator==(Date);
    bool operator!=(Date);
    bool operator>(Date);
    bool operator>=(Date);
    bool operator<(Date);
    bool operator<=(Date);
    ///////////////////////////////
    Date operator+(int);
    Date operator-(int);
    Date &operator++();   // PREFIX
    Date &operator--();   // PREFIX
    Date operator++(int); // POSTFIX
    operator int() const;
    operator long() const;
};