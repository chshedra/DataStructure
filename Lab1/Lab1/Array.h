#pragma once

struct Array
{
	//RSDN:
	int* array;
	int length;
	int capacity;
};

//RSDN:
void Create(Array* dynArray, int size);
void PrintArray(Array* dynArray);
void GetManualy(Array* dynArray, int size);
void GetRandom(Array* dynArray, int size);
void AddElem(Array* dynArray, int value, int index);
bool DeleteElem(Array* dynArray, int index);
bool SearchElem(Array* dynArray, int value, int* index);
bool BinarySearch(Array* dynArray, int value, int* index);
void SortArray(Array* dynArray);