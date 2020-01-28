#pragma once
#include "NodeColor.h"

struct RBTreeNode
{
	int Data;
	NodeColor Color;
	RBTreeNode* Left;
	RBTreeNode* Right;
	RBTreeNode* Parent;
	RBTreeNode(int data = 0, NodeColor color = BLACK, RBTreeNode* parent = nullptr)
	{
		Data = data;
		Color = color;
		Parent = parent;
		Left = nullptr;
		Right = nullptr;
	}
};