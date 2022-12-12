#include "question.h"

void question::display()
{
    cout << this->Q << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << 1 + i << ") " << possibleA[i] << endl;
    }
}

question::question(string question, string ans[], int a)
{
    this->Q = question;
    for (int i = 0; i < 4; i++)
        possibleA[i] = ans[i];
    this->A = a;
}