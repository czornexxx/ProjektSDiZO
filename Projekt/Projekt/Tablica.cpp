#include "Tablica.h"
#include <string>
Tablica::Tablica(){

	tablica = new int[2];
	
	tablica[0] = 5;
	tablica[1] = 10;
	
	size = 2; 
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

int Tablica::getValue(int idx){

	if(idx > 0 && idx <= size)
		return tablica[idx];
	return NULL;
}

int Tablica::getSize(){

	return size;
}

bool Tablica::remove(int idx){

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
	Tablica *t = new Tablica();
	int *tab;
	int i=0;
	fstream plik;
	string sizee;
	
	plik.open( "liczby.txt" );
	getline(plik, sizee);
	size=atoi(sizee.c_str());
	tab=new int[size];

	while( !plik.eof() )
	{
   
		plik>>tablica[i];
		/*t->add(tab[i]);*/
		i++;
	}
plik.close();



}

bool Tablica::Find(int a)
{
	int t=0;
	for(int i=0; i<size; i++)
		if(tablica[i]==a)
			t++;
	if(t>0)
		return true;
	else
		return false;

			
}
