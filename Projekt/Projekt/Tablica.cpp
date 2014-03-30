#include "Biblioteki.h"
Tablica::Tablica(){

	tablica = new int[0];
	size = 0;
}


Tablica::~Tablica(void)
{
	delete [] tablica;
}


void Tablica::add(int Value){

	int *tmp = new int[size + 1];	// utworzenie nowej wi�kszej tablicy

	for(int i=0; i<size; i++)		// przekopiowanie danych
		tmp[i] = tablica[i];

	delete[] tablica;				// usuniecie mniejszej tablicy

	tmp[size] = Value;				// wstawienie wartosci na koniec
	
	tablica = tmp;					// podstawienie pod g��wny wska�nik nowej tablicy

	size ++;						// zwiekszenie ilosci elementow
}

bool Tablica::add(int Value, int idx){

	idx --;								// -1 bo tablica od 0

	if(idx < 0 || idx > size+1)			// sprawdzenie czy index jest w tablicy
		return false;

	int *tmp = new int[size + 1];		// tworzenie nowej wiekszej tablicy

	for(int i=0; i<idx; i++)			// przekopiowanie warto�ci do miejsca wstawienia elementu
		tmp[i] = tablica[i];

	tmp[idx] = Value;					// Dodanie nowej warto�ci

	for(int i=idx; i<size; i++)			// przekopiowanie reszty warto�ci
		tmp[i+1] = tablica[i];

	delete[] tablica;					// Kasowanie starej tablicy
	
	size ++;							// Zwiekszenie ilo�ci elementow w tablicy
	
	tablica = tmp;

	return true;
}

int Tablica::getValue(int idx){

	if(idx > 0 && idx <= size)
		return tablica[idx];		// zwracanie warto�ci z podanego indeksu
	return NULL;
}

int Tablica::getSize(){

	return size;
}

bool Tablica::removeIndex(int idx){

	idx --;
	// sprawdzenie czy idx jest >=0 oraz czy nie jest wiekszy niz elementy tablicy
	if(idx >= 0 && idx < this->size){

		size --;	// zmiejszenie rozmiaru tablicy

		int *tmp = new int[size];
		
		//przekopiowanie tablicy danych, efektem jest usuniecie wybranego elementu
		for(int i=0; i<idx; i++)
			tmp[i] = tablica[i];

		for(int i=idx; i<size; i++)			
			tmp[i] = tablica[i+1];
		
		delete[] tablica;

		tablica = tmp; 

		return true;
	}
	
	return false;
}

bool Tablica::remove(int value){

	int tmp = getPozycja(value);	// zwrocenie pozycji pod ktora wystepuje wartosc
	if(tmp != NULL){
		removeIndex(tmp);			// usuniecie pozycji
		return true;
	}
	return false;
}

void Tablica::wyswietl(){

	for(int i=0; i<size; i++)
		cout << tablica[i] << endl;
}

bool Tablica::sprawdz(int Value){

	for(int i=0; i<size; i++)	//Sprawdzanie czy jest warto�� w tablicy
		
		if(tablica[i] == Value){
			return true;
		}
	
	return false;	// je�li nie znalaz� warto�ci zwr�� false;
}

int Tablica::getPozycja(int Value){

	for(int i=0; i<size; i++)		// szukanie warto�ci i zwracanie pozycji na kt�rej jest.
		
		if(tablica[i] == Value)
			return (++i);

	return NULL;	
}
