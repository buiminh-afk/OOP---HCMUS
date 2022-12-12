#include "OfficeEmployee.h"
#include "Worker.h"
int main()
{
    Worker bui("21127105", "Bui Nguyen Nhat Minh", "Quan Go Vap", "9/11/2003", 10);
    bui.output();
    cout << bui.salary();
    return 0;
}