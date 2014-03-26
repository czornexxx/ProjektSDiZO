#include <iostream>

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
	bool add(int Value, int idx);
	int getValue(int idx);
	int getSize();
	bool removeIndex(int idx);
	void remove(int value);
	bool sprawdz(int Value);
	int getPozycja(int Value);
	void wyswietl();
	void wczytaj();
};

