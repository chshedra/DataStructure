#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"

using namespace std;

void BinaryTree::Create()
{
	Root = nullptr;
	IsCreated = true;
}

BinaryTreeNode* BinaryTree::Find(BinaryTreeNode* node, int key)
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

BinaryTreeNode* BinaryTree::FindMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Right != nullptr)
	{
		node = node->Right;
	}

	return node;
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	while (node->Left != nullptr)
	{
		node = node->Left;
	}

	return node;
}

bool BinaryTree::Insert(BinaryTreeNode* node, int key)
{

	if (node == nullptr)
	{
		node = new BinaryTreeNode;
		node->Init(key);
		Root = node;
		return true;
	}
	if (key < node->Key && node->Left == nullptr)
	{
		node->Left = new BinaryTreeNode;
		node->Left->Init(key);
		node->Left->Parent = node;
		return true;
	}
	else if (key < node->Key)
	{
		return Insert(node->Left, key);
	}
	if (key > node->Key&& node->Right == nullptr)
	{
		node->Right = new BinaryTreeNode;
		node->Right->Init(key);
		node->Right->Parent = node;
		return true;
	}
	else if (key > node->Key)
	{
		return Insert(node->Right, key);
	}
	else
	{
		return false;
	}
}

bool BinaryTree::Remove(BinaryTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return false;
	}
	if (key < node->Key)
	{
		return Remove(node->Left, key);
	}
	else if (key > node->Key)
	{
		return Remove(node->Right, key);
	}
	else
	{
		if (node->Left == nullptr && node->Right == nullptr)
		{
			if (node->Parent != nullptr)
			{
				node->Parent->Left == node 
					? node->Parent->Left = nullptr 
					:node->Parent->Right = nullptr;
			}
			else
			{
				Root = nullptr;
			}

			delete node;
		}
		else if (node->Left != nullptr && node->Right == nullptr)
		{
			BinaryTreeNode* oldNode = node;
			node = node->Left;
			node->Parent = oldNode->Parent;

			if (oldNode->Parent != nullptr)
			{
		
				oldNode->Parent->Left == oldNode 
					?oldNode->Parent->Left = node 
					:oldNode->Parent->Right = node;
			}
			else
			{
				Root = node;
			}

			delete oldNode;
		}
		else if (node->Right != nullptr && node->Left == nullptr)
		{
			BinaryTreeNode* oldNode = node;
			node = node->Right;
			node->Parent = oldNode->Parent;

			if (oldNode->Parent != nullptr)
			{
				oldNode->Parent->Left == oldNode ?
					oldNode->Parent->Left = node :
					oldNode->Parent->Right = node;
			}
			else
			{
				Root = node;
			}

			delete oldNode;
		}
		else
		{
			BinaryTreeNode* oldNode = node;
			node = FindMin(oldNode->Right);
			int min = node->Key;

			Remove(node, min);

			oldNode->Key = min;
		}
	}
}

void BinaryTree::Clear(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}

	Clear(node->Left);
	Clear(node->Right);

	delete node;
}

bool BinaryTree::IsEmpty()
{
	return Root == nullptr;
}

void Print(BinaryTreeNode* node, int level)
{
	if (node != nullptr)
	{
		Print(node->Right, level + 1);

		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->Key << "\n";

		Print(node->Left, level + 1);
	}
}