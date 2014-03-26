#pragma once
#include "Biblioteki.h"

using namespace std;

class Wezel {

private:
	Wezel * ojciec;
	Wezel * prawyPotomek;
	Wezel * lewyPotomek;

	int wartosc; 
	char kolor;

public: 
	Wezel(){
		
		ojciec = 0; 
		prawyPotomek = 0;
		lewyPotomek = 0;
		kolor = 'R';
	
		wartosc = 0;
	}

	Wezel(int Value){

		ojciec = 0; 
		prawyPotomek = 0;
		lewyPotomek = 0;
		kolor = 'R';
	
		wartosc = Value;
	}

	Wezel(int Value, Wezel *wskOjciec){

		ojciec = wskOjciec; 
		prawyPotomek = 0;
		lewyPotomek = 0;
		kolor = 'R';
		
		wartosc = Value;
	}

	Wezel(int Value, Wezel *wskOjciec, Wezel *wskLewyP){

		ojciec = wskOjciec; 
		prawyPotomek = 0;
		lewyPotomek = wskLewyP;
		kolor = 'R';

		wartosc = Value;
	}

	Wezel(int Value, char Kolor, Wezel *wskOjciec, Wezel *wskLewyP, Wezel *wskPrawyP){

		ojciec = wskOjciec; 
		prawyPotomek = wskPrawyP;
		lewyPotomek = wskLewyP;
		if(Kolor == 'B' || Kolor == 'b' || Kolor == 'R' || Kolor == 'r')
			kolor = Kolor;
		else
			kolor = 'R';

		wartosc = Value;
	}


public:

	void setValue(int Value){

		wartosc = Value;
	}

	int getValue(){

		return wartosc;
	}

	void setWskOjciec(Wezel * wsk){

		ojciec = wsk;
	}

	Wezel * getWskOjciec(){

		return ojciec;
	}

	void setWskLewyP(Wezel * wsk){

		lewyPotomek = wsk;
	}

	Wezel * getWskLewyP(){

		return lewyPotomek;
	}

	void setWskPrawyP(Wezel * wsk){

		prawyPotomek = wsk;
	}

	Wezel * getWskPrawyP(){

		return prawyPotomek;
	}

	char getKolor(){

		return kolor;
	}

	bool setKolor(char Kolor){

		if(Kolor == 'B' || Kolor == 'b' || Kolor == 'R' || Kolor == 'r'){
			
			kolor = Kolor;
			return true; 
		}

		return false;
	}


};



class DrzewoRB
{
private: 
	Wezel *korzen;
	string cr,cl,cp;			  // £añcuchy do znaków ramek
	HANDLE hOut;

public:
	DrzewoRB(void);
	~DrzewoRB(void);

	void add(int Value);
	Wezel * wyszukaj(int Value);
	Wezel * nastepnik(Wezel * w);
	Wezel * minWezel(Wezel *w);
	void removeWezel(Wezel *x);
	void remove(int Value);
	void wyswietl();
	void rotacjaLewo(Wezel *A);
	void rotacjaPrawo(Wezel *A);

private:
	void wyswietly(string sp, string sn, Wezel * p);
};

