#include <iostream>
#include <ctime>
#include "Array.h"
#include "Menu.h"


using namespace std;



void Create(Array* dynArray, int size)
{
	dynArray->length = 0;
	dynArray->capacity = size;
	dynArray->array = new int[dynArray->capacity];
}

void GetRandom(Array* dynArray, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		dynArray->array[i] = rand() % 100;
		dynArray->length++;
	}
}

void GetManualy(Array* dynArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynArray->array[i] = InputValidation();
		dynArray->length++;
	}
}

void Resize(Array* dynArray)
{
	if (dynArray->length >= dynArray->capacity)
	{
		//TODO: вынести в константу
		dynArray->capacity = dynArray->capacity * 1.5;
	}

	int* newArray = new int[dynArray->capacity];

	for (int i = 0; i < dynArray->length; i++)
	{
		newArray[i] = dynArray->array[i];
	}

	delete[] dynArray->array;
	dynArray->array = newArray;
}

void AddElem(Array* dynArray, int value, int index)
{
	if (dynArray->capacity == dynArray->length)
	{
		Resize(dynArray);
	}
	for (int i = dynArray->length + 1; i > index; i--)
	{
		dynArray->array[i] = dynArray->array[i - 1];
	}
	dynArray->array[index] = value;
	dynArray->length++;
}

bool DeleteElem(Array* dynArray, int index)
{
	if (dynArray->length - 1 < index || index < 0)
	{
		return false;
	}

	for (int i = index; i < dynArray->length; i++)
	{
		dynArray->array[i] = dynArray->array[i +1];
	}
	dynArray->length--;
	return true;
}

bool SearchElem(Array* dynArray, int value, int* index)
{
	for (int i = 0; i < dynArray->length; i++)
	{
		if (dynArray->array[i] == value)
		{
			*index = i;
			return true;
		}
	}
	return false;
}

bool BinarySearch(Array* dynArray, int value, int* index)
{
	int first = 0;
	int last = dynArray->length;
	int mid;

	while (first < last)
	{
		mid = (last + first) / 2;
		if (value <= dynArray->array[mid])
		{
			last = mid;
		}
		else
		{
			first = mid + 1;
		}
	}
	if (dynArray->array[first] == value)
	{
		*index = first;
		return true;
	}
	else
	{
		return false;
	}
}

void SortArray(Array* dynArray)
{
	int i, j;
	for (i = 0; i < dynArray->length - 1; i++)
  
		for (j = 0; j < dynArray->length- i - 1; j++)
			if (dynArray->array[j] > dynArray->array[j + 1])
			{
				int temp = dynArray->array[j];
				dynArray->array[j] = dynArray->array[j + 1];
				dynArray->array[j + 1] = temp;
			}
}

void PrintArray(Array* dynArray)
{
	for (int i = 0; i < dynArray->length; i++)
	{
		cout << dynArray->array[i] << " ";
	}
	cout << endl;
}