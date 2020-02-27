#pragma once

struct Array
{
	int* Array;
	int Length;
	int Capacity;
};

//RSDN:
void Create(Array* dynamicArray, int size);
void PrintArray(Array* dynamicArray);
void GetManualy(Array* dynamicArray, int size);
void GetRandom(Array* dynamicArray, int size);
void AddElem(Array* dynamicArray, int value, int index);
bool DeleteElem(Array* dynamicArray, int index);
bool SearchElem(Array* dynamicArray, int value, int* index);
bool BinarySearch(Array* dynamicArray, int value, int* index);
void SortArray(Array* dynamicArray);