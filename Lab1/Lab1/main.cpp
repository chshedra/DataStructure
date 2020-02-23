#include <iostream>
#include "Menu.h"

void main()
{
    Array* dynArray = new Array;
    Menu(dynArray);
    delete dynArray;
}