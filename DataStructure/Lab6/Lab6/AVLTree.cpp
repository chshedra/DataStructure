#include "AVLTree.h"

AVLTreeNode* AVLTree::AddElement(AVLTreeNode* node, int number)
{
	if (!node)
	{
		return new AVLTreeNode(number);
	}
	if (number < node->Data)
	{
		node->Left = AddElement(node->Left, number);
	}
	else if (number > node->Data)
	{
		node->Right = AddElement(node->Right, number);
	}
	else
	{
		return node;
	}
	return Balance(node);
}

AVLTreeNode* AVLTree::RemoveElement(AVLTreeNode* node, int number)
{
	if (!node)
	{
		return node;
	}
	if (number < node->Data)
	{
		node->Left = RemoveElement(node->Left, number);
	}
	else if (number > node->Data)
	{
		node->Right = RemoveElement(node->Right, number);
	}
	else
	{
		AVLTreeNode* left = node->Left;
		AVLTreeNode* right = node->Right;
		delete node;
		if (!right)
		{
			return left;
		}

		AVLTreeNode* min = SearchMin(right);

		min->Right = RemoveMin(right);
		min->Left = left;
		return Balance(min);
	}
	return Balance(node);
}

bool AVLTree::SearchElement(int number)
{
	AVLTreeNode* current = Root;
	while (current != nullptr)
	{
		if (current->Data == number)
		{
			return true;
		}
		else if (current->Data > number)
		{
			current = current->Left;
		}
		else
		{
			current = current->Right;
		}
	}
	return false;
}

AVLTreeNode* AVLTree::SearchMin(AVLTreeNode* node)
{
	if (node->Left == nullptr)
	{
		return node;
	}
	return SearchMin(node->Left);
}

AVLTreeNode* AVLTree::RemoveMin(AVLTreeNode* node)
{
	if (!node->Left)
	{
		return node->Right;
	}
	node->Left = RemoveMin(node->Left);
	return Balance(node);
}

AVLTreeNode* AVLTree::RotateRight(AVLTreeNode* node)
{
	AVLTreeNode* support = node->Left;
	node->Left = support->Right;
	support->Right = node;
	FixHeight(node);
	FixHeight(support);
	return support;
}

AVLTreeNode* AVLTree::RotateLeft(AVLTreeNode* node)
{
	AVLTreeNode* support = node->Right;
	node->Right = support->Left;
	support->Left = node;
	FixHeight(node);
	FixHeight(support);
	return support;
}

AVLTreeNode* AVLTree::Balance(AVLTreeNode* node)
{
	FixHeight(node);
	if (CountBalanceFactor(node) == 2)
	{
		if (CountBalanceFactor(node->Right) < 0)
		{
			node->Right = RotateRight(node->Right);
		}
		return RotateLeft(node);
	}

	if (CountBalanceFactor(node) == -2)
	{
		if (CountBalanceFactor(node->Left) > 0)
		{
			node->Left = RotateLeft(node->Left);
		}
		return RotateRight(node);
	}
	return node;
}

unsigned int AVLTree::CountHeight(AVLTreeNode* node)
{
	return node ? node->Height : 0;
}


int AVLTree::CountBalanceFactor(AVLTreeNode* node)
{
	return CountHeight(node->Right) - CountHeight(node->Left);
}

void AVLTree::FixHeight(AVLTreeNode* node)
{
	unsigned int left = CountHeight(node->Left);
	unsigned int right = CountHeight(node->Right);
	node->Height = (left > right ? left : right) + 1;
}