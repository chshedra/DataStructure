#include <iostream>
#include "HashTable.h"
#include "Dictionary.h"
using namespace std;

bool AddItem(Dictionary* newDictionary, string key, string value, int size, int& count)
{
	int hash = CountHash(key, size);
	Dictionary* tempNode = new Dictionary[hash];
	while (tempNode != nullptr)
	{
		if (tempNode->dictionary->Key == key)
		{
			return false;
		}
		tempNode->dictionary = tempNode->dictionary->Next;
	}
	Push(size, count, key, value, &newDictionary->dictionary);
	return true;
}

bool DeleteFromDictionary(Dictionary* dictionary, string key, int size, int& count)
{
	bool isDeleted = DeleteItem(&dictionary->dictionary, key, size, count);
	return isDeleted;
}

void DisplayDictionary(Dictionary* dictionary, int size)
{
	DisplayTable(&dictionary->dictionary, size);
}