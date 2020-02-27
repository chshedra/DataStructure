#pragma once

#include <iostream>
#include <ctime>
#include "AVLTreeNode.h"


struct AVLTree
{
	unsigned int CountHeight(AVLTreeNode* node);
	int CountBalanceFactor(AVLTreeNode* node);

	void FixHeight(AVLTreeNode* node);
	AVLTreeNode* Root = nullptr;
	AVLTreeNode* AddElement(AVLTreeNode* node, int value);
	AVLTreeNode* RemoveElement(AVLTreeNode*node, int value);
	bool SearchElement(int value);
	AVLTreeNode* RotateLeft(AVLTreeNode* node);
	AVLTreeNode* RotateRight(AVLTreeNode* node);
	AVLTreeNode* Balance(AVLTreeNode* node);
	AVLTreeNode* SearchMin(AVLTreeNode* node);
	AVLTreeNode* RemoveMin(AVLTreeNode* node);
};