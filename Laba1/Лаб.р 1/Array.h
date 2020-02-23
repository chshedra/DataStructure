#pragma once

struct Dynamic
{
	int* array;
	int length;
	int capacity;
};

void Create(Dynamic* dynArray);
void ArrayShow(Dynamic* dynArray);
void ArrayGetAuto(Dynamic* dynArray, int lenght);
void ArrayGetManually(Dynamic* dynArray, int lenght);
void Resize(Dynamic* dynArray);
void AddElement(Dynamic* dynArray, int value, int index);
void DeleteElement(Dynamic* dynArray, int index);
void PushElement(Dynamic* dynArray, int value, int index);
void Sort(Dynamic* dynArray);
void Search(Dynamic* dynArray, int value);
void BinarySearch(Dynamic* dynArray, int value);
bool ArrayValidation(bool isArrayCreated);
int InputValidation(int value);
#pragma once
