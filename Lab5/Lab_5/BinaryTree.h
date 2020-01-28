#pragma once
#include "BinaryTreeNode.h"
#include <iostream>

#pragma once
struct BinaryTree
{
	BinaryTreeNode* Root;

	void Create();
	BinaryTreeNode* Find(BinaryTreeNode* node, int key);
	BinaryTreeNode* FindMax(BinaryTreeNode* node);
	BinaryTreeNode* FindMin(BinaryTreeNode* node);
	void Insert(BinaryTreeNode* node, int key);
	void Remove(BinaryTreeNode* node, int key);
	void Clear(BinaryTreeNode* node);
	bool IsEmpty();

	bool IsCreated;
};

void Print(BinaryTreeNode* node, int level);