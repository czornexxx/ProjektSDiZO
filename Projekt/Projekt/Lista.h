#pragma once
// elementy cz¹stkowe listy zawieraj¹ wskaŸnik na nastêpny element.
// Lista jednokierunkowa z g³ow¹ oraz ogonem.
class Element{

private:	
	Element * wskaznik; 
	int wartosc;


public:	Element::Element(){}

public: Element::Element(int Value){
		
			wartosc = Value;
		}

public: Element::Element(int Value, Element *adres){

			wartosc = Value;
			wskaznik = wskaznik;
		}

public: bool setValue(int value){

			wartosc = value;
		}

public: int getValue(){

			return wartosc;
		}

public: void setWskaznik(Element *adres){

			wskaznik = adres;
		}

public: Element* getWskaznik(){

			return wskaznik;
		}
};

class Lista
{
private:
	Element *glowa;
	Element *ogon; 
	int size;

public:
	Lista(void);
	~Lista(void);

	void add(int value);
	bool add(int value, int idx);
	bool removeIndex(int idx);
	bool remove(int value);
	int getNrElementu(int value);
	Element * sprawdz(int value);
	int getSize();
	int getValue(int index);
	void wyswietl(); 
};


