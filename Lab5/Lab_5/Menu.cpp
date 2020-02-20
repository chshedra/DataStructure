#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeNode.h"
#include "Treap.h"
#include "TreapNode.h"
#include "Menu.h"

using namespace std;

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

void MainMenu()
{
	while (true)
	{
		//comment
		cout << "1.Binary tree\n"
			<< "2.Treap Tree\n"
			<< "3.Exit\n";
		cout << "Select the item from the menu: ";
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			BinaryTreeMenu();
			break;
		}
		case 2:
		{
			TreapTreeMenu();
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



void BinaryTreeMenu()
{
	BinaryTree* newTree = new BinaryTree;
	newTree->IsCreated = false;
	while (true)
	{

		cout << "Choose the point from the menu:\n"
			<< "1.Add element\n"
			<< "2.Delete element\n"
			<< "3.Find element\n"
			<< "4.Find max\n"
			<< "5.Find min\n"
			<< "6.Delete tree\n"
			<< "7.Back to main menu\n";
		cout << endl;
		int choice = InputValidation();
		switch (choice)
		{
		case 1:
		{
			if (!newTree->IsCreated)
			{
				newTree->Create();
			}

			cout << "Enter the value: ";
			int key = InputValidation();
			cout << endl;

			bool isInserted = newTree->Insert(newTree->Root, key);
			if (isInserted == true)
			{
				Print(newTree->Root, 0);
			}
			else
			{
				cout << "This element is already in the tree!\n";
			}
			break;
		}
		case 2:
		{
			if (!newTree->IsCreated || newTree->IsEmpty())
			{
				cout << "Tree is empty\n";
				break;
			}

			cout << "Enter the key: ";
			int key = InputValidation();
			cout << endl;

			bool isRemoved = newTree->Remove(newTree->Root, key);
			if (isRemoved = true)
			{
				Print(newTree->Root, 0);
			}
			else
			{
				cout << "There is not this element in the tree!\n";
			}
			break;
		}
		case 3:
		{
			if (!newTree->IsCreated || newTree->IsEmpty())
			{
				cout << "Tree is empty\n";
				break;
			}

			cout << "Enter the value: ";
			int key = InputValidation();
			cout << "\n";

			BinaryTreeNode* node =
				newTree->Find(newTree->Root, key);

			cout << (node == nullptr ? "There is not this element in the tree\n"
				: "Element has been found\n");

			break;
		}
		case 4:
		{
			if (!newTree->IsCreated || newTree->IsEmpty())
			{
				cout << "Дерево пустое.\n";
				break;
			}

			BinaryTreeNode* max;
			max = newTree->FindMax(newTree->Root);

			if (max == nullptr)
			{
				cout << "Tree is empty\n";
				break;
			}

			cout << "Maximal element is "
				<< max->Key << ".\n";
			break;
		}
		case 5:
		{
			if (!newTree->IsCreated || newTree->IsEmpty())
			{
				cout << "Дерево пустое.\n";
				break;
			}

			BinaryTreeNode* min;
			min = newTree->FindMin(newTree->Root);

			if (min == nullptr)
			{
				cout << "Tree is empty\n";
				break;
			}

			cout << "Minimal element is "
				<< min->Key << ".\n";
			break;
		}
		case 6:
		{
			if (!newTree->IsCreated)
			{
				break;
			}

			newTree->Clear(newTree->Root);
			newTree->IsCreated = false;
			break;
		}
		case 7:
		{
			return;
		}
		default:
		{
			cout << "Selest the right item!\n";
			break;
		}
		}
	}
	delete newTree;
}

void TreapTreeMenu()
{
	Treap* newTree = new Treap;
	newTree->IsCreated = false;
	{
		while (true)
		{
			cout << "Selest the point from the menu\n";
			cout << "1. Not optimised insertion\n"
				<< "2. Optimised insertion\n"
				<< "3. Not optimised deltion\n"
				<< "4. Optimized deletion"
				<< "5. Find element\n"
				<< "6. Delete element\n"
				<< "7. Back to the main menu\n";

			int choice = InputValidation();
			switch (choice)
			{
			case 1:
			{
				if (!newTree->IsCreated)
				{
					newTree->Create();
				}

				cout << "Enter the value: ";
				int key = InputValidation();
				cout << endl;

				TreapNode* node = newTree->Find(newTree->Root, key);
				if (node != nullptr)
				{
					cout << "This element in the tree!\n ";
					break;
				}
				newTree->SlowInsert(key);
				PrintTreap(newTree->Root, 0);
				break;
			}
			case 2:
			{
				if (!newTree->IsCreated)
				{
					newTree->Create();
				}

				cout << "Enter the value ";
				int key = InputValidation();
				cout << endl;

				TreapNode* node = newTree->Find(newTree->Root, key);
				if (node != nullptr)
				{
					cout << "This element in the tree!\n ";
					break;
				}
				int priority = rand() % 100;

				newTree->FastInsert(newTree->Root, nullptr, key, priority);
				PrintTreap(newTree->Root, 0);
				break;
			}
			case 3:
			{
				if (!newTree->IsCreated || newTree->IsEmpty())
				{
					cout << "Tree is empty!\n";
					break;
				}

				cout << "Enter the value: ";
				int key = InputValidation();
				cout << endl;

				newTree->SlowRemove(key);
				PrintTreap(newTree->Root, 0);
				break;
			}
			case 4:
			{
				if (!newTree->IsCreated || newTree->IsEmpty())
				{
					cout << "Tree is empty\n";
					break;
				}

				cout << "Enter the value: ";
				int key = InputValidation();
				cout << endl;

				newTree->FastRemove(newTree->Root, nullptr, key);
				PrintTreap(newTree->Root, 0);
				break;
			}
			case 5:
			{
				if (!newTree->IsCreated || newTree->IsEmpty())
				{
					cout << "Tree is empty\n";
					break;
				}

				cout << "Enter the value: ";
				int key = InputValidation();

				TreapNode* node = newTree->Find(newTree->Root, key);

				if (node == nullptr)
				{
					cout << "There is not this element in the tree\n";
				}
				else
				{
					cout << "Element = " << node->Key << endl
						<< "Priority = " << node->Priority << endl;
				}
				break;
			}
			case 6:
			{
				if (!newTree->IsCreated || newTree->IsEmpty())
				{
					break;
				}

				newTree->Clear(newTree->Root);
				newTree->IsCreated = false;
				break;
			}
			case 7:
			{
				return;
			}

			default:
				cout << "Select the right item!\n";
				break;
			}
		}
	}
}


