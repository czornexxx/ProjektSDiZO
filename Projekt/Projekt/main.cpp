#include "Biblioteki.h"


using namespace std;

int main(){
<<<<<<< HEAD
	Time t;
	Heap H;
	t.start1();
	H.ReadFromFile();
	H.BuildHeap();
	H.Add(33);
	H.Write();
	H.RemoveRoot();
	H.Write();
	if(H.Search(11))
		cout<<"\nW kopcu znajduje sie szukana liczba\n";
	else cout<<"\nW kopcu NIE znajduje sie szukana liczba\n";
	t.stop1();
	t.Print();
	/*char c,ch,cch;
	Time A;
	Tablica *t = new Tablica();
=======

	srand( time( NULL ) );
	DrzewoRB d;                  

	d.add(5);
	d.add(7);
	d.add(2);
	d.add(1);
	d.add(4);

	cout << d.wyszukaj(4) << endl;

	d.wyswietl();

	d.rotacjaLewo(d.wyszukaj(2));

	d.wyswietl();

	d.rotacjaPrawo(d.wyszukaj(4));

	d.wyswietl();


	//l.wyswietl();


	/*char c,ch,cch;
	Time A;
>>>>>>> 497e106a00f6f94f5f0af938b0512186ed58779b

	//char c,ch,cch;
	//Time A;
	//Tablica *t = new Tablica();
	 srand( time( NULL ) );
	DrzewoRB d;

	d.add(10);
	d.add(7);
	d.add(11);
	d.add(12);


	d.wyswietl();

	//cout << "Koniec" << endl;


<<<<<<< HEAD
=======
	
>>>>>>> 497e106a00f6f94f5f0af938b0512186ed58779b
	do{
		cout<<"Wybierz strukture: \n";
		cout<<"1 - tablica\n";
		cout<<"2 - lista\n";
		cout<<"3 - kopiec\n";
		cout<<"4 - drzewo czerwono-czarne";
		cin>>c;
		switch(c)
		{
		case '1' : do{
						cout<<"\nWybierz operacje\n";
						cout<<"1 - Wczytaj z pliku\n";
						cout<<"2 - Usun\n";
						cout<<"3 - Dodaj\n";
						cout<<"4 - Znajdz\n";				
						cout<<"5 - Wyswietl\n";
						cin>>(ch);
						switch(ch)
						{
						case '1' : t->wczytaj();
							
							break;
						case '2' :  do{
										cout<<"\nWybierz operacje\n";
										cout<<"1 - Usun pierwsz�\n";
										cout<<"2 - Usun ostatnia\n";
										cout<<"3 - Usun wybrana\n";
										cin>>cch;
										switch(cch)
										{
										case '1' : A.start1();
												   t->remove(0);
												   A.stop1();
												   A.Print();
									    break;
										case '2' : A.start1();
												   t->remove(9);
												   A.stop1();
												   A.Print();
										break;

										case '3' :  int ind;
													cout<<"\nPodaj indeks do usuni�cia\n";
													cin>>ind;
													A.start1();
													t->remove(ind);
													A.stop1();
													A.Print();
										break;
										default : cout<<"\n...\n";
										}
									}while(cch!='k');

							break;
						case '3' : 
							cout << "Podaj liczb� do dodania: ";
							int value, idx;
							cin >> value;
							cout << "Podaj index gdzie wstawi�: ";
							cin >> idx;
							 t->add(555);
							cout << endl << "wyswietlanie";
							t->wypisz();

							break;
						case '4' :  cout<<"Podaj liczbe do wyszukania";
									int a;
									bool x;
									cin>>a;
									A.start1();
									x=t->sprawdz(a);
									A.stop1();
									if(x==true)
										cout<<"\nLiczba znajduje sie w tablicy\n";
									else cout<<"\nLiczby nie ma w tablicy\n";
									
										A.Print();
									break;
						case '5' : t->wypisz();
							break;
						default : cout<<"powrot\n";
							break;
				   }
				   }while(ch!='k');
			
		break;
		default : cout<<"Koniec\n";
			break;
		}
	}while(c!='k');*/
	
	system("Pause");
	return 0;
}