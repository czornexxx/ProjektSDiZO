#include "Biblioteki.h"

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
	
	if(index > 0 && index <= size)				// sprawdzenie indexu

	
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
	
	if(size == 0){
		if(idx == 0 ){
			add(value);
			return true;
		}
		return false;
	}
	else if(size == 1){

		if(idx == 0){
			
			Element *nowy = new Element(value);
			glowa = nowy;
			glowa->setWskaznik(ogon);
			size ++;
			return true;
		}
		else if(idx == 1){

			Element *nowy = new Element(value);
			ogon = nowy;
			glowa->setWskaznik(ogon);
			size ++;
			return true;
		}
		return false;
	}

	if(idx == 0){

		Element *nowy = new Element(value);
		nowy->setWskaznik(glowa);
		glowa = nowy;
		size ++;
		return true;
	}

	if(idx <=0 || idx > size)
		return false;
	idx --;
	Element *nowy = new Element(value);

	Element *tmpWskaznik;
	tmpWskaznik = glowa;

	for(int i=0; i<size; i++){

		if(i == idx)
			break;
		tmpWskaznik = tmpWskaznik->getWskaznik();
	}

	nowy->setWskaznik(tmpWskaznik->getWskaznik());		// zapsanie wskaznika do nowego elementu
	tmpWskaznik->setWskaznik(nowy);		                // ustawienie wsk elementu na nowy
	
	size ++;											// zwiekszenie rozmiaru listy

	return true;
}

bool Lista::removeIndex(int idx){

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

bool Lista::remove(int value){

	if( size == 0 )
		return false;

	// jeœli jest 1 element w liœcie
	if( size == 1){

		if(glowa ->getValue() == value){
			
			size --;
			ogon = NULL;
			glowa = NULL;
			return true;
		}
		else
			return false;
	}

	if( size == 2 ){

		if(glowa->getValue() == value){

			size --;
			delete glowa;
			glowa = ogon;
			return true;
		}
		else if(ogon->getValue() == value){

			size --;
			delete ogon;
			ogon = glowa;
			return true;
		}
		return false;
	}

// jesli wiecej elementow 
	Element *tmp0 = glowa;
	Element *tmp1 = glowa->getWskaznik();

	if(value == glowa->getValue()){						
		glowa = glowa->getWskaznik();
		size --;
		return true;
	}

	while(tmp1->getValue() != value && tmp1->getWskaznik() != ogon){

		tmp0 = tmp1;
		tmp1 = tmp1->getWskaznik();
	}

	if(tmp1->getWskaznik() == ogon){
		if(ogon->getValue() == value){
			delete ogon;
			ogon = tmp1;
			size --;
			return true;
		}
	}
	else{
		tmp0->setWskaznik(tmp1->getWskaznik());
		delete tmp1;
		size --;
		return true;
	}
	return false;
}

Element * Lista::sprawdz(int value){

	bool tmp = false;
	Element *tmpWskaznik;
	tmpWskaznik = glowa;

	for(int i=0; i<size; i++){

		if((tmpWskaznik->getValue()) == value){
			
			return tmpWskaznik;
		}

		tmpWskaznik = tmpWskaznik->getWskaznik();
	}

	return 0;
}

