#pragma once


#include "RBTreeNode.h"

struct RBTree
{
	RBTreeNode* Root;
	RBTreeNode* Nil;
	bool Insert(int);
	bool DeleteElem(RBTreeNode*);
	bool SearchElem(RBTreeNode*&, int);
	void RotateLeft(RBTreeNode*);
	void RotateRight(RBTreeNode*);
	void InsertFixup(RBTreeNode*);
	void DeleteFixup(RBTreeNode*);

	RBTree()
	{
		Root = nullptr;
		Nil = new RBTreeNode();
	}
};