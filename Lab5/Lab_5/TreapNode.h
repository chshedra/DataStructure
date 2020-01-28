#pragma once
struct TreapNode
{
	int Key;
	int Priority;

	TreapNode* Left;
	TreapNode* Right;

	void Init(int key);
};