#include <iostream>
#include "QueueByBuffer.h"

using namespace std;

void CreateQueueByBuffer(QueueByBuffer* queue)
{
	queue->Queue = CreateBuffer();
}

void EnqueueItem(QueueByBuffer* queue, int value)
{
	if (queue->Queue->Size == queue->Queue->Capacity)
	{
		if (queue->Queue->WritePoint <= queue->Queue->ReadPoint)
		{

			CircularBuffer* tempBuffer = CreateBuffer();
			tempBuffer->Capacity = queue->Queue->Capacity;
			int count = 0;
			for (int i = queue->Queue->ReadPoint; i < queue->Queue->Capacity; i++)
			{
				tempBuffer->Buffer[count] = queue->Queue->Buffer[i];
				count++;
			}
			for (int i = 0; i < queue->Queue->WritePoint; i++)
			{
				tempBuffer->Buffer[count] = queue->Queue->Buffer[i];
				count++;
			}
			queue->Queue->Buffer = tempBuffer->Buffer;
			queue->Queue->ReadPoint = 0;
			queue->Queue->WritePoint = queue->Queue->Capacity;
			delete tempBuffer;
		}
		GrowQueue(queue);
	}
	WriteItem(queue->Queue, value);

}

bool DequeueItem(QueueByBuffer* queue, int& value)
{
	return ReadItem(queue->Queue, value);
}

void DeleteQueue(QueueByBuffer* queue)
{
	queue->Queue->Capacity = 8;
	queue->Queue->Size = 0;
	queue->Queue->ReadPoint = queue->Queue->WritePoint = 0;
	queue->Queue->IsFull = false;
}

void DisplayQueueByBuffer(QueueByBuffer* queue)
{
	cout << "Write: " << queue->Queue->WritePoint << endl;
	cout << "Read: " << queue->Queue->ReadPoint << endl;
	if (queue->Queue->Capacity == queue->Queue->Size)
	{
		for (int i = 0; i < queue->Queue->Capacity; i++)
		{
			cout << queue->Queue->Buffer[i] << " ";
		}
	}
	else if (queue->Queue->ReadPoint < queue->Queue->WritePoint)
	{
		for (int i = 0; i < queue->Queue->ReadPoint; i++)
		{
			cout << "- ";
		}
		for (int i = queue->Queue->ReadPoint; i < queue->Queue->WritePoint; i++)
		{
			cout << queue->Queue->Buffer[i] << " ";
		}
		for (int i = queue->Queue->WritePoint; i < queue->Queue->Capacity; i++)
		{
			cout << "- ";
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < queue->Queue->WritePoint; i++)
		{
			cout << queue->Queue->Buffer[i] << " ";
		}
		for (int i = queue->Queue->WritePoint; i < queue->Queue->ReadPoint; i++)
		{
			cout << "- ";
		}
		for (int i = queue->Queue->ReadPoint; i < queue->Queue->Capacity; i++)
		{
			cout << queue->Queue->Buffer[i] << " ";
		}
	}
}

bool GrowQueue(QueueByBuffer* queue)
{
	if (queue->Queue->Size < queue->Queue->Capacity)
	{
		return false;
	}
	else
	{
		const double growFactor = 1.5;
		queue->Queue->WritePoint = queue->Queue->Capacity;
		queue->Queue->Capacity = queue->Queue->Capacity * growFactor;
		queue->Queue->IsFull = false;
	}
}