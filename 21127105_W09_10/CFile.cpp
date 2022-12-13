#include "CFile.h"

CFile::CFile(string _name, long _size) : CItem(_name, _size) {}

void CFile::setHidden(bool _hidden)
{
    this->hidden_attr = _hidden;
}

void CFile::print(bool _print)
{
    if (this->hidden_attr)
    {
        if (_print)
        {
            cout << this->getName() << endl;
            return;
        }
    }
    cout << this->getName() << endl;
}

long CFile::calcSize()
{
    return this->size;
}

CItem *CFile::removeByName(string _name)
{
    return _name == name ? this : nullptr;
}

CItem *CFile::findByName(string _name)
{
    return _name == name ? this : nullptr;
}