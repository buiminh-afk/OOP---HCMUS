#pragma once
#include <iostream>
#include "Gate.h"
#include <vector>

using namespace std;

class Castle
{
private:
    vector<Gate *> a;

public:
    void nhapDS();
    bool cuuCongChua(Prince &);
};