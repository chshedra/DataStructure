#include <iostream>
#include "Array.h"
#include "Menu.h"

using namespace std;


void Menu(Array* dynamicArray)
{
	bool isCreated = false;
	while (true)
	{
		if (isCreated != false)
		{
			PrintArray(dynamicArray);
		}

		cout << "Enter the item from the menu:" << endl
			<< "1. Fill array random" << endl
			<< "2. Fill array manually" << endl
			<< "3. Add element to the end" << endl
			<< "4. Add element to the begining" << endl
			<< "5. Add element after another element" << endl
			<< "6. Delete element" << endl
			<< "7. Search element" << endl
			<< "8.Binary search" << endl
			<< "9.Sorting array" << endl
			<< "10.Exit" << endl;


		int choice = InputValidation();
		switch (choice)
		{
			case 1:
			{
				if (!isCreated)
				{
					cout << "Enter the size of array: ";
					int size = InputValidation();
					if (size > 0)
					{
						Create(dynamicArray, size);
						GetRandom(dynamicArray, size);
						isCreated = true;
					}
					else
					{
						cout << "Enter the correct size!" << endl;
					}
				}
				else
				{
					cout << "Array has already created!" << endl;
				}
				break;

			}
			case 2:
			{
				if (!isCreated)
				{
					cout << "Enter the size of array: ";
					int size = InputValidation();
					if (size > 0)
					{
						Create(dynamicArray, size);
						GetManualy(dynamicArray, size);
						isCreated = true;
					}
					else
					{
						cout << "Enter the correct size!" << endl;
					}
				}
				else
				{
					cout << "Array has already created!" << endl;
				}
				break;
			}
			case 3:
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					cout << "Enter the value: ";
					int value = InputValidation();
					AddElem(dynamicArray, value, dynamicArray->Length);
				}
				break;
			}
			case 4:
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					cout << "Enter the value: ";
					int value = InputValidation();
					AddElem(dynamicArray, value, 0);
				}
				break;
			}
			case 5:
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					cout << "Enter the value: ";
					int value = InputValidation();
					cout << endl;
					cout << "Enter the index: ";
					int index = InputValidation();
					if (index < 0 || index > dynamicArray->Length - 1)
					{
						cout << "Enter the correct index!" << endl;
					}
					else
					{
						AddElem(dynamicArray, value, index + 1);
					}
				}
				break;
			}
			case 6:
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					cout << "Enter the index: ";
					int index = InputValidation();
					bool isDeleted = DeleteElem(dynamicArray, index);
					ShowMessage(isDeleted, index);
				}
				break;
			}
			case 7:
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					int index;
					cout << "Enter the value: ";
					int value = InputValidation();
					bool isSearched = SearchElem(dynamicArray, value, &index);
					cout << endl;
					ShowMessage(isSearched, index);
				}
			}
			case 8:
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					bool isSearched;
					int index;
					cout << "Enter the value: ";
					int value = InputValidation();
					isSearched = BinarySearch(dynamicArray, value, &index);
					cout << endl;
					ShowMessage(isSearched, index);
				}
				break;
			}
			case 9: 
			{
				if (isCreated == false)
				{
					cout << "Create the array!" << endl;
				}
				else
				{
					SortArray(dynamicArray);
				}
				break;
			}
			case 10:
			{
				return;
			}
			default:
			{
				cout << "Choose the right item!" << endl;
			}
		}
	}
}

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
			cout << "Try again!\n";
		}
		else
		{
			break;
		}
	}
	return number;
}


void ShowMessage(bool isSearched, int index)
{
	if (isSearched == true)
	{
		cout << "Element by index " << index << endl;
	}
	else
	{
		cout << "There is not element with that value" << endl;
	}
}
