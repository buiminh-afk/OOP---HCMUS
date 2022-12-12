#include "OfficeEmployee.h"
#include "Worker.h"
#include <vector>

class Company
{
private:
    vector<Employee *> employeesList;

public:
    Company() = default;
    void input();
    void output();
    double totalSalaryInMonth();
    int highestSalary();
};