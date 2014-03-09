#include <iostream>
#include <fstream>
using namespace std;

#pragma once
class Tablica
{
private : 
	int *tablica; 
	int size;

public:	
	Tablica();
	~Tablica(void);

	void add(int Value);
	int getValue(int idx);
	int getSize();
	bool remove(int idx);
	bool sprawdz(int Value);
	int getPozycja(int Value);
	void wypisz();
	void wczytaj();
	bool Find(int);
};

