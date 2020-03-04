#pragma once
struct BinaryTreeNode
{
	int Key;
	BinaryTreeNode* Left;
	BinaryTreeNode* Right;
	BinaryTreeNode* Parent;

	void Init(int key);
};