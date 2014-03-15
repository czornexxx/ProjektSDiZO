#include "DrzewoRB.h"
#include <iostream>


DrzewoRB::DrzewoRB(void)
{
}


DrzewoRB::~DrzewoRB(void)
{
}

void DrzewoRB::add(int Value){

	Wezel *tmpWezel;

	Wezel *nowy = new Wezel(Value);

	if(korzen == 0)	{			// jesli to pierwszy element to dodaj jako korzen
	
		korzen = nowy;
	}

	else{	
	
		tmpWezel = korzen;

		while(tmpWezel != 0){

 			if(tmpWezel->getValue() > Value){                  // jesli prawy wiekszy niz lewy to przejdz na lewy
					
				if(tmpWezel->getWskLewyP() == 0){			   // jesli brak elementu na lisciu
				
					tmpWezel->setWskLewyP(nowy);				// jesli znalazlem wolne miejsce to ustawiam ojca i lewy potomek
					nowy->setWskOjciec(tmpWezel);
					break;
				}
				else
					tmpWezel = tmpWezel->getWskLewyP();
			}
			else {												// jesli wartosc wieksza to na prawo
				

				if(tmpWezel->getWskPrawyP() == 0){			   // jesli brak elementu na lisciu
				
					tmpWezel->setWskPrawyP(nowy);				// jesli znalazlem wolne miejsce to ustawiam ojca i prawy potomek
					nowy->setWskOjciec(tmpWezel);
					break;
				}
				else
					tmpWezel = tmpWezel->getWskPrawyP();
			}
		}
	
	}
	
}

void DrzewoRB::wyswietl(){

	wyswietlx(korzen);

}

void DrzewoRB::wyswietlx(Wezel *wsk){

	std::cout << wsk->getValue() << " : Left-> ";
	if(wsk->getWskLewyP()) std::cout << wsk->getWskLewyP()->getValue();
	 else        std::cout << "NIL";
  std::cout << ", Right-> ";
  if(wsk->getWskPrawyP()) std::cout << wsk->getWskPrawyP()->getValue();
	 else         std::cout << "NIL";
  std::cout << std::endl;
  if(wsk->getWskLewyP())  wyswietlx(wsk->getWskLewyP());
  if(wsk->getWskPrawyP()) wyswietlx(wsk->getWskPrawyP());

}


