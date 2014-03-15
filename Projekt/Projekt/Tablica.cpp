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

	int *tmp = new int[size + 1];

	for(int i=0; i<size; i++)
		tmp[i] = tablica[i];

	delete[] tablica;

	tmp[size] = Value;
	
	tablica = tmp;

	size ++;
}

bool Tablica::add(int Value, int idx){

	idx --;			// -1 bo tablica od 0

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
		return tablica[idx];
	return NULL;
}

int Tablica::getSize(){

	return size;
}

bool Tablica::remove(int idx){

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

void Tablica::wypisz(){

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
			return i;

	return NULL;	
}

void Tablica::wczytaj()
{

	int poprzedniRozmiar=size;
	fstream plik;
	string sizee;
	
	plik.open( "liczby.txt" );
	getline(plik, sizee);
	size= poprzedniRozmiar + (atoi(sizee.c_str()));

	int *tab = new int[size];
	for(int i=0; i< poprzedniRozmiar; i++)
		tab[i] = tablica[i];

	delete[] tablica;

	tablica = tab;

	int i = poprzedniRozmiar;

	while( !plik.eof() )
	{
   
		plik>>tablica[i];
		i++;
	}

plik.close();
}

