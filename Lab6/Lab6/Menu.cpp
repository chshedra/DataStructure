#include <iostream>
#include <ctime>
#include "RBTree.h"
#include "Menu.h"
#include "Output.h"

using namespace std;
#pragma once

void MainMenu()
{
	while (true)
	{
		cout << "1.Red-black tree\n"
			<< "2.AVL Tree\n"
			<< "3.Exit\n";
		cout << "Select the item from the menu: ";
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			RBTreeMenu();
			break;
		}
		case 2:
		{
			AVLTreeMenu();
			break;
		}
		case 3:
		{
			exit(0);
		}
		default:
		{
			cout << "Select the right item!" << endl;
		}
		}
	}
}



void RBTreeMenu()
{
	bool ending = true;
	RBTree* newTree = new RBTree();
	RBTreeNode* searchedElem = nullptr;
	cout << "How many elements to create ";
	int number = InputValidation();
	srand(time(NULL));
	for (int i = 0; i < number; i++)
	{
		newTree->Insert(rand() % 100);
	}
	while (true)
	{
		PrintTree(newTree->Root, 0);
		cout << "Choose the point from the menu:\n"
			<< "1.Add element\n"
			<< "2.Delete element\n"
			<< "3.Find element\n"
			<< "4.Back to main menu\n";
		cout << endl;
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			cout << "Enter the number\n";
			number = InputValidation();
			if (newTree->Insert(number))
			{
				cout << "Element has been added\n";
			}
			else
			{
				cout << "This element is already in the tree!\n";
			}
			break;
		}
		case 2:
		{
			if (newTree->Root == nullptr);
			cout << "Enter the number\n";
			number = InputValidation();
			if (newTree->SearchElem(searchedElem, number))
			{
				newTree->DeleteElem(searchedElem);
			}
			else
			{
				cout << "Element is not found!\n";
			}
			break;
		}
		case 3:
		{
			cout << "Enter the number\n";
			number = InputValidation();
			if (newTree->SearchElem(searchedElem, number))
			{
				cout << "The number is found " << endl;
			}
			else
			{
				cout << "Element has not been found!\n";
			}
			break;
		}
		case 4:
		{
			return;
		}
		default:
		{
			cout << "Select the right item!\n";
			break;
		}
		}
	}
	delete newTree;
}

void AVLTreeMenu()
{
	bool ending = true;
	AVLTree* newTree = new AVLTree();
	cout << "Enter the count of elemetns\t";
	int number = InputValidation();
	srand(time(NULL));
	for (int i = 0; i < number; i++)
	{
		newTree->Root = newTree->AddElement(newTree->Root, rand() % 100);
	}
	cout << endl;
	while (ending)
	{
		DisplayAVLTree(newTree->Root, 0);
		cout << endl;
		cout << "Choose the item from the menu:\n"
			<< "1.Add element\n"
			<< "2.Delete element\n"
			<< "3.Find element\n"
			<< "4.Back to main menu\n";
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			cout << "Enter the number\n";
			number = InputValidation();
			newTree->Root = newTree->AddElement(newTree->Root, number);
			break;
		}
		case 2:
		{
			cout << "Enter the number\n";
			number = InputValidation();
			if (newTree->SearchElement(number))
			{
				newTree->Root = newTree->RemoveElement(newTree->Root, number);
			}
			else
			{
				cout << "There is not this element in the tree\n";
			}
			break;
		}
		case 3:
		{
			cout << "Enter the number\n";
			number = InputValidation();
			cout << endl;
			if (newTree->SearchElement(number))
			{
				cout << "Element has been found\n";
			}
			else
			{
				cout << "There is not this element in the tree\n";
			}
			break;
		}
		case 4:
		{
			return;
		}
		default:
			cout << "Select the right item!\n";
			break;
		}
	}
	delete newTree;
}