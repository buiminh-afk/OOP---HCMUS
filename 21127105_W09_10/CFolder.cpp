#include "CFolder.h"

CFolder::CFolder(string _name) : CItem(_name) {}

void CFolder::add(CItem *file)
{
    this->subItem.push_back(file);
}

void CFolder::print(bool hidden)
{
    // false - khong in hidden item
    if (hidden_attr == hidden)
        return;
    cout << this->name << "-> " << endl;
    for (int i = 0; i < this->subItem.size(); i++)
    {
        this->subItem[i]->print(hidden);
        // if (this->subItem[i]->isHidden())
        // {
        //     if (hidden)
        //     {
        //         cout << "-> " << this->subItem[i]->getName() << endl;
        //     }
        // }
        // else
        // {
        //     cout << "-> " << this->subItem[i]->getName() << endl;
        // }
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
        tmp = this->subItem[i]->removeByName(_name);
        if (tmp != NULL)
            break;
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
        tmp = this->subItem[i]->findByName(_name);
        if (tmp != NULL)
            break;
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

long CFolder::calcSize()
{
    size = 0;
    for (int i = 0; i < this->subItem.size(); i++)
    {
        size += this->subItem[i]->calcSize();
    }
    return size;
}