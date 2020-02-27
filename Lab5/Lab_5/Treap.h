#pragma once
#include"TreapNode.h"

struct Treap
{
	TreapNode* Root;

	void Create();
	//TODO: Передача ноды?
	TreapNode* Find(TreapNode* node, int key);
	void Split(TreapNode* node, int key,
		TreapNode*& left, TreapNode*& right);
	TreapNode* Merge(TreapNode* left, TreapNode* right);
	void SlowInsert(int key);
	void FastInsert(TreapNode* node, TreapNode* parent,
		int key, int priority);
	void SlowRemove(int key);
	void FastRemove(TreapNode* node, TreapNode* parent, int key);
	void Clear(TreapNode* node);
	bool IsEmpty();

	bool IsCreated;
};

void PrintTreap(TreapNode* node, int level);