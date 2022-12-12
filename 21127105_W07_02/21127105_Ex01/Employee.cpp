#include "Employee.h"

Employee::Employee(string _id)
{
    this->id = _id;
}

Employee::Employee(string _id, string _fullName)
{
    this->id = _id;
    this->fullName = _fullName;
}

Employee::Employee(string _id, string _fullName, string _address)
{
    this->id = _id;
    this->fullName = _fullName;
    this->address = _address;
}

Employee::Employee(string _id, string _fullName, string _address, string _hireDate)
{
    this->id = _id;
    this->fullName = _fullName;
    this->address = _address;
    this->hireDate = _hireDate;
}

void Employee::input()
{
    cout << "Nhap ten : ";
    getline(cin, this->fullName);

    cout << "Nhap id : ";
    getline(cin, this->id);

    cout << "Nhap dia chi : ";
    getline(cin, this->address);

    cout << "Nhap ngay thue : ";
    getline(cin, this->hireDate);
}

void Employee::output()
{
    cout << "ID : " << this->id << endl;
    cout << "Full Name : " << this->fullName << endl;
    cout << "Address : " << this->address << endl;
    cout << "Hire Date : " << this->hireDate << endl;
}