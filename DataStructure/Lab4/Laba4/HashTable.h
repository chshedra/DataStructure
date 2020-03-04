#pragma once
#include <iostream>
#include <string>
using namespace std;

struct HashTable
{
	string Key;
	string Value;
	HashTable* Next = nullptr;
};

int CountHash(string str, int m);
bool Push(int size, int& count, string str, string number, HashTable** table);
void InitTable(HashTable** table, int size);
void DisplayTable(HashTable** table, int size);
bool DeleteItem(HashTable** table, string key, int size, int& count);
bool FindItem(HashTable** table, string key, string& value, int& hash, int size);
HashTable** Rehash(HashTable** table, int& size);