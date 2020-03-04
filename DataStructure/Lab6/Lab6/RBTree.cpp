#include "RBTree.h"

void RBTree::RotateLeft(RBTreeNode* RotateElem)
{
	RBTreeNode* temp = RotateElem->Right;
	RotateElem->Right = temp->Left;
	if (temp->Left != Nil)
	{
		temp->Left->Parent = RotateElem;
	}
	if (temp != Nil)
	{
		temp->Parent = RotateElem->Parent;
	}
	if (RotateElem->Parent)
	{
		if (RotateElem == RotateElem->Parent->Left)
		{
			RotateElem->Parent->Left = temp;
		}
		else
		{
			RotateElem->Parent->Right = temp;
		}
	}
	else
	{
		Root = temp;
	}
	temp->Left = RotateElem;
	if (RotateElem != Nil)
	{
		RotateElem->Parent = temp;
	}
}

void RBTree::RotateRight(RBTreeNode* RotateElem)
{
	RBTreeNode* temp = RotateElem->Left;
	RotateElem->Left = temp->Right;
	if (temp->Right != Nil)
	{
		temp->Right->Parent = RotateElem;
	}
	if (temp != Nil)
	{
		temp->Parent = RotateElem->Parent;
	}
	if (RotateElem->Parent)
	{
		if (RotateElem == RotateElem->Parent->Right)
		{
			RotateElem->Parent->Right = temp;
		}
		else
		{
			RotateElem->Parent->Left = temp;
		}
	}
	else
	{
		Root = temp;
	}
	temp->Right = RotateElem;
	if (RotateElem != Nil)
	{
		RotateElem->Parent = temp;
	}
}

void RBTree::InsertFixup(RBTreeNode* node)
{
	while (node != Root && node->Parent->Color == RED)
	{
		if (node->Parent == node->Parent->Parent->Left)
		{
			RBTreeNode* temp = node->Parent->Parent->Right;
			if (temp->Color == RED)
			{
				node->Parent->Color = BLACK;
				temp->Color = BLACK;
				node->Parent->Parent->Color = RED;
				node = node->Parent->Parent;
			}
			else
			{
				if (node == node->Parent->Right)
				{
					node = node->Parent;
					RotateLeft(node);
				}
				node->Parent->Color = BLACK;
				node->Parent->Parent->Color = RED;
				RotateRight(node->Parent->Parent);
			}
		}
		else
		{
			RBTreeNode* temp = node->Parent->Parent->Left;
			if (temp->Color == RED)
			{
				node->Parent->Color = BLACK;
				temp->Color = BLACK;
				node->Parent->Parent->Color = RED;
				node = node->Parent->Parent;
			}
			else
			{
				if (node == node->Parent->Left)
				{
					node = node->Parent;
					RotateRight(node);
				}
				node->Parent->Color = BLACK;
				node->Parent->Parent->Color = RED;
				RotateLeft(node->Parent->Parent);
			}
		}
	}
	Root->Color = BLACK;
}

bool RBTree::Insert(int data)
{

	RBTreeNode* insertedElem;
	RBTreeNode* parent = nullptr;
	RBTreeNode* current = Root;

	while (current != Nil && current)
	{
		if (data == current->Data) return false;

		parent = current;
		current = (data < current->Data)
			? current->Left
			: current->Right;
	}
	insertedElem = new RBTreeNode(data, RED, parent);
	insertedElem->Left = insertedElem->Right = Nil;
	if (parent)
	{
		if (data < parent->Data)
		{
			parent->Left = insertedElem;
		}
		else
		{
			parent->Right = insertedElem;
		}
	}
	else
	{
		Root = insertedElem;
	}
	InsertFixup(insertedElem);
	return true;
}

void RBTree::DeleteFixup(RBTreeNode* node)
{
	while (node != Root && node->Color == BLACK)
	{
		if (node == node->Parent->Left)
		{
			RBTreeNode* temp = node->Parent->Right;
			if (temp->Color == RED)
			{
				temp->Color = BLACK;
				temp->Parent->Color = RED;
				RotateLeft(node->Parent);
				temp = node->Parent->Right;
			}
			if (temp->Left->Color == BLACK && temp->Right->Color == BLACK)
			{
				temp->Color = RED;
				node = node->Parent;
			}
			else
			{
				if (temp->Right->Color == BLACK)
				{
					temp->Left->Color = BLACK;
					temp->Color = RED;
					RotateRight(temp);
					temp = node->Parent->Right;
				}

				temp->Color = node->Parent->Color;
				node->Parent->Color = BLACK;
				temp->Right->Color = BLACK;
				RotateLeft(node->Parent);
				node = Root;
			}
		}
		else
		{
			RBTreeNode* temp = node->Parent->Left;
			if (temp->Color == RED)
			{
				temp->Color = BLACK;
				temp->Parent->Color = RED;
				RotateRight(node->Parent);
				temp = node->Parent->Left;
			}
			if (temp->Left->Color == BLACK && temp->Right->Color == BLACK)
			{
				temp->Color = RED;
				node = node->Parent;
			}
			else
			{
				if (temp->Left->Color == BLACK)
				{
					temp->Right->Color = BLACK;
					temp->Color = RED;
					RotateLeft(temp);
					temp = node->Parent->Left;
				}

				temp->Color = node->Parent->Color;
				node->Parent->Color = BLACK;
				temp->Left->Color = BLACK;
				RotateRight(node->Parent);
				node = Root;
			}
		}
	}
	node->Color = BLACK;
}

bool RBTree::DeleteElem(RBTreeNode* elem)
{
	RBTreeNode* temp, * deleteElem;

	if (!elem || elem == Nil) return false;

	if (elem->Left == Nil || elem->Right == Nil)
	{
		deleteElem = elem;
	}
	else
	{
		deleteElem = elem->Right;
		while (deleteElem->Left != Nil)
		{
			deleteElem = deleteElem->Left;
		}
	}
	if (deleteElem->Left != Nil)
	{
		temp = deleteElem->Left;
	}
	else
	{
		temp = deleteElem->Right;
	}
	temp->Parent = deleteElem->Parent;
	if (deleteElem->Parent)
	{
		if (deleteElem == deleteElem->Parent->Left)
		{
			deleteElem->Parent->Left = temp;
		}
		else
		{
			deleteElem->Parent->Right = temp;
		}
	}
	else
	{
		Root = temp;
	}
	if (deleteElem != elem)
	{
		elem->Data = deleteElem->Data;
	}
	if (deleteElem->Color == BLACK)
	{
		DeleteFixup(temp);
	}
	delete deleteElem;
}

bool RBTree::SearchElem(RBTreeNode*& elem, int data)
{
	if (Root == nullptr)
	{
		return false;
	}

	RBTreeNode* current = Root;
	while (current != Nil)
	{
		if (data == current->Data)
		{
			elem = current;
			return true;
		}
		current = (data < current->Data)
			? current->Left
			: current->Right;
	}
	elem = nullptr;
	return false;
}

