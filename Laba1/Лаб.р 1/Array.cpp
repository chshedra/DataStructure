#include "Array.h"
#include <ctime>
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

void Create(Dynamic* dynArray)
{
	int size = 4;
	dynArray->length = 0;
	dynArray->capacity = size;
	dynArray->array = new int[dynArray->capacity];
}

//добавить случайные значени€
void ArrayGetAuto(Dynamic *dynArray, int lenght)
{
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
	{
		AddElement(dynArray, rand() % 41 - 20, i);
	}
}

//ввести элементы вручную
void ArrayGetManually(Dynamic *dynArray, int lenght)
{
	if (lenght >= dynArray->capacity)
	{
		Resize(dynArray);
	}

	for (int i = 0; i < lenght; i++)
	{
		dynArray->length++;
		cout << "¬ведите " << i + 1 << " элемент массива: ";
		cin >> dynArray->array[i];
		cout << endl;
	}

}

//вывод массива на экран
void ArrayShow(Dynamic* dynArray)
{
	cout << "Ќомер элемента: ";
	for (int i = 1; i < dynArray->length + 1; i++)
	{
		cout << i << "\t";
	}
	cout << "\nЁлемент: \t";
	for (int i = 0; i < dynArray->length; i++)
	{
		cout  << dynArray->array[i] << "\t";
	}
	cout << "\n\n";
}

//увеличение размера массива
void Resize(Dynamic* dynArray)
{
	if (dynArray->length == (dynArray->capacity / 2) - 1 &&
		dynArray->capacity > 4)
	{
		dynArray->capacity /= 2;
	}
	if (dynArray->length >= dynArray->capacity)
	{
		dynArray->capacity = dynArray->capacity + 10;
	}

	int* temp_array = new int[dynArray->capacity];

	for (int i= 0; i < dynArray->length; i++)
	{
		temp_array[i] = dynArray->array[i];
	}
	
	delete[] dynArray->array;
	dynArray->array = temp_array;
}

//добавление элемента
void AddElement(Dynamic* dynArray, int value, int index)
{
	dynArray->length++;

	if (dynArray->length >= dynArray->capacity)
	{
		Resize(dynArray);
	}

	for (int i = dynArray->length - 1; i > index; i--)
	{
		dynArray->array[i] = dynArray->array[i - 1];
	}

	dynArray->array[index] = value;
}

//удаление элемнта из массива
void DeleteElement(Dynamic* dynArray, int index)
{
	for (int i = index - 1; i < dynArray->length - 1; i++)
	{
		dynArray->array[i] = dynArray->array[i + 1];
	}
	dynArray->length--;

	if (dynArray->length == (dynArray->capacity / 2) - 1 &&
		dynArray->capacity > 4)
	{
		Resize(dynArray);
	}
}

//вставка элемента на определенное место
void PushElement(Dynamic* dynArray, int value, int index)
{
	dynArray->length += 1;
	if (dynArray->length >= dynArray->capacity)
	{
		Resize(dynArray);
	}
	for (int i = dynArray->length; i > index; i--)
	{
		dynArray->array[i] = dynArray->array[i - 1];
	}
	dynArray->array[index] = value;
}


void Sort(Dynamic* dynArray)
{
	int temp = 0;
	bool flag = true;

	while (flag==true)
	{
		flag = false;
		for (int i = 0; i < (dynArray->length - 1); i++)
		{
			
			if (dynArray->array[i] > dynArray->array[i + 1])
			{
				temp = dynArray->array[i];
				dynArray->array[i] = dynArray->array[i + 1];
				dynArray->array[i + 1] = temp;
				flag = true;
			}
		}
	}
}

void Search(Dynamic* dynArray, int value)
{ 
	bool flag = false;
	for (int i = 0; i < dynArray->length; i++)
	{
		if (dynArray->array[i] == value)
		{
			flag = true;
			cout << "\n\t\t\tЁлемент найден "
				<< "номер элемента: " << i + 1<<endl;
		}
	}
	if (flag == false)
	{
		cout << "\n\t\t\tЁлемент не найден.\n";
	}
}


void BinarySearch(Dynamic* dynArray, int value)
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
		cout << "\n\t\t\tЁлемент найден, номер элемента " << first + 1<<endl;
	}
	else
	{
		cout << "\n\t\t\tЁлемент не найден."<<endl;
	}
}

//проверка создани€ массива
bool ArrayValidation(bool isArrayCreated)
{
	if (isArrayCreated == false)
	{
		system("cls");
		cout << "\t\t\tћассив не создан! "
			<<"—оздайте массив. (ѕункт меню 1)"<<endl;
		system("pause");
		return false;
	}
}

//прорверка входных данных
int InputValidation(int value) 
{
	while (true) 
	{
		cin >> value;
		
		if (cin.fail()) 
		{
			cin.clear(); 
			cin.ignore(32767, '\n'); 
			cout << "\t\t\tќшибка, повторите попытку\n";
		}
		else
		{
			cin.ignore(32767, '\n'); 
			return value;
		}
	}
}