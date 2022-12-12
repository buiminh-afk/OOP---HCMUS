#include "Worker.h"

Worker::Worker(string _id, int _numberOfProduct) : Employee(_id)
{
    this->numberOfProduct = _numberOfProduct;
}

Worker::Worker(string _id, string _fullName, int _numberOfProduct) : Employee(_id, _fullName)
{
    this->numberOfProduct = _numberOfProduct;
}

Worker::Worker(string _id, string _fullName, string _address, int _numberOfProduct) : Employee(_id, _fullName, _address)
{
    this->numberOfProduct = _numberOfProduct;
}

Worker::Worker(string _id, string _fullName, string _address, string _hireDay, int _numberOfProduct) : Employee(_id, _fullName, _address, _hireDay)
{
    this->numberOfProduct = _numberOfProduct;
}

double Worker::salary()
{
    return numberOfProduct * payRate;
}

void Worker::input()
{
    Employee::input();
    cout << "Nhap so san phan da lam : ";
    cin >> this->numberOfProduct;
    cin.ignore();
}

void Worker::output()
{
    Employee::output();
    cout << "So san phan da lam : " << this->numberOfProduct << endl;
}