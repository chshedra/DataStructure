#pragma once
#include "Node.h"
//TODO: naming
struct List
{
	Node *Head;
	Node *Tail;
	int Size = 0;
};

List* CreateList();
//TODO: naming
void InsertFront(List* newList, int value);
void InsertEnd(List *list, int value);
void DeleteNode(List* list, int index);
void InsertAfter(List *list, int value, int index);
void InsertBefore(List *list, int value, int index);
int LinearSearch(List* list, int value);
void SwapNode(List* list, Node* first, Node* second);
void SortList(List* list);
