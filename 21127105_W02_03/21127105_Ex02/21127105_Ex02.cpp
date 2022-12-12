#include <iostream>
#include "header.h"

using namespace std;

int main() {
    Triangle ABC;
    ABC.Input();
    if (ABC.isValidTriangle()) {
        ABC.TypeOfTriangle();
    }
    ABC.CenterG();
    return 0;
}