#pragma once
#include "Biblioteki.h"
class Heap
{
private:
	int size;
	int sizebuff;
	int *tab, *buff;
	string cr,cl,cp;
public:
	Heap(void);
	~Heap(void);

	void Add(int);
	void BuildHeap();
	void Heapify(int);
	void RemoveRoot(void);
	void ReadFromFile(void);
	void Write(string,string,int);
	bool Search(int);
	void Remove(int);
	void AddBuff(int);
};

