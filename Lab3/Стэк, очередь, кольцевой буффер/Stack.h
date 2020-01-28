#pragma once
#include "Node.h"
struct Stack
{
	int Data;
	Node *Head;
	Node *Next;
	int Capacity;
	int Size;
};

Stack* CreateStack();
bool Push(Stack *newStack, int value);
bool Pop(Stack* stack, int &value);
void DisplayStack(Stack *stack);
void DeleteStack(Stack* stack);
void GrowStack(Stack* newStack);
void DisplayStack(Stack *newStack);