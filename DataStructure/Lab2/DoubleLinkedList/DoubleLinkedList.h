#pragma once
#include "Node.h"

struct DoubleLinkedList
{
	Node *Head;
	Node *Tail;
	int Size = 0;
};

DoubleLinkedList* CreateList();

void InsertFront(DoubleLinkedList* list, int value);
void InsertEnd(DoubleLinkedList *list, int value);
void DeleteNode(DoubleLinkedList* list, int index);
void InsertAfter(DoubleLinkedList *list, int value, int index);
void InsertBefore(DoubleLinkedList *list, int value, int index);
int LinearSearch(DoubleLinkedList* list, int value);
void SwapNode(DoubleLinkedList* list, Node* first, Node* second);
void SortList(DoubleLinkedList* list);
