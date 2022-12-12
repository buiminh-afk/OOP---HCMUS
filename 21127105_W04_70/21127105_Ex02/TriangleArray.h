#include "Triangle.h"
#include <vector>
class TriangleArray : public Triangle
{
private:
    Triangle *Array;
    int num;

public:
    TriangleArray();
    TriangleArray(int);
    TriangleArray(Triangle[], int);
    TriangleArray(vector<Triangle>);
    TriangleArray(string);

    int getNum()
    {
        return num;
    }
    Triangle *getArr()
    {
        return Array;
    }

    void input();
    void output();
    void LoadFromFile(string);
    void SaveToFile(string);
    void AllValidTriangle();

    double MaxArea();

    void numberOfEachType();
};