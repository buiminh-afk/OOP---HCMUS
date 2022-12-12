#include "BankAccount.h"

void BankAccount::input()
{
    cout << "Nhap ten: ";
    getline(cin, this->Username);

    cout << "Nhap so tai khoan: ";
    getline(cin, this->accountNumber);

    cout << "Nhap so cmnd : ";
    getline(cin, this->SocialID);

    cout << "Nhap so tien trong tai khoan : ";
    cin >> this->Balance;
    cin.ignore();
}

void BankAccount::output()
{
    cout << "Ten: ";
    cout << this->Username << endl;
    cout << "So tai khoan: ";
    cout << this->accountNumber << endl;
    cout << "So cmnd : ";
    cout << this->SocialID << endl;
    cout << "So tien trong tai khoan : ";
    cout << this->Balance << endl;
}

void BankAccount::deposit(double _x)
{
    if (_x < 0)
        return;
    this->Balance += _x;
}

void BankAccount::withdraw(double _x)
{
    if (_x < 0)
        return;
    if (this->Balance - _x >= 50000)
        this->Balance -= _x;
    else
        cout << "Can not withdraw" << endl;
}

double BankAccount::checkCurBalance()
{
    return this->Balance;
}