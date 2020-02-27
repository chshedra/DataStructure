#include <iostream>
#include "Menu.h"

void main()
{
    Array* dynamicArray = new Array;
    Menu(dynamicArray);
    delete dynamicArray;
}