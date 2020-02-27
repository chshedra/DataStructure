#include <iostream>
#include "HashTable.h"

using namespace std;

int CountHash(string str, int size)
{
	double number;
	double hash = 0;
	number = (sqrt(5) - 1) / 2;
	for (int i = 0; i < str.length(); i++)
	{
		double result = pow(number, i);

		hash = ((int)((int)str[i] * result)) % size;
	}
	return hash;
}

void InitTable(HashTable** table, int size)
{
	for (int i = 0; i < size; i++)
	{
		table[i] = nullptr;
	}
}

bool Push(int size, int& count, string key, string value, HashTable** table)
{
	int hash;
	hash = CountHash(key, size);
	HashTable* newNode = new HashTable;
	newNode->Key = key;
	newNode->Value = value;
	if (table[hash] == nullptr)
	{
		table[hash] = newNode;
	}
	else
	{
		HashTable* tempNode = table[hash];
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

bool DeleteItem(HashTable** table, string key, int size, int& count)
{
	HashTable* current = nullptr;
	HashTable* prev = nullptr;
	int index = CountHash(key, size);
	current = table[index];
	while (current != nullptr)
	{
		if (current->Key == key)
		{
			if ((prev == nullptr) && (current != nullptr))
			{
				table[index] = current->Next;
				HashTable* save = current->Next;
				delete current;
				current = save;
				count--;
			}
			else if ((prev != nullptr) && (current != nullptr))
			{
				prev->Next = current->Next;
				HashTable* save = current->Next;
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

bool FindItem(HashTable** table, string key, string& value, int& hash, int size)
{
	hash = CountHash(key, size);
	if (table[hash] == nullptr)
	{
		return false;
	}
	else
	{
		HashTable* tempNode = table[hash];
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

HashTable** Rehash(HashTable** table, int& size)
{
	int saveSize = size;
	size = size * 2;
	HashTable* tempNode = nullptr;
	HashTable** newTable = new HashTable * [size];
	InitTable(newTable, size);
	for (int i = 0; i < saveSize; i++)
	{
		tempNode = table[i];
		while (tempNode != nullptr)
		{
			table[i] = tempNode->Next;
			int index = CountHash(tempNode->Key, size);
			tempNode->Next = newTable[index];
			newTable[index] = tempNode;
			tempNode = table[i];
		}
	}
	delete[] table;
	table = newTable;
	return table;
}

void DisplayTable(HashTable** table, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i;
		if (table[i] != nullptr)
		{
			HashTable* tempNode = table[i];
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