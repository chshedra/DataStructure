#pragma once

struct CircularBuffer
{
	int *Buffer;
	int ReadPoint;
	int WritePoint;
	int Capacity;
	int Size;
	//TODO:RSDN
	bool isFull;
	bool isGrown;
};

CircularBuffer* CreateBuffer();
void WriteItem(CircularBuffer* buffer, int value);
bool ReadItem(CircularBuffer* buffer, int &readItem);
void DisplayBuffer(CircularBuffer* buffer);
int CountEmptyCell(CircularBuffer* buffer);
int CountFilledCells(CircularBuffer* buffer);
