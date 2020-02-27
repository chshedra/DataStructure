#pragma once
#include "BinaryTreeNode.h"
#include <iostream>

#pragma once
struct BinaryTree
{
	BinaryTreeNode* Root;

	void Create();
	//TODO: передача ноды?
	BinaryTreeNode* Find(BinaryTreeNode* node, int key);
	BinaryTreeNode* FindMax(BinaryTreeNode* node);
	BinaryTreeNode* FindMin(BinaryTreeNode* node);
	bool Insert(BinaryTreeNode* node, int key);
	bool Remove(BinaryTreeNode* node, int key);
	void Clear(BinaryTreeNode* node);
	bool IsEmpty();

	bool IsCreated;
};

void Print(BinaryTreeNode* node, int level);