#include <iostream>
#include <ctime>
#include "Array.h"
#include "Menu.h"


using namespace std;



void Create(Array* dynamicArray, int size)
{
	dynamicArray->Length = 0;
	dynamicArray->Capacity = size;
	dynamicArray->Array = new int[dynamicArray->Capacity];
}

void GetRandom(Array* dynamicArray, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		dynamicArray->Array[i] = rand() % 100;
		dynamicArray->Length++;
	}
}

void GetManualy(Array* dynamicArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArray->Array[i] = InputValidation();
		dynamicArray->Length++;
	}
}

void Resize(Array* dynamicArray)
{
	if (dynamicArray->Length >= dynamicArray->Capacity)
	{
		const double growFactor = 1.5;
		dynamicArray->Capacity = dynamicArray->Capacity * growFactor;
	}

	int* newArray = new int[dynamicArray->Capacity];

	for (int i = 0; i < dynamicArray->Length; i++)
	{
		newArray[i] = dynamicArray->Array[i];
	}

	delete[] dynamicArray->Array;
	dynamicArray->Array = newArray;
}

void AddElem(Array* dynamicArray, int value, int index)
{
	if (dynamicArray->Capacity == dynamicArray->Length)
	{
		Resize(dynamicArray);
	}
	for (int i = dynamicArray->Length + 1; i > index; i--)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i - 1];
	}
	dynamicArray->Array[index] = value;
	dynamicArray->Length++;
}

bool DeleteElem(Array* dynamicArray, int index)
{
	if (dynamicArray->Length - 1 < index || index < 0)
	{
		return false;
	}

	for (int i = index; i < dynamicArray->Length; i++)
	{
		dynamicArray->Array[i] = dynamicArray->Array[i +1];
	}
	dynamicArray->Length--;
	return true;
}

bool SearchElem(Array* dynamicArray, int value, int* index)
{
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		if (dynamicArray->Array[i] == value)
		{
			*index = i;
			return true;
		}
	}
	return false;
}

bool BinarySearch(Array* dynamicArray, int value, int* index)
{
	int first = 0;
	int last = dynamicArray->Length;
	int mid;

	while (first < last)
	{
		mid = (last + first) / 2;
		if (value <= dynamicArray->Array[mid])
		{
			last = mid;
		}
		else
		{
			first = mid + 1;
		}
	}
	if (dynamicArray->Array[first] == value)
	{
		*index = first;
		return true;
	}
	else
	{
		return false;
	}
}

void SortArray(Array* dynamicArray)
{
	int i, j;
	for (i = 0; i < dynamicArray->Length - 1; i++)
  
		for (j = 0; j < dynamicArray->Length- i - 1; j++)
			if (dynamicArray->Array[j] > dynamicArray->Array[j + 1])
			{
				int temp = dynamicArray->Array[j];
				dynamicArray->Array[j] = dynamicArray->Array[j + 1];
				dynamicArray->Array[j + 1] = temp;
			}
}

void PrintArray(Array* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		cout << dynamicArray->Array[i] << " ";
	}
	cout << endl;
}