#include "CItem.h"

CItem::CItem(string _name)
{
    this->name = _name;
}

CItem::CItem(string _name, long _size)
{
    this->name = _name;
    this->size = _size;
}

long CItem::getSize()
{
    return this->size;
}

bool CItem::isHidden()
{
    return this->hidden_attr;
}

string CItem::getName()
{
    return this->name;
}