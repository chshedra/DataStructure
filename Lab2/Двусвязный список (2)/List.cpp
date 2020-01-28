#include <iostream>
#include "List.h"
using namespace std;


int LinearSearch(List* list, int value)
{
	Node* searchNode = list->Head;
	int count = 0;
	
		while(searchNode->Data != value)
		{
			searchNode = searchNode->Next;
			count++;
		}
			return count;
}

void SortList(List* list)
{
	Node* startNode = list->Head;
	Node* node;

	while (startNode->Next)
	{
		node = list->Tail;
		while (node != startNode)
		{
			if (node->Prev->Data > node->Data)
			{
				if (startNode == node->Prev) startNode = node;
				SwapNode(list, node->Prev, node);
			}
			else
			{
				node = node->Prev;
			}
		}
		startNode = startNode->Next;
	}
}

void SwapNode(List* list, Node* first, Node* second)
{
	if (first->Prev)
	{
		first->Prev->Next = second;
	}
	else
	{
		list->Head = second;
	}

	if (second->Next)
	{
		second->Next->Prev = first;
	}
	else
	{
		list->Tail = first;
	}
	first->Next = second->Next;
	second->Prev = first->Prev;
	first->Prev = second;
	second->Next = first;
}


List *CreateList()
{
	List *newList = new List;
	newList->Head = nullptr;
	newList->Tail = nullptr;
	newList->Size = 0;
	return newList;
}


void InsertFront(List *list, int Data)
{
	Node* newItem;
	newItem = new Node;
	if (list->Head == nullptr)
	{
		list->Head = newItem;
		newItem->Prev = nullptr;
		newItem->Data = Data;
		newItem->Next = nullptr;
		list->Tail = newItem;
		list->Size++;
	}
	else
	{
		newItem->Next = list->Head;
		newItem->Data = Data;
		newItem->Prev = nullptr;
		list->Head->Prev = newItem;
		list->Head = newItem;
		list->Size++;
	}
}

void InsertEnd(List *list, int Data)
{
	Node* newItem = new Node;
	newItem->Data = Data;
	if (list->Head == nullptr)
	{
		list->Head = newItem;
		newItem->Prev = nullptr;
		newItem->Next = nullptr;
		list->Tail = newItem;
		list->Size++;
	}
	else
	{
		newItem->Prev = list->Tail;
		list->Tail->Next = newItem;
		newItem->Next = nullptr;
		list->Tail = newItem;
		list->Size++;
	}
}

void InsertAfter(List *list, int value, int index)
{
	int count = -1;
	Node* newItem = new Node;
	Node* tempNode = list->Head;
	newItem->Data = value;
	while (count < index)
	{
		tempNode = tempNode->Next;
		count++;
	}
	if (tempNode == nullptr)
	{
		newItem->Prev = list->Tail;
		list->Tail->Next = newItem;
		newItem->Next = nullptr;
		list->Tail = newItem;
		list->Size++;
	}
	else
	{
		tempNode->Prev->Next = newItem;
		newItem->Prev = tempNode->Prev;
		newItem->Next = tempNode;
		tempNode->Prev = newItem;
		list->Size++;
	}
}


void InsertBefore(List *list, int value, int index)
{
	int count = 0;
	Node* newItem = new Node;
	Node* tempNode = list->Head;
	newItem->Data = value;

	while (count < index)
	{
		tempNode = tempNode->Next;
		count++;
	}
	if (count == 0)
	{
		newItem->Next = list->Head;
		list->Head->Prev = newItem;
		newItem->Prev = nullptr;
		list->Head = newItem;
		list->Size++;
	}
	else
	{
		tempNode->Prev->Next = newItem;
		newItem->Next = tempNode;
		newItem->Prev = tempNode->Prev;
		tempNode->Prev = newItem;
		list->Size++;
	}
}


void DeleteNode(List* list, int index)
{
	int count = 0;
	Node* delNode = list->Head;
	if (list->Size == 1)
	{
		list->Head = nullptr;
		list->Tail = nullptr;
		list->Size = 0;
		list = CreateList();
		return;
	}
	while (count < index)
	{
		delNode = delNode->Next;
		count++;
	}
	if (count == 0)
	{
		list->Head = delNode->Next;
		list->Head->Prev = nullptr;
	}
	else if (count == list->Size)
	{
		list->Tail = delNode->Prev;
		list->Tail->Next = nullptr;
	}
	else
	{
		delNode->Prev->Next = delNode->Next;
		delNode->Next->Prev = delNode->Prev;
	}
	delete delNode;
	list->Size--;
}