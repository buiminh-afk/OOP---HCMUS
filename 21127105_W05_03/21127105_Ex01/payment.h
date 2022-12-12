#pragma once

#include <cmath>
#include <iostream>
using namespace std;

class payment
{
private:
    double loan; // tiền vay
    double rate; // lãi
    int years;
    double term; // kỳ hạn
    double Payment, TotalPaid;

public:
    payment(double, double, int); // loan - rate- years
    void setLoan(double);
    void setRate(double);
    void setYears(int);

    void calcPayement();
    void calcTerm();
    double MonthlyPayment()
    {
        return Payment;
    }
    double total();
};