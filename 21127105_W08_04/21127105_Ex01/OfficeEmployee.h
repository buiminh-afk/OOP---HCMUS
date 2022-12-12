#pragma once
#include "Employee.h"

class OfficeEmployee : public Employee
{
private:
    double payRate = 300000;
    int numberOfWDay = 0;

public:
    OfficeEmployee() : Employee(){};
    OfficeEmployee(string, int);
    OfficeEmployee(string, string, int);
    OfficeEmployee(string, string, string, int);
    OfficeEmployee(string, string, string, string, int);
    double salary();
    void input();
    void output();
};