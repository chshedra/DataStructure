#include <iostream>
#include "Common.h"
using namespace std;


int InputValidation()
{
	int number = 0;

	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "try again!\n";
		}
		else
		{
			break;
		}
	}
	return number;
}