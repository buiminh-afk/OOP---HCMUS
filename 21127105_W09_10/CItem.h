#pragma once
#include <string>
#include <iostream>

using namespace std;

class CItem
{
protected:
    string name;
    long size;
    bool hidden_attr = false;

public:
    CItem() = default;
    CItem(string);
    CItem(string, long);
    string getName();
    long getSize();
    bool isHidden();
    virtual CItem *removeByName(string) = 0;
    virtual CItem *findByName(string) = 0;
    virtual void print(bool) = 0;
    virtual void setHidden(bool, bool) = 0;
    virtual long calcSize() = 0;
};