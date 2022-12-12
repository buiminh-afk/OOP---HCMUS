#pragma once
#include <iostream>
#include "CItem.h"
#include <string>

using namespace std;

class CFile : public CItem
{
private:
    bool read_only_attr;

public:
    CFile() : CItem(){};
    CFile(string, long);
    ~CFile() = default;
    void print(bool);
    void setHidden(bool);
    void setHidden(bool A, bool B) { this->hidden_attr = A; };
};