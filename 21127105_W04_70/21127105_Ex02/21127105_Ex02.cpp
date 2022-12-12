#include "Point.h"
#include "Triangle.h"
#include "TriangleArray.h"
int main()
{
    Triangle test;
    test.LoadFromFile("input.txt");
    test.SaveToFile("output.txt");
    // TriangleArray test;
    // test.LoadFromFile("input.txt");
    // test.SaveToFile("output.txt");
    // test.AllValidTriangle();
    // cout << test.MaxArea() << endl;
    // test.numberOfEachType();
    return 0;
}