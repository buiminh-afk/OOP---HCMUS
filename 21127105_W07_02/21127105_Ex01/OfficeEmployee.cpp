#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee(string _id, int _numberOfDay) : Employee(_id)
{
    this->numberOfWDay = _numberOfDay;
}

OfficeEmployee::OfficeEmployee(string _id, string _fullName, int _numberOfDay) : Employee(_id, _fullName)
{
    this->numberOfWDay = _numberOfDay;
}

OfficeEmployee::OfficeEmployee(string _id, string _fullName, string _address, int _numberOfDay) : Employee(_id, _fullName, _address)
{
    this->numberOfWDay = _numberOfDay;
}

OfficeEmployee::OfficeEmployee(string _id, string _fullName, string _address, string _hireDay, int _numberOfDay) : Employee(_id, _fullName, _address, _hireDay)
{
    this->numberOfWDay = _numberOfDay;
}

double OfficeEmployee::salary()
{
    return numberOfWDay * payRate;
}

void OfficeEmployee::input()
{
    Employee::input();
    cout << "Nhap so ngay da lam : ";
    cin >> this->numberOfWDay;
    cin.ignore();
}

void OfficeEmployee::output()
{
    Employee::output();
    cout << "So ngay lam " << this->numberOfWDay << endl;
}