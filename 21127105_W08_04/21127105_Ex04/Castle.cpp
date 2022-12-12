#include "Castle.h"
void Castle::nhapDS()
{
    int number, opt;
    Gate *temp;
    cout << "Nhap so cong : ";
    cin >> number;
    cout << "0. Cong giao thuong" << endl
         << "1. Cong hoc thuat" << endl
         << "2. Cong suc manh" << endl;
    for (int i = 0; i < number; i++)
    {
        cout << "-----------------------" << endl;
        cout << "Nhap loai cong (0-2) : ";
        cin >> opt;
        switch (opt % 3 + 1)
        {
        case 1:
            temp = new BusinessGate;
            break;
        case 2:
            temp = new AcademicGate;
            break;
        case 3:
            temp = new PowerGate;
            break;
        default:
            cout << "Loi nhap cong : ";
            break;
        }
        temp->nhap();
        a.push_back(temp);
    }
}

bool Castle::cuuCongChua(Prince &bui)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (!a[i]->quaCong(bui))
            return false;
    }
    return true;
}