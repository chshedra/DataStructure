#include <iostream>
#include "Table.h"
using namespace std;

bool AddItem(Table** dictionary, string key, string value, int size, int &count)
{
	int hash = Hash(key, size);
	Table* tempNode = dictionary[hash];
	while (tempNode != nullptr)
	{
		if (tempNode->Key == key)
		{
			return false;
		}
		tempNode = tempNode->Next;
	}
	Push(size, count, key, value, dictionary);
	return true;
}

bool DeleteFromDictionary(Table** dictionary, string key, int size, int &count)
{
	bool isDeleted = DeleteItem(dictionary, key, size, count);
	return isDeleted;
}

void DisplayDictionary(Table** dictionary, int size)
{
	DisplayTable(dictionary, size);
}