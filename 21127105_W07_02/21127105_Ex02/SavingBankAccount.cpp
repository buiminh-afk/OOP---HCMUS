#include "SavingBankAccount.h"

void SavingBankAccount::input()
{
    BankAccount::input();
    cout << "Nhap lai suat hang nam : ";
    cin >> this->annualInterestRate;
    cout << "Nhap ky hang : ";
    cin >> this->period;
    cout << "Nhap so thang tiet kiem : ";
    cin >> this->numberOfSavingMonths;
}

void SavingBankAccount::output()
{
    BankAccount::output();
    cout << "Lai suat hang nam : " << this->annualInterestRate << endl;
    cout << "Ky hang : " << this->period << endl;
    cout << "So thang tiet kiem : " << this->numberOfSavingMonths << endl;
}

void SavingBankAccount::deposit(double _x)
{
    Balance = curBalance();
    char opt;
    if (numberOfSavingMonths < period)
    {
        cout << "Cannot deposit" << endl;
        cout << "Do you want to create new saving account to store new amout of money (Y/N) : ";
        cin >> opt;
        cin.ignore();
        if (opt == 'y')
        {
            cout << "New account has been created" << endl;
            SavingBankAccount *newAccount = new SavingBankAccount;
            *this = *newAccount;
            this->input();
            this->deposit(_x);
            delete newAccount;
        }
        else
        {
            cout << "Bye" << endl;
        }
    }
    else
        Balance += _x;
}

void SavingBankAccount::withdraw(double _x)
{
    Balance = curBalance();
    if (numberOfSavingMonths < period)
        cout << "Canont withdraw" << endl;
    else
        Balance -= _x;
}

void SavingBankAccount::withdrawImmediately(double _x)
{
    this->annualInterestRate = 2 / 100;
    Balance *= pow((1 + annualInterestRate), numberOfSavingMonths / 12);
}

double SavingBankAccount::curBalance()
{
    return Balance * pow((1 + annualInterestRate), numberOfSavingMonths / 12);
}

double SavingBankAccount::curInterest()
{
    return annualInterestRate;
}