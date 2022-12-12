#pragma once
#include "Employee.h"

class Worker : public Employee
{
private:
    double payRate = 20000;
    int numberOfProduct = 0;

public:
    Worker() : Employee(){};
    Worker(string, int);
    Worker(string, string, int);
    Worker(string, string, string, int);
    Worker(string, string, string, string, int);
    double salary();
    void input();
    void output();
};