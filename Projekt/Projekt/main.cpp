#include "Biblioteki.h"


using namespace std;
int *liczby,n;
void Losuj()
{   
	int p,i, licznik;
	bool t;
 	cout<<"Podaj iloœæ liczb (np. 1000,10000,20000...): ";
	cin>>n;
	liczby = new int[n];
	srand(time(NULL));
	licznik = 0;
    do
    {
        p = (rand()*rand())%(640001) -320000;
		 	
        t = true;
        for(i = 0; i < licznik; i++)
            if(liczby[i] == p)
            {
                t = false;
                break;
            }

        if(t) liczby[licznik++] = p;

    } while(licznik < n);

	fstream zapisz("liczby.txt", ios::out);

	zapisz<<n<<"\n";
	for(int i = 0; i<n; i++)
	{
		zapisz<<liczby[i]<<"\n";
	}
	zapisz.close();
}

void mieszaj()
{
	int t;
	bool z;
	int licznik = 0;
	int *tmp = new int[n];
	int size1 =n;
	
	srand(time(NULL));
	
	do{

		if(n>32767)
			t = rand();
		else 
			t = rand() %n+1;
		z = true;
		tmp[licznik] = liczby[t];
		
		
		licznik++;
		
		int *tmp2 = new int[n];
		for( int i = 0; i<t; i++)
			tmp2[i] = liczby[i];
		for (int i=t; i<n; i++)
			tmp2[i] = liczby[i+1];
		//delete [] liczby;
		liczby = new int[n];
		/*for(int i =0; i<n; i++)*/
			liczby=tmp2;
		
		n--;	
		//delete []tmp2;
	}while(n>0);
	/*for(int i = 0; i<size1; i++)*/
		liczby=tmp;
	
	//delete []tmp;
fstream zapisz;
	zapisz.open("liczby2.txt", ios::trunc | ios::out);

	zapisz<<size1<<"\n";
	for(int i = 0; i<size1; i++)
	{
		zapisz<<liczby[i]<<"\n";
	}
	zapisz.flush();
	zapisz.close();



}

int main(){

	Losuj();
	mieszaj();

	
	/*Heap H;
	H.ReadFromFile();
	H.BuildHeap();
	H.RemoveRoot();
	H.Write("","",0);
	cout<<endl<<endl;
	if(H.Search(11))
		cout<<"\nW kopcu znajduje sie szukana liczba\n";
	else cout<<"\nW kopcu NIE znajduje sie szukana liczba\n";
	H.Remove(4);
	H.Write("","",0);*/
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
										cout<<"1 - Usun pierwsz¹\n";
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
													cout<<"\nPodaj indeks do usuniêcia\n";
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
							cout << "Podaj liczbê do dodania: ";
							int value, idx;
							cin >> value;
							cout << "Podaj index gdzie wstawiæ: ";
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