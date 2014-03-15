#pragma once

class Wezel {

private:
	Wezel * ojciec;
	Wezel * prawyPotomek;
	Wezel * lewyPotomek;

	int wartosc; 

public: 
	Wezel(){
		
		ojciec = 0; 
		prawyPotomek = 0;
		lewyPotomek = 0;
	
		wartosc = 0;
	}

	Wezel(int Value){

		ojciec = 0; 
		prawyPotomek = 0;
		lewyPotomek = 0;
	
		wartosc = Value;
	}

	Wezel(int Value, Wezel *wskOjciec){

		ojciec = wskOjciec; 
		prawyPotomek = 0;
		lewyPotomek = 0;
	
		wartosc = Value;
	}

	Wezel(int Value, Wezel *wskOjciec, Wezel *wskLewyP){

		ojciec = wskOjciec; 
		prawyPotomek = 0;
		lewyPotomek = wskLewyP;
	
		wartosc = Value;
	}

	Wezel(int Value, Wezel *wskOjciec, Wezel *wskLewyP, Wezel *wskPrawyP){

		ojciec = wskOjciec; 
		prawyPotomek = wskPrawyP;
		lewyPotomek = wskLewyP;
	
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
};



class DrzewoRB
{
private: 
	Wezel *korzen;

public:
	DrzewoRB(void);
	~DrzewoRB(void);

	void add(int Value);
	void wyswietl();
	void wyswietlx(Wezel * wsk );
};

