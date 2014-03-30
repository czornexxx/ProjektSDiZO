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

	int *tmp = new int[size + 1];	// utworzenie nowej wiêkszej tablicy

	for(int i=0; i<size; i++)		// przekopiowanie danych
		tmp[i] = tablica[i];

	delete[] tablica;				// usuniecie mniejszej tablicy

	tmp[size] = Value;				// wstawienie wartosci na koniec
	
	tablica = tmp;					// podstawienie pod g³ówny wskaŸnik nowej tablicy

	size ++;						// zwiekszenie ilosci elementow
}

bool Tablica::add(int Value, int idx){

	idx --;								// -1 bo tablica od 0

	if(idx < 0 || idx > size+1)			// sprawdzenie czy index jest w tablicy
		return false;

	int *tmp = new int[size + 1];		// tworzenie nowej wiekszej tablicy

	for(int i=0; i<idx; i++)			// przekopiowanie wartoœci do miejsca wstawienia elementu
		tmp[i] = tablica[i];

	tmp[idx] = Value;					// Dodanie nowej wartoœci

	for(int i=idx; i<size; i++)			// przekopiowanie reszty wartoœci
		tmp[i+1] = tablica[i];

	delete[] tablica;					// Kasowanie starej tablicy
	
	size ++;							// Zwiekszenie iloœci elementow w tablicy
	
	tablica = tmp;

	return true;
}

int Tablica::getValue(int idx){

	if(idx > 0 && idx <= size)
		return tablica[idx];		// zwracanie wartoœci z podanego indeksu
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

	for(int i=0; i<size; i++)	//Sprawdzanie czy jest wartoœæ w tablicy
		
		if(tablica[i] == Value){
			return true;
		}
	
	return false;	// jeœli nie znalaz³ wartoœci zwróæ false;
}

int Tablica::getPozycja(int Value){

	for(int i=0; i<size; i++)		// szukanie wartoœci i zwracanie pozycji na której jest.
		
		if(tablica[i] == Value)
			return (++i);

	return NULL;	
}
