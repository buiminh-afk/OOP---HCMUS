#include "CFolder.h"

CFolder::CFolder(string _name) : CItem(_name) {}

void CFolder::add(CItem *file)
{
    this->subItem.push_back(file);
}

void CFolder::print(bool hidden)
{
    // false - khong in hidden item
    for (int i = 0; i < this->subItem.size(); i++)
    {
        if (this->subItem[i]->isHidden())
        {
            if (hidden)
            {
                cout << "-> " << this->subItem[i]->getName() << endl;
            }
        }
        else
        {
            cout << "-> " << this->subItem[i]->getName() << endl;
        }
    }
}

CItem *CFolder::removeByName(string _name)
{
    CItem *tmp = NULL;
    for (int i = 0; i < this->subItem.size(); i++)
    {
        if (this->subItem[i]->getName() == _name)
        {
            tmp = this->subItem[i];
            this->subItem.erase(subItem.begin() + i);
            break;
        }
    }
    return tmp;
    delete tmp;
}

CItem *CFolder::findByName(string _name)
{
    CItem *tmp = NULL;
    for (int i = 0; i < this->subItem.size(); i++)
    {
        if (this->subItem[i]->getName() == _name)
        {
            tmp = this->subItem[i];
            break;
        }
    }
    return tmp;
    delete tmp;
}

void CFolder::setHidden(bool H, bool A)
{
    this->hidden_attr = H;
    if (A)
        for (int i = 0; i < this->subItem.size(); i++)
            this->subItem[i]->setHidden(A, A);
}