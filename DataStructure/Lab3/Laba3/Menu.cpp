#include <iostream>
#include "Menu.h"
#include "Common.h"
using namespace std;


void StackMenu(Stack* newStack, int stackChoise)
{
	do
	{
		cout << "Selest the item from the menu:\n"
			<< "1.Push\n"
			<< "2.Pop\n"
			<< "3.Delete\n"
			<< "4.Display\n"
			<< "5.Grow stack\n"
			<< "6.Exit to main menu\n";
		cout << endl;
		int stackChoise = InputValidation();
		switch (stackChoise)
		{
		case 1:
		{
			cout << "Enter the value: ";
			int value = InputValidation();
			bool isOverflow = Push(newStack, value);
			if (isOverflow == false)
			{
				cout << "Stack overflow!" << endl;
			}
			DisplayStack(newStack);
			cout << endl;
			break;
		}
		case 2:
		{
			if (newStack->Head == nullptr)
			{
				cout << "Stack is empty" << endl;
				break;
			}
			else
			{
				int popItem;
				bool isEmpty;
				isEmpty = Pop(newStack, popItem);
				cout << "The popped item is " << popItem << endl;
				DisplayStack(newStack);
				cout << endl;
				break;
			}
		}
		case 3:
		{
			DeleteStack(newStack);
			cout << "Stack is empty" << endl;
			break;
		}
		case 4:
		{
			if (newStack->Head == nullptr)
			{
				cout << "Stack is empty" << endl;;
				break;
			}
			DisplayStack(newStack);
			break;
		}
		case 5:
		{
			GrowStack(newStack);
			cout << "Stack has been grown" << endl;
			break;
		}
		case 6:
		{
			DeleteStack(newStack);
			return;
		}
		default:
		{
			cout << "" << endl;
			break;
		}
		}
	} while (true);
}

void CircularBufferMenu(CircularBuffer* buffer)
{
	do
	{
		cout << "Selest the item from menu:\n"
			<< "1.Add element\n"
			<< "2.Delete element\n"
			<< "3.Amount of empty nodes\n"
			<< "4.Amount of filled nodes\n"
			<< "5.Exit to main menu\n";
		int choise = InputValidation();
		switch (choise)
		{
		case 1:
		{
			cout << "Enter the element: ";
			int value = InputValidation();
			WriteItem(buffer, value);
			DisplayBuffer(buffer);
			break;
		}
		case 2:
		{
			int readItem;
			bool isEmpty = ReadItem(buffer, readItem);
			if (isEmpty == false)
			{
				cout << "Buffer is empty!" << endl;
				break;
			}
			cout << "Deleted item is " << readItem << endl;
			DisplayBuffer(buffer);
			break;
		}
		case 3:
		{
			cout << "The number of empty cells is "
				<< CountEmptyCell(buffer) << endl;
			break;
		}
		case 4:
		{
			cout << "The number of filled cells is "
				<< CountFilledCells(buffer) << endl;
			break;
		}
		case 5:
		{
			return;
		}
		default:
		{
			cout << "The wrong item is selested";
			break;
		}
		}
	} while (true);
}


void QueueByStacksMenu(Queue* newQueue)
{
	do
	{
		cout << "Selest the item from menu: \n"
			<< "1.Enqueue\n"
			<< "2.Dequeue\n"
			<< "3.Delete queue\n"
			<< "4.Grow queue\n"
			<< "5.Exit to main menu\n";
		int queueChoise = InputValidation();
		switch (queueChoise)
		{
		case 1:
		{
			cout << "Enter the value ";
			int value = InputValidation();
			bool isEmpty = Enqueue(newQueue, value);
			if (isEmpty == false)
			{
				cout << "Queue is full!" << endl;
			}

			DisplayStack(newQueue->First);
			DisplayStack(newQueue->Second);
			cout << endl;
			break;
		}
		case 2:
		{
			int dequeueItem;
			bool isEmpty = DeQueue(newQueue, dequeueItem);
			if (isEmpty == false)
			{
				cout << "Queue is empty" << endl;
				break;
			}
			cout << " The dequeued item is " << dequeueItem << endl;
			DisplayStack(newQueue->First);

			DisplayStack(newQueue->Second);
			cout << endl;
			break;
		}
		case 3:
		{
			ClearQueue(newQueue);
			cout << "Queue is empty" << endl;
			break;
		}
		case 4:
		{
			GrowQueue(newQueue);
			cout << "Queue has been grown" << endl;
			break;
		}
		case 5:
		{
			return;
		}
		default:
		{
			cout << "The wrong item is selested";
			break;
		}
		}
	} while (true);
}

void QueueByBufferMenu(QueueByBuffer* queue)
{
	do
	{
		cout << "Selest the item from menu: \n"
			<< "1.Enqueue\n"
			<< "2.Dequeue\n"
			<< "3.Delete queue\n"
			<< "4.Exit to main menu\n";
		int queueChoise = InputValidation();
		switch (queueChoise)
		{
		case 1:
		{
			cout << "Enter the value: ";
			int value = InputValidation();
			EnqueueItem(queue, value);
			DisplayQueueByBuffer(queue);
			cout << endl;
			break;
		}
		case 2:
		{
			int dequeuedItem = 0;
			bool isEmpty = DequeueItem(queue, dequeuedItem);
			if (isEmpty == false)
			{
				cout << "Queue is empty" << endl;
				break;
			}
			cout << " The dequeued item is " << dequeuedItem << endl;
			if (queue->Queue->Size != 0)
			{
				DisplayQueueByBuffer(queue);
			}
			cout << endl;
			break;
		}
		case 3:
		{
			DeleteQueue(queue);
			cout << "Queue is empty" << endl;
			break;
		}
		case 4:
		{
			return;
		}
		}
	} while (true);
}