#include "BankAccount.h"
#include <math.h>
class SavingBankAccount : public BankAccount
{
private:
    double annualInterestRate = 6 / 100;
    int period = 6;
    int numberOfSavingMonths = 0;

public:
    SavingBankAccount() : BankAccount(){};
    void input();
    void output();
    void deposit(double _x);
    void withdraw(double _x);
    void withdrawImmediately(double _x);
    double curBalance();
    double curInterest();
};