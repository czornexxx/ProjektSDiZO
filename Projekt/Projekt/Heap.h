#pragma once
#include "Biblioteki.h"
class Heap
{
private:
	int size;
	int *tab;
public:
	Heap(void);
	~Heap(void);

	void Add(int);
	void BuildHeap();
	void Heapify(int);
	void RemoveRoot(void);
	void ReadFromFile(void);
	void Write(void);
	bool Search(int);
};

