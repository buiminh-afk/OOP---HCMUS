#include "payment.h"
#include <iomanip>

int main()
{
    payment test(150000, 2.87, 15);
    cout << "Monthly payment : " << test.MonthlyPayment() << endl;
    cout << "Total paid : " << test.total();
    return 0;
}