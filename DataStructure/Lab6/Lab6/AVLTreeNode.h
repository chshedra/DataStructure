#pragma once
struct AVLTreeNode
{
	int Data;
	AVLTreeNode* Left;
	AVLTreeNode* Right;
	unsigned int Height;

	AVLTreeNode(int data)
	{
		Data = data;
		Left = Right = nullptr;
		Height = 1;
	}
};