#include <iostream>
#include "Stack.h"
using namespace std;

Stack* CreateStack()
{
	Stack* newStack = new Stack;
	newStack->Head = nullptr;
	newStack->Size = 0;
	newStack->Capacity = 4;
	return newStack;
}

bool Push(Stack* newStack, int value)
{
	if (newStack->Size >= newStack->Capacity)
	{
		return false;
	}
	Node* temp = new Node;
	temp->Data = value;
	temp->Next = newStack->Head;
	newStack->Head = temp;
	newStack->Size++;
	return true;
}

bool Pop(Stack* newStack, int& value)
{
	if (newStack->Head == nullptr)
	{
		return false;
	}
	Node* temp = newStack->Head;
	value = temp->Data;
	newStack->Head = newStack->Head->Next;
	temp->Next = nullptr;
	newStack->Size--;
	delete temp;
	return true;
}

void DeleteStack(Stack* newStack)
{
	while (newStack->Head != nullptr)
	{
		Node* temp = newStack->Head->Next;
		delete newStack->Head;
		newStack->Head = temp;
	}
	newStack->Capacity = 4;
	newStack->Size = 0;
}

void GrowStack(Stack* newStack)
{
	const double growFactor = 1.5;
	newStack->Capacity = newStack->Capacity * growFactor;
}

void DisplayStack(Stack* newStack)
{
	Node* temp = newStack->Head;
	while (temp != nullptr)
	{
		cout << temp->Data << " ";
		temp = temp->Next;
	}
}