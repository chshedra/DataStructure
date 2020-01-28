#pragma once
#include <iostream>
#include <string>
using namespace std;


struct Table
{
	string Key;
	string Value;
	Table* Next = nullptr;
};

int Hash(string str, int m);
bool Push(int size, int &count, string str, string number, Table **table);
void InitTable(Table **table, int size);
void DisplayTable(Table **table, int size);
bool DeleteItem(Table** table, string key, int size, int &count);
bool FindItem(Table** table, string key, string &value, int &hash, int size);
Table** Rehash(Table** table, int &size);