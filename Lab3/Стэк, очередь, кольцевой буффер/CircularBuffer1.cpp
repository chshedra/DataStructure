#include <iostream>
#include "CircularBuffer1.h"

using namespace std;

CircularBuffer* CreateBuffer()
{
	CircularBuffer *newBuffer = new CircularBuffer;
	newBuffer->Capacity = 8;
	newBuffer->Size = 0;
	newBuffer->Buffer = new int[newBuffer->Capacity];
	newBuffer->ReadPoint = newBuffer->WritePoint = 0;
	newBuffer->isFull = false;
	return newBuffer;
}

void WriteItem(CircularBuffer* buffer, int value)
{
	if (buffer->isFull == true && buffer->ReadPoint == buffer->WritePoint)
	{
		buffer->ReadPoint = (buffer->ReadPoint + 1) % buffer->Capacity;
	}
	buffer->Buffer[buffer->WritePoint] = value;
	buffer->WritePoint = (buffer->WritePoint + 1) % buffer->Capacity;
	if (buffer->Capacity - 1 == buffer->Size)
	{
		buffer->isFull = true;
	}
	if (buffer->Size < buffer->Capacity)
	{
		buffer->Size++;
	}
}

bool ReadItem(CircularBuffer* buffer, int &readItem)
{
	if (buffer->isFull == false && buffer->ReadPoint == buffer->WritePoint)
	{
		return false;
	}
	readItem = buffer->Buffer[buffer->ReadPoint];
	buffer->ReadPoint = (buffer->ReadPoint + 1) % buffer->Capacity;
	if (buffer->ReadPoint == buffer->WritePoint)
	{
		buffer->isFull = false;
		buffer->ReadPoint = buffer->WritePoint = 0;
	}
	buffer->Size--;
	return true;
}

int CountEmptyCell(CircularBuffer* buffer)
{
	int count;
	count = buffer->Capacity - buffer->Size;
	return count;
}

int CountFilledCells(CircularBuffer* buffer)
{
	return buffer->Size;
}


void DisplayBuffer(CircularBuffer* buffer)
{
	cout << "Write: " << buffer->WritePoint << endl;
	cout << "Read: " << buffer->ReadPoint << endl;
	cout << "Size: " << buffer->Size << endl;
	cout << "Capacity: " << buffer->Capacity << endl;
	if (buffer->Size == buffer->Capacity)
	{
		for (int i = 0; i < buffer->Capacity; i++)
		{
			cout << buffer->Buffer[i] << " ";
		}
		cout << endl;
		return;
	}
	if (buffer->isFull == false)
	{
		if (buffer->ReadPoint <= buffer->WritePoint)
		{
			for (int i = 0; i < buffer->ReadPoint; i++)
			{
				cout  << "- ";
			}
			for (int i = buffer->ReadPoint; i < buffer->WritePoint; i++)
			{
				cout << buffer->Buffer[i] << " ";
			}
			for (int i = buffer->WritePoint; i < buffer->Capacity; i++)
			{
				cout << "- ";
			}
		}
		else
		{
			for (int i = 0; i < buffer->WritePoint; i++)
			{
				cout << buffer->Buffer[i] << " ";
			}
			for (int i = buffer->WritePoint; i < buffer->ReadPoint; i++)
			{
				cout << "- ";
			}
			for (int i = buffer->ReadPoint; i < buffer->Capacity; i++)
			{
				cout << buffer->Buffer[i] << " ";
			}
		}
	}
	else 
	{
		cout << "Full" << endl;
		if (buffer->ReadPoint >= buffer->WritePoint)
		{
			for (int i = 0; i < buffer->WritePoint; i++)
			{
				cout << buffer->Buffer[i] << " ";
			}
			for (int i = buffer->WritePoint; i < buffer->ReadPoint; i++)
			{
				cout << "- ";
			}
			for (int i = buffer->ReadPoint; i < buffer->Capacity; i++)
			{
				cout << buffer->Buffer[i] << " ";
			}
		}
		else
		{
			for (int i = 0; i < buffer->ReadPoint; i++)
			{
				cout << "- ";
			}
			for (int i = buffer->ReadPoint; i < buffer->WritePoint; i++)
			{
				cout << buffer->Buffer[i] << " ";
			}
			for (int i = buffer->WritePoint; i < buffer->Capacity; i++)
			{
				cout << "- ";
			}
		}
	
	}
	
	cout << endl;
}