#include "Lista.h"
#include <iostream>

Lista::Lista(void)
{	
	size = 0;
}


Lista::~Lista(void)
{
}

void Lista::add(int value){

	Element *nowy = new Element(value);

	if(size == 0){		// jeœli nie ma elementow to przypisz do glowy
		
		glowa = nowy;
		ogon = nowy;
	}
	else{				// ustawienie ogona na nowy element, ostatni element wskazuje na nowy
		
		ogon->setWskaznik(nowy);
		ogon = nowy; 
	}	

	size ++; 
}

int Lista::getSize(){
	
	return size;
}

int Lista::getValue(int index){

	int tmpWartosc = 0;
	Element *tmpWskaznik = glowa;
	
	if(index > 0 && index <= size);		// sprawdzenie indexu
	
	for(int i=1; i<= size; i++){

		if(i == index){							    // jesli ten nr. to daj wartosc

			tmpWartosc = tmpWskaznik->getValue();
			break;
		}		
		
		tmpWskaznik = tmpWskaznik->getWskaznik();	// przeskakuj po elementach listy
	}

	return tmpWartosc;
}

void Lista::wyswietl(){

	Element *tmpwsk;
	tmpwsk = glowa;

	for(int i=0; i<size; i++){
		std::cout << tmpwsk->getValue() << std::endl;
		tmpwsk = tmpwsk->getWskaznik();
	}

}

bool Lista::add(int value, int idx){

	if(idx <=0 || idx > size)		// jesli index z poza zakresu to false;
		return false;

	Element *nowy = new Element(value);

	Element *tmpWskaznik;
	tmpWskaznik = glowa;

	for(int i=1; i<=size; i++){

		if(i = idx)
			break;
		tmpWskaznik = tmpWskaznik->getWskaznik();
	}

	nowy->setWskaznik(tmpWskaznik->getWskaznik());		// zapsanie wskaznika do nowego elementu

	tmpWskaznik->setWskaznik(nowy);						// ustawienie wsk elementu na nowy

	size ++;											// zwiekszenie rozmiaru listy

	return true;
}

bool Lista::remove(int idx){

	if(idx <=0 || idx > size)		// jesli index z poza zakresu to false;
		return false;

	Element *tmpWskaznik;
	tmpWskaznik = glowa;

	if(idx == 1)				// jesli rowne 1 elementowi (zmiana glowy)
		glowa = glowa->getWskaznik();
	else if(idx == size){

		for(int i=1; i<size-1; i++)
			tmpWskaznik = tmpWskaznik->getWskaznik();

		ogon = tmpWskaznik;
	}
	else{

		tmpWskaznik = glowa;

		for(int i=2; i<= size; i++){	
	
			if(i == idx)
				break;
			tmpWskaznik = tmpWskaznik->getWskaznik();	
		}

		tmpWskaznik->setWskaznik((tmpWskaznik->getWskaznik())->getWskaznik());	// ominiecie el.
	}
	size --; 
	return true;
}

bool Lista::sprawdz(int value){

	bool tmp = false;
	Element *tmpWskaznik;
	tmpWskaznik = glowa;

	for(int i=0; i<size; i++){

		if((tmpWskaznik->getValue()) == value){

			tmp = true;
			break;
		}

		tmpWskaznik = tmpWskaznik->getWskaznik();
	}

	return tmp;
}

