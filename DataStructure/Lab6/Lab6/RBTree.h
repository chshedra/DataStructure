#pragma once


#include "RBTreeNode.h"

struct RBTree
{
	RBTreeNode* Root;
	RBTreeNode* Nil;
	bool Insert(int);
	bool DeleteElem(RBTreeNode* node);
	bool SearchElem(RBTreeNode*& node, int value);
	void RotateLeft(RBTreeNode* node);
	void RotateRight(RBTreeNode* node);
	void InsertFixup(RBTreeNode* node);
	void DeleteFixup(RBTreeNode* node);

	RBTree()
	{
		Root = nullptr;
		Nil = new RBTreeNode();
	}
};