#pragma once
#include "CItem.h"
#include "CFile.h"
#include <vector>
#include <algorithm>

class CFolder : public CItem
{
private:
    vector<CItem *> subItem;

public:
    CFolder() : CItem(){};
    CFolder(string);
    ~CFolder() = default;
    void add(CItem *);
    void print(bool);
    CItem *removeByName(string);
    CItem *findByName(string);
    void setHidden(bool, bool);
};