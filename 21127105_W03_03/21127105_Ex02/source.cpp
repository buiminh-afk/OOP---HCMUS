#include "header.h"

bool isLeapYear(int _x)
{
    if (_x % 400 == 0)
        return true;
    else if (_x % 100 == 0)
        return false;
    else if (_x % 4 == 0)
        return true;
    else
        return false;
}

int endofmonth(int _x, int year)
{
    if (_x == 1 || _x == 3 || _x == 5 || _x == 7 || _x == 8 || _x == 10 || _x == 12)
        return 31;
    if (_x == 4 || _x == 6 || _x == 9 || _x == 11)
        return 30;
    if (_x == 2)
        return isLeapYear(year) ? 29 : 28;
    return 0;
}

void Date::setDay(int _x)
{
    this->day = _x;
}

void Date::setMonth(int _x)
{
    this->month = _x;
}

void Date::setYear(int _x)
{
    this->year = _x;
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}

void Date::Input()
{
    int ngay, thang, nam, validDay;
    cout << "Nhap ngay : ";
    cin >> ngay;
    cout << "Nhap thang : ";
    cin >> thang;
    cout << "Nhap nam : ";
    cin >> nam;
    while (nam <= 0)
    {
        cout << "Nhap lai nam : ";
        cin >> nam;
    }
    while (thang < 1 || thang > 12)
    {
        cout << "Nhap lai thang : ";
        cin >> thang;
    }
    validDay = endofmonth(thang, nam);

    while (ngay < 1 || ngay > validDay)
    {
        cout << "Nhap lai ngay : ";
        cin >> ngay;
    }
    this->setDay(ngay);
    this->setMonth(thang);
    this->setYear(nam);
}

Date Date::Tomorrow()
{
    int endDay = endofmonth(this->getMonth(), this->year);
    Date ans;
    if (this->getDay() == endDay)
    {
        ans.setDay(1);
        if (this->getMonth() == 12)
        {
            ans.setMonth(1);
            ans.setYear(2023);
        }
        else
            ans.setMonth(this->getMonth() + 1);
    }
    else
    {
        ans.setDay(this->getDay() + 1);
        ans.setMonth(this->getMonth());
    }
    return ans;
}

Date Date::Yesterday()
{
    Date ans;
    if (this->getDay() == 1)
    {
        if (this->getMonth() == 1)
        {
            ans.setDay(31);
            ans.setMonth(12);
            ans.setYear(this->getYear() - 1);
        }
        else
        {
            int endDay = endofmonth(this->getMonth() - 1, this->year);
            ans.setDay(endDay);
            ans.setMonth(this->getMonth() - 1);
        }
    }
    else
    {
        ans.setDay(this->getDay() - 1);
        ans.setMonth(this->getMonth());
    }
    return ans;
}

bool Date::operator==(Date d)
{
    if (d.getDay() == this->getDay() &&
        d.getMonth() == this->getMonth() &&
        d.getYear() == this->getYear())
        return true;
    return false;
}

bool Date::operator!=(Date d)
{
    if (d.getDay() != this->getDay() ||
        d.getMonth() != this->getMonth() ||
        d.getYear() != this->getYear())
        return true;
    return false;
}

bool Date::operator>(Date d)
{
    if (d == *this)
        return false;
    if (this->getYear() > d.getYear())
    {
        return true;
    }
    else if (this->getYear() == d.getYear())
    {
        if (this->getMonth() > d.getMonth())
        {
            return true;
        }
        else if (this->getMonth() == d.getMonth())
        {
            if (this->getDay() > d.getDay())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Date::operator>=(Date d)
{
    if (this->getYear() == d.getYear())
    {
        if (this->getMonth() == d.getMonth())
        {
            if (this->getDay() >= d.getDay())
            {
                return true;
            }
            else
                return false;
        }
        else if (this->getMonth() > d.getMonth())
        {
            return true;
        }
        else
            return false;
    }
    else if (this->getYear() > d.getYear())
    {
        return true;
    }
    else
        return false;
}

bool Date::operator<(Date d)
{
    if (d == *this)
        return false;
    if (this->getYear() < d.getYear())
    {
        return true;
    }
    else if (this->getYear() == d.getYear())
    {
        if (this->getMonth() < d.getMonth())
        {
            return true;
        }
        else if (this->getMonth() == d.getMonth())
        {
            if (this->getDay() < d.getDay())
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

bool Date::operator<=(Date d)
{
    if (this->getYear() == d.getYear())
    {
        if (this->getMonth() == d.getMonth())
        {
            if (this->getDay() <= d.getDay())
            {
                return true;
            }
            else
                return false;
        }
        else if (this->getMonth() < d.getMonth())
        {
            return true;
        }
        else
            return false;
    }
    else if (this->getYear() < d.getYear())
    {
        return true;
    }
    else
        return false;
}

Date Date::operator+(int x)
{
    for (int i = 0; i < x; i++)
    {
        *this = this->Tomorrow();
    }
    return *this;
}

Date Date::operator-(int x)
{
    for (int i = 0; i < abs(x); i++)
    {
        *this = this->Yesterday();
    }
    return *this;
}

Date &Date::operator++()
{
    *this = this->Tomorrow();
    return *this;
}

Date &Date::operator--()
{
    *this = this->Yesterday();
    return *this;
}

Date operator++(Date &d, int)
{
    Date newDate = d;
    newDate = newDate.Tomorrow();
    return newDate;
}

Date ::operator int() const
{
    int ans = 0;
    for (int i = 1; i < month; i++)
    {
        ans += endofmonth(i, this->year);
    }
    return ans + day;
}

Date ::operator long() const
{
    int ans = 0;
    for (int i = 1; i < year; i++)
    {
        if (isLeapYear(i))
            ans += 366;
        else
            ans += 365;
    }
    for (int i = 1; i < month; i++)
    {
        ans += endofmonth(i, year);
    }
    return ans + day;
}