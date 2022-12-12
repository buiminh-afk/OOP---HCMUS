#pragma once

#include <iostream>
using namespace std;

class question
{
private:
    string Q = "Hello World";
    string possibleA[4] = {
        "answer 1",
        "answer 2",
        "answer 3",
        "answer 4"};
    int A = 1;

public:
    question() = default;
    question(string, string[], int);
    int answer()
    {
        return A;
    }
    void display();
};