#include "CFile.h"
#include "CFolder.h"

int main()
{
    CFolder C("C");
    CFolder System("System");
    CFolder Windows("Windows");
    CFile a_txt("a.txt", 123);
    CFile b_doc("b.doc", 456);
    ////////////////////////////
    System.add(&a_txt);
    System.add(&b_doc);
    Windows.add(&b_doc);
    C.add(&System);
    C.add(&Windows);
    ////////////////////////////
    cout << "Content of folder C -> " << endl;
    bool isPrintHiddenItems = false;
    C.print(isPrintHiddenItems);
    ////////////////////////////
    CItem *p = C.removeByName("b.doc");
    cout << "-------------------------------------------" << endl;
    cout << "Content of folder C after removing b.doc ->" << endl;
    C.print(false);
    cout << "-------------------------------------------" << endl;
    ////////////////////////////
    p = C.findByName("b.doc");
    if (p != NULL)
    {
        cout << "b.doc is found in folder C" << endl;
    }
    else
    {
        cout << "b.doc is not found" << endl;
    }
    ////////////////////////////
    cout << "-------------------------------------------" << endl;
    p = C.findByName("a.txt");
    if (p != NULL)
    {
        cout << "a.txt is found in folder C" << endl;
    }
    else
    {
        cout << "a.txt is not found" << endl;
    }
    cout << "-------------------------------------------" << endl;
    ////////////////////////////
    p = C.findByName("Windows");
    bool isHidden;
    bool isAlsoApplyToChildren;
    if (p != NULL)
    {
        cout << "Folder Windows is folder. Content of folder Windows ->" << endl;
        // set HIDDEN to folder p and do not change hidden attributes of its sub-items
        isHidden = true;
        isAlsoApplyToChildren = false;
        p->setHidden(isHidden, isAlsoApplyToChildren);
        p->print(true);
        cout << "-------------------------------------------" << endl;

        cout << "Folder Windows is folder. Content of folder Windows ->" << endl;
        // set HIDDEN to folder p and all its items
        isHidden = true;
        isAlsoApplyToChildren = true;
        p->setHidden(isHidden, isAlsoApplyToChildren);
        p->print(false);
    }
    else
    {
        cout << "Folder Windows is not found" << endl;
    }

    return 0;
}