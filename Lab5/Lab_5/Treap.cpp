#include <iostream>
#include "TreapNode.h"
#include "Treap.h"

using namespace std;


void Treap::Create()
{
	Root = nullptr;
	IsCreated = true;
}


TreapNode* Treap::Find(TreapNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Key == key)
	{
		return node;
	}
	if (key < node->Key)
	{
		return Find(node->Left, key);
	}
	else
	{
		return Find(node->Right, key);
	}
}

void Treap::Split(TreapNode* node, int key,
	TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (key >= node->Key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (key < node->Key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void Treap::SlowInsert(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);

	TreapNode* node = new TreapNode;
	node->Init(key);

	left = Merge(left, node);
	Root = Merge(left, right);
}

void Treap::FastInsert(TreapNode* node, TreapNode* parent,
	int key, int priority)
{
	if (node == nullptr)
	{
		node = new TreapNode;
		node->Init(key);
		Root = node;
		return;
	}
	else if (node->Priority < priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(node, key, left, right);

		TreapNode* newNode = new TreapNode;
		newNode->Key = key;
		newNode->Priority = priority;
		newNode->Left = left;
		newNode->Right = right;

		if (parent != nullptr)
		{
			parent->Left == node 
				? parent->Left = newNode 
				: parent->Right = newNode;
		}
		else
		{
			Root = newNode;
		}

		return;
	}
	else if (key < node->Key)
	{
		return FastInsert(node->Left, node, key, priority);
	}
	else if (key > node->Key)
	{
		return FastInsert(node->Right, node, key, priority);
	}
}

void Treap::SlowRemove(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);

	TreapNode* newLeft = nullptr;
	TreapNode* newRight = nullptr;
	Split(left, key - 1, newLeft, newRight);

	if (newRight == nullptr)
	{
		cout << "Такого элемента нет.\n\n";
		return;
	}

	Root = Merge(newLeft, right);

	delete newRight;
}

void Treap::FastRemove(TreapNode* node, TreapNode* parent, int key)
{
	if (node == nullptr)
	{
		cout << "Такого элемента нет.\n\n";
		return;
	}
	if (key < node->Key)
	{
		return FastRemove(node->Left, node, key);
	}
	else if (key > node->Key)
	{
		return FastRemove(node->Right, node, key);
	}
	else
	{
		TreapNode* newNode = Merge(node->Left, node->Right);

		if (parent != nullptr)
		{
			parent->Left == node ? parent->Left = newNode :
				parent->Right = newNode;
		}
		else
		{
			Root = newNode;
		}

		delete node;
		return;
	}
}

void Treap::Clear(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	Clear(node->Left);
	Clear(node->Right);

	delete node;
}

bool Treap::IsEmpty()
{
	return Root == nullptr;
}

void PrintTreap(TreapNode* node, int level)
{
	if (node != nullptr)
	{
		PrintTreap(node->Right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "; " << node->Priority << "\n";

		PrintTreap(node->Left, level + 1);
	}
}
