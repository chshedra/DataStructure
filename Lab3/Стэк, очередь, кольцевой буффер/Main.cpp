#include <iostream>
#include "Menu.h"
using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		int stackChoise = 0;
		cout << "Selest the type of stucture: \n"
			 << "1.Stack\n"
			 << "2.Circular buffer\n"
			 << "3.Queue using stacks\n"
			 << "4.Queue using circular buffer\n";
		int mainChoice = InputValidation();
		switch (mainChoice)
		{
		case 1:
		{
				  Stack* newStack = CreateStack();
				  StackMenu(newStack, stackChoise);
				  delete newStack;
				  break;
		}
		case 2:
		{
				  CircularBuffer *buffer = CreateBuffer();
				  CircularBufferMenu(buffer);
				  delete buffer;
				  break;
		}
		case 3:
		{
				  Queue* newQueue = new Queue;
				  CreateQueue(newQueue);
				  QueueByStacksMenu(newQueue);
				  delete newQueue;
				  break;
		}
		case 4:
		{
				  QueueByBuffer* queue = new QueueByBuffer;
				  CreateQueueByBuffer(queue);
				  QueueByBufferMenu(queue);
				  delete queue;
				  break;
		}
		default:
		{
				   cout << "Wrong menu item selected" << endl;
				   break;
		}
		}
	}
	system("pause");
}




