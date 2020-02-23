#include <iostream>
#include "Array.h"
#include <Windows.h>
#include <stdlib.h>
#include "Menu.h"

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dynamic *dynArray = new Dynamic;

	Menu(dynArray);

	delete[] dynArray->array;
	delete  dynArray;
}