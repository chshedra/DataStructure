#pragma once
#include"RBTree.h"
#include "AVLTree.h"

using namespace std;

int  InputValidation();
void  PrintTree(RBTreeNode* node, int level);
void DisplayAVLTree(AVLTreeNode* node, int level, int* number);