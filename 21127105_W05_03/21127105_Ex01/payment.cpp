#include "payment.h"

payment::payment(double _loan, double _rate, int _years)
{
    this->loan = _loan;
    this->rate = _rate / 100;
    this->years = _years;
    this->calcPayement();
}

void payment::setLoan(double _loan)
{
    this->loan = _loan;
    this->calcPayement();
}

void payment::setYears(int _years)
{
    this->years = _years;
    this->calcPayement();
}

void payment::setRate(double _rate)
{
    this->rate = _rate / 100;
    this->calcPayement();
}

void payment::calcPayement()
{
    this->calcTerm();
    double tu = (this->loan * (this->rate / 12) * this->term);
    double mau = this->term - 1;
    this->Payment = tu / mau;
}

void payment::calcTerm()
{
    this->term = pow((1 + this->rate / 12), 12 * this->years);
}

double payment::total()
{
    this->TotalPaid = this->Payment * this->years * 12;
    return TotalPaid;
}