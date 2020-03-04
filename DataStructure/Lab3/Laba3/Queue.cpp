#include <iostream>
#include "Queue.h"

void CreateQueue(Queue* newQueue)
{
	newQueue->First = CreateStack();
	newQueue->Second = CreateStack();
}

//добавление элемента в очередь
bool Enqueue(Queue* newQueue, int& value)
{
	bool isOverflow;
	if (newQueue->First->Size
		+ newQueue->Second->Size
		== newQueue->First->Capacity)
	{
		isOverflow = false;
	}
	else
	{
		isOverflow = Push(newQueue->First, value);
	}
	return isOverflow;
}

bool DeQueue(Queue* newQueue, int& value)
{
	bool isEmpty;
	if (newQueue->First->Head == nullptr && newQueue->Second->Head == nullptr)
	{
		return false;
	}
	if (newQueue->Second->Head == nullptr) {
		while (newQueue->First->Head != nullptr) {
			isEmpty = Pop(newQueue->First, value);
			Push(newQueue->Second, value);
		}
	}
	isEmpty = Pop(newQueue->Second, value);
	return isEmpty;
}

void ClearQueue(Queue* newQueue)
{
	DeleteStack(newQueue->First);
	DeleteStack(newQueue->Second);
}

void GrowQueue(Queue* newQueue)
{
	GrowStack(newQueue->First);
	GrowStack(newQueue->Second);
}

void DisplayQueue(Queue* newQueue)
{
	if (newQueue->Second->Head == nullptr)
	{
		DisplayStack(newQueue->First);
	}
	else
	{
		DisplayStack(newQueue->Second);
		DisplayStack(newQueue->First);
	}
}