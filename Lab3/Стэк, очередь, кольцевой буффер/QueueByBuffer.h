#pragma once
#include "CircularBuffer1.h"

struct QueueByBuffer
{
	CircularBuffer *Queue;
};

bool GrowQueue(QueueByBuffer* queue);
void CreateQueueByBuffer(QueueByBuffer* queue);
void EnqueueItem(QueueByBuffer* queue, int value);
bool DequeueItem(QueueByBuffer* queue, int &value);
void DisplayQueueByBuffer(QueueByBuffer* queue);
void DeleteQueue(QueueByBuffer* queue);
