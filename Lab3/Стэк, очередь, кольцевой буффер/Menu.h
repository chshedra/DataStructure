#pragma once
#include "Stack.h"
#include "CircularBuffer1.h"
#include "Queue.h"
#include "QueueByBuffer.h"

int InputValidation();
void StackMenu(Stack* newStack, int stackChoise);
void QueueByStacksMenu(Queue *newQueue);
void CircularBufferMenu(CircularBuffer* buffer);
void QueueByBufferMenu(QueueByBuffer* queue);
