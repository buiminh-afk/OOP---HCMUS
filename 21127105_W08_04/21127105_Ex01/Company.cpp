#include "Company.h"

void Company::input()
{
    int number, opt;
    OfficeEmployee *temp1;
    Worker *temp2;
    cout << "Nhap so nhan vien : ";
    cin >> number;
    cin.ignore();
    cout << "1. Nhan vien van phong" << endl
         << "2. Cong nhan" << endl;
    for (int i = 0; i < number; i++)
    {
        cout << "Nhan vien thu " << i + 1 << " la :";
        cin >> opt;
        cin.ignore();
        switch (opt)
        {
        case 1:
            temp1 = new OfficeEmployee;
            temp1->input();
            this->employeesList.push_back(temp1);
            break;
        case 2:
            temp2 = new Worker;
            temp2->input();
            this->employeesList.push_back(temp2);
            break;
        default:
            cout << "Nhap bi loi" << endl;
            break;
        }
    }
}

void Company::output()
{
    for (int i = 0; i < employeesList.size(); i++)
    {
        employeesList[i]->output();
        cout << "-----------------------" << endl;
    }
}

double Company::totalSalaryInMonth()
{
    double res = 0;
    for (int i = 0; i < employeesList.size(); i++)
    {
        res += employeesList[i]->salary();
    }
    return res;
}

int Company::highestSalary()
{
    double max = 0;
    int index = 0;
    for (int i = 0; i < employeesList.size(); i++)
        if (employeesList[i]->salary() > max)
        {
            max = employeesList[i]->salary();
            index = i;
        }
    return index;
}