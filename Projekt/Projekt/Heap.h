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
	void Remove(int);
	void ReadFromFile(void);
	void Write(void);
};

