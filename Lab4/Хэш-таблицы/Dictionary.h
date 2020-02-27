#pragma once
#include "Table.h"

//TODO: Завести структуру словаря

bool AddItem(Table** dictionary, string key, string value, int size, int &count);
bool DeleteFromDictionary(Table** dictionary, string key, int size, int &count);
void DisplayDictionary(Table** dictionary, int size);