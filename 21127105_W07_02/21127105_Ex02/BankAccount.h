#pragma once
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
protected:
    string accountNumber = "unknown";
    string Username = "unknown";
    string SocialID = "unknown";
    double Balance; // money in the account
public:
    BankAccount() = default;
    void input();
    void output();
    void deposit(double);
    void withdraw(double);
    double checkCurBalance();
};