#pragma once

#include <iostream>
#include <ctime>
#include "AVLTreeNode.h"


struct AVLTree
{
	unsigned int CountHeight(AVLTreeNode*);
	int CountBalanceFactor(AVLTreeNode*);

	void FixHeight(AVLTreeNode*);
	AVLTreeNode* Root = nullptr;
	AVLTreeNode* AddElement(AVLTreeNode*, int);
	AVLTreeNode* RemoveElement(AVLTreeNode*, int);
	bool SearchElement(int);
	AVLTreeNode* RotateLeft(AVLTreeNode*);
	AVLTreeNode* RotateRight(AVLTreeNode*);
	AVLTreeNode* Balance(AVLTreeNode* node);
	AVLTreeNode* SearchMin(AVLTreeNode*);
	AVLTreeNode* RemoveMin(AVLTreeNode*);
};