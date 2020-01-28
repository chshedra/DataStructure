#include <iostream>
#include <fstream> 
#include <ctime>
#include"Output.h"
#include "RBTreeNode.h"
#include "AVLTree.h"

#pragma once

int InputValidation()
{
	int number = 0;

	while (true)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Try again!\n";
		}
		else
		{
			break;
		}
	}

	return number;
}

void  PrintTree(RBTreeNode* node, int level)
{
	if (node != nullptr && node->Right != nullptr && node->Left != nullptr)
	{
		PrintTree(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << node->Data;
		if (node->Color == BLACK)
		{
			cout << " B\n";
		}
		else
		{
			cout << " R\n";
		}
		PrintTree(node->Left, level + 1);
	}
}

void DisplayAVLTree(AVLTreeNode* node, int level)
{
	if (node != nullptr)
	{
		DisplayAVLTree(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << node->Data << "(" << node->Height << ")" << endl;
		DisplayAVLTree(node->Left, level + 1);
	}
}