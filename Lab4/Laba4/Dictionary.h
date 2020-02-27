#pragma once
#include "HashTable.h"

struct Dictionary
{
	HashTable* dictionary;
};


bool AddItem(Dictionary* dictionary, string key, string value, int size, int& count);
bool DeleteFromDictionary(Dictionary* dictionary, string key, int size, int& count);
void DisplayDictionary(Dictionary* dictionary, int size);