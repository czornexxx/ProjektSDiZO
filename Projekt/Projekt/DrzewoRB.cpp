#include "DrzewoRB.h"


DrzewoRB::DrzewoRB(void)
{
  cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;

  hOut = GetStdHandle( STD_OUTPUT_HANDLE );
}


DrzewoRB::~DrzewoRB(void)
{
}

void DrzewoRB::add(int Value){

	Wezel *tmpWezel;

	Wezel *nowy = new Wezel(Value);
	nowy->setKolor('R');

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

// **** Przywracanie struktury drzewa RB *****
	Wezel * Y;
	tmpWezel = nowy;
	tmpWezel->setKolor('R');         // Wêze³ kolorujemy na czerwono

	while((tmpWezel != korzen) && (tmpWezel->getWskOjciec()->getKolor() == 'R'))  // jeœli rodzic jest czewony to przywracamy w³asnoœci drzewa RB
  {
    if(tmpWezel->getWskOjciec() == tmpWezel->getWskOjciec()->getWskOjciec()->getWskLewyP())
    {
      Y = tmpWezel->getWskOjciec()->getWskOjciec()->getWskPrawyP(); // Y -> wujek X

	
      if(Y != 0 && Y->getKolor() == 'R')  // Przypadek 1
      {
        tmpWezel->getWskOjciec()->setKolor('B');
        Y->setKolor('B');
		tmpWezel->getWskOjciec()->getWskOjciec()->setKolor('R');
		tmpWezel = tmpWezel->getWskOjciec()->getWskOjciec();
        continue;
      }

      if(tmpWezel == tmpWezel->getWskOjciec()->getWskPrawyP()) // Przypadek 2
      {
        tmpWezel = tmpWezel->getWskOjciec();
        rotacjaLewo(tmpWezel);
      }

      tmpWezel->getWskOjciec()->setKolor('B'); // Przypadek 3
      tmpWezel->getWskOjciec()->getWskOjciec()->setKolor('R');
	  rotacjaPrawo(tmpWezel->getWskOjciec()->getWskOjciec());
      break;
    }
    else
    {                  // Przypadki lustrzane
      Y = tmpWezel->getWskOjciec()->getWskOjciec()->getWskLewyP();

      if(Y != 0 && Y->getKolor() == 'R') // Przypadek 1
      {
        tmpWezel->getWskOjciec()->setKolor('B');
        Y->setKolor('B');
        tmpWezel->getWskOjciec()->getWskOjciec()->setKolor('R');
        tmpWezel = tmpWezel->getWskOjciec()->getWskOjciec();
        continue;
      }

      if(tmpWezel == tmpWezel->getWskOjciec()->getWskLewyP()) // Przypadek 2
      {
        tmpWezel = tmpWezel->getWskOjciec();
        rotacjaPrawo(tmpWezel);
      }

      tmpWezel->getWskOjciec()->setKolor('B'); // Przypadek 3
      tmpWezel->getWskOjciec()->getWskOjciec()->setKolor('R');
      rotacjaLewo(tmpWezel->getWskOjciec()->getWskOjciec());
      break;
    }
  }
  korzen->setKolor('B');
	
}

Wezel* DrzewoRB::wyszukaj(int Value){

	Wezel *tmpWezel = korzen;

	while( tmpWezel != 0){

		if(tmpWezel->getValue() == Value)			// jeœli równe to zwróæ wskaŸnik
			return tmpWezel;	

		if(tmpWezel->getValue() < Value){			// jeœli wartoœæ wieksza to idŸ na prawo
			
			if(tmpWezel->getWskPrawyP() != 0)		// sprawdzenie czy istnieje potomek			
				tmpWezel = tmpWezel->getWskPrawyP();
			else
				break;
		}
		if(tmpWezel->getValue() > Value){			// jesli wartosc mniejsza to na lewo

			if(tmpWezel->getWskLewyP() != 0 )			// sprawdzenie czy istnieje potomek
				tmpWezel = tmpWezel->getWskLewyP();
			else
				break;
		}
	}

	return 0;
}

void DrzewoRB::rotacjaLewo(Wezel *A){

  Wezel * B, * p;

  if(A == 0) return;

  B = A->getWskPrawyP();
  if(B != 0)
  {
	  p = A->getWskOjciec();
	  A->setWskPrawyP(B->getWskLewyP());
	  if(A->getWskPrawyP() != 0) 
		  A->getWskPrawyP()->setWskOjciec( A );

	  B->setWskLewyP(A);
	  B->setWskOjciec(p);
      A->setWskOjciec(B);

      if(p != 0)
      {
		  if(p->getWskLewyP() == A) 
			  p->setWskLewyP(B); 
		  else p->setWskPrawyP(B);
      }
    else korzen = B;
  }

}

void DrzewoRB::rotacjaPrawo(Wezel *A){

  Wezel * B, * p;

  if(A == 0) return;

  B = A->getWskLewyP();
  if(B != 0)
  {
    p = A->getWskOjciec();
    A->setWskLewyP(B->getWskPrawyP());
	if(A->getWskLewyP() != 0) A->getWskLewyP()->setWskOjciec(A);

    B->setWskPrawyP(A);
    B->setWskOjciec(p);
    A->setWskOjciec(B);

    if(p != 0)
    {
      if(p->getWskLewyP() == A) 
		  p->setWskLewyP(B); 
	  else p->setWskPrawyP(B);
    }
    else korzen = B;
  }

}

void DrzewoRB::wyswietl(){

	wyswietly("","",korzen);

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

void DrzewoRB::wyswietly(string sp, string sn, Wezel * p)
{
  string t;

    t = sp;
    if(sn == cr) t[t.length() - 2] = ' ';
	if(p->getWskPrawyP() != 0)
	wyswietly(t+cp,cr,p->getWskPrawyP());

    t = t.substr(0,sp.length()-2);
	
	SetConsoleTextAttribute( hOut, 0x0007);	
	cout << t << sn;
	if(p->getKolor() == 'R')
		SetConsoleTextAttribute( hOut, FOREGROUND_RED);
	
	cout<< p->getKolor() << ":" << p->getValue() << endl;

	SetConsoleTextAttribute( hOut, 0x0007);	

    t = sp;
    if(sn == cl) t[t.length() - 2] = ' ';
	if(p->getWskLewyP() != 0)
	wyswietly(t+cp,cl,p->getWskLewyP());
}

