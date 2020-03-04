#pragma once
#include "Stack.h"
#include "CircularBuffer.h"
#include "Queue.h"
#include "QueueByBuffer.h"

void StackMenu(Stack* newStack, int stackChoise);
void QueueByStacksMenu(Queue* newQueue);
void CircularBufferMenu(CircularBuffer* buffer);
void QueueByBufferMenu(QueueByBuffer* queue);
