#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
    string id = "unknown", fullName = "unknown", address = "unknown", hireDate = "unknown";

public:
    Employee() = default;
    Employee(string);                         // id;
    Employee(string, string);                 // id - full name;
    Employee(string, string, string);         // id - full name - address
    Employee(string, string, string, string); // id - full name - address - hire date
    virtual void input() = 0;
    virtual void output() = 0;
    virtual double salary() = 0;
};