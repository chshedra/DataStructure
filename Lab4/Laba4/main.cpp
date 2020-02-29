#include <iostream>
#include <string>
#include "HashTable.h"
#include "Dictionary.h"
#include <stdio.h>
#include <string>
using namespace std;

int InputValidation();
void HashTableMenu(HashTable** table, int size);
void DictionaryMenu(Dictionary* newDictionary, int size);

int main()
{
	setlocale(LC_ALL, "rus");
	while (true)
	{
		cout << "1.Hash-table \n"
			<< "2.Dictionary\n";
		cout << "Select the item from the menu: ";
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			cout << "Enter the size of table: ";
			int size = InputValidation();
			HashTable** table = new HashTable * [size];
			InitTable(table, size);
			HashTableMenu(table, size);
			delete[] table;
			break;
		}
		case 2:
		{
			cout << "Enter the size of table: ";
			int size = InputValidation();
			Dictionary* newDictionary = new Dictionary[size];
			InitTable(&newDictionary->dictionary, size);
			DictionaryMenu(newDictionary, size);
			delete[] newDictionary;
			break;
		}
		default:
		{
			cout << "Select the right item!" << endl;
		}
		}
		cout << "Enter the size of table: ";
		int size = InputValidation();
		HashTable** table = new HashTable * [size];
		InitTable(table, size);
		system("pause");
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

void HashTableMenu(HashTable** table, int size)
{
	int count = 0;
	while (true)
	{
		if (count / size >= 0.9)
		{
			table = Rehash(table, size);
		}
		cout << "1.Insert \n"
			<< "2.Delete\n"
			<< "3.Find\n";
		cout << "Select the item from the menu: ";
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			int hash;
			string key;
			string value;
			bool isPushed;
			cout << "Enter the key: ";
			getline(cin, key);
			cout << "Enter the value: ";
			getline(cin, value);
			isPushed = Push(size, count, key, value, table);
			if (isPushed == false)
			{
				cout << "This element had been pushed before!" << endl;;
			}
			DisplayTable(table, size);
			break;
		}
		case 2:
		{
			string key;
			bool isDeleted;
			cout << "Enter the key: ";
			getline(cin, key);
			isDeleted = DeleteItem(table, key, size, count);
			if (isDeleted == false)
			{
				cout << "Cell is empty" << endl;
			}
			else
			{
				cout << "Item has been deleted" << endl;
			}
			DisplayTable(table, size);
			break;
		}
		case 3:
		{
			int index;
			bool isFind;
			string key;
			string value;
			cout << "Enter the key: ";
			getline(cin, key);
			isFind = FindItem(table, key, value, index, size);
			if (isFind == true)
			{
				cout << "The value of key " << key << " is " << value << endl;
				cout << "Index: " << index << endl;
			}
			else
			{
				cout << "Key has not been found" << endl;
			}
			break;

		}
		default:
		{
			cout << "Выбран неверный пункт\n";
			break;
		}
		}
	}
}

void DictionaryMenu(Dictionary* newDictionary, int size)
{
	int count = 0;
	while (true)
	{
		if (count / size >= 0.9)
		{
			newDictionary->dictionary = *Rehash(&newDictionary->dictionary, size);
		}
		cout << "1.Insert \n"
			<< "2.Delete\n"
			<< "3.Find\n";
		cout << "Select the item from the menu: ";
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			int hash;
			bool isAdded;
			string key;
			string value;
			cout << "Enter the key: ";
			getline(cin, key);
			cout << "Enter the value: ";
			getline(cin, value);
			isAdded = AddItem(newDictionary, key, value, size, count);
			if (!isAdded)
			{
				cout << "This key had been used before!" << endl;
			}
			DisplayDictionary(newDictionary, size);
			break;
		}
		case 2:
		{
			string key;
			bool isDeleted;
			cout << "Enter the key: ";
			getline(cin, key);
			isDeleted = DeleteFromDictionary(newDictionary, key, size, count);
			if (isDeleted == false)
			{
				cout << "Cell is empty" << endl;
			}
			else
			{
				cout << "Item has been deleted" << endl;
			}
			DisplayTable(&newDictionary->dictionary, size);
			break;
		}
		default:
		{
			cout << "Выбран неверный пункт\n";
			break;
		}
		}
	}
}