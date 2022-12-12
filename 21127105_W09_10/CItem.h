#pragma once
#include <string>
#include <iostream>

using namespace std;

class CItem
{
private:
    string name;
    long size;

protected:
    bool hidden_attr = false;

public:
    CItem() = default;
    CItem(string);
    CItem(string, long);
    string getName();
    long getSize();
    bool isHidden();
    virtual void print(bool) = 0;
    virtual void setHidden(bool, bool) = 0;
};