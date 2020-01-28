#pragma once
#include"Stack.h"

struct Queue
{
	Stack* First;
	Stack* Second;
};


void CreateQueue(Queue *newQueue);
bool Enqueue(Queue* newQueue, int &value);
bool DeQueue(Queue *newQueue, int &isEmpty);
void ClearQueue(Queue* newQueue);
void GrowQueue(Queue* newQueue);