#include <iostream>
#include "Table.h"

using namespace std;

//TODO: naming
int Hash(string str, int size)
{
	//TODO:RSDN
	double a;
	double hash = 0;
	a = (sqrt(5) - 1) / 2;
	for (int i = 0; i < str.length(); i++)
	{
		double result = pow(a, i);
		
		hash = ((int)((int)str[i] * result)) % size;
	}
	return hash;
}

void InitTable(Table** table, int size)
{
	for (int i = 0; i < size; i++)
	{
		table[i] = nullptr;
	}
}

bool Push(int size, int &count, string key, string value, Table **table)
{
	int hash;
	hash = Hash(key, size);
	Table* newNode = new Table;
	newNode->Key = key;
	newNode->Value = value;
	if (table[hash] == nullptr)
	{
		table[hash] = newNode;
	}
	else
	{
		Table* tempNode = table[hash];
		while (tempNode != nullptr)
		{
			if (tempNode->Key == key && tempNode->Value == value)
			{
				return false;
			}
			tempNode = tempNode->Next;
		}
		newNode->Next = table[hash];
		table[hash] = newNode;
	}
	count++;
	return true;
}

bool DeleteItem(Table** table, string key, int size, int &count)
{
	//TODO: почему здесь?
	int index;
	Table* current = nullptr;
	Table* prev = nullptr;
	index = Hash(key, size);
	current = table[index];
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			if ((prev == nullptr) && (current != nullptr))
			{
				table[index] = current->Next;
				Table* save = current->Next;
				delete current;
				current = save;
				count--;
			}
			else if ((prev != nullptr) && (current != nullptr))
			{
				prev->Next = current->Next;
				Table* save = current->Next;
				delete current;
				current = save;
				count--;
			}
		}
		else
		{
			prev = current;
			current = current->Next;
		}
	}
	return true;
}

bool FindItem(Table** table, string key, string &value, int &hash, int size)
{
	hash = Hash(key, size);
	if (table[hash] == nullptr)
	{
		return false;
	}
	else
	{
		Table* tempNode = table[hash];
		while (tempNode != nullptr)
		{
			if (tempNode->Key == key)
			{
				value = tempNode->Value;
				return true;
			}
		}
		return false;
	}
}

Table** Rehash(Table** table, int &size)
{
	int saveSize = size;
	size = size * 2;
	Table* tempNode = nullptr;
	Table** newTable = new Table*[size];
	InitTable(newTable, size);
	for (int i = 0; i < saveSize; i++)
	{
		tempNode = table[i];
		while (tempNode != nullptr)
		{
			table[i] = tempNode->Next;
			int index = Hash(tempNode->Key, size);
			tempNode->Next = newTable[index];
			newTable[index] = tempNode;
			tempNode = table[i];
		}
	}
	delete[] table;
	table = newTable;
	return table;
}

void DisplayTable(Table **table, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i;
		if (table[i] != nullptr)
		{
			Table* tempNode = table[i];
			while (tempNode != nullptr)
			{

				cout << "--> " << tempNode->Key << " " << tempNode->Value;
				tempNode = tempNode->Next;
			}
		}
		cout << endl;
	}
	cout << endl;
}