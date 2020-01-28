#include <iostream>
#include <ctime>
#include "TreapNode.h"

void TreapNode::Init(int key)
{
	srand(time(0));

	Key = key;
	Priority = rand() % 100;

	Left = nullptr;
	Right = nullptr;
}