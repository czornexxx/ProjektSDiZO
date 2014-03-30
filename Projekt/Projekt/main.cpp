#include "Biblioteki.h"

using namespace std;
int *liczby,n;

void Losuj(int n)
{   
	int p,i, licznik;
	bool t;
	liczby = new int[n];
	srand(time(NULL));
	licznik = 0;
    do
    {
        p = (rand()*rand())%(1000001) -500000;
		 	
        t = true;
        for(i = 0; i < licznik; i++)
            if(liczby[i] == p)
            {
                t = false;
                break;
            }

        if(t) liczby[licznik++] = p;

    } while(licznik < n);
}

void mieszaj()
{
	int *tmp = new int[n]; 
	int iterator = 0;
	int ntmp = n, losLiczba;
		
	srand(time(NULL));
	
	while(ntmp != 0){
			
		// losowanie liczby z przedzialu

		if(ntmp > 32767)
			losLiczba = rand();
		else
			losLiczba = rand()%(ntmp);

		// przeniesienie liczb

		tmp[iterator] = liczby[losLiczba];

		for(int i=losLiczba; i<ntmp; i++)
			liczby[i] = liczby[i+1];
		
		iterator ++;	
		ntmp --;
	}

	liczby = tmp;



fstream zapisz;
	zapisz.open("liczby2.txt", ios::out);

	zapisz<<n<<"\n";
	for(int i = 0; i<n; i++)
	{
		zapisz<<liczby[i]<<"\n";
	}
	zapisz.flush();
	zapisz.close();

}

void zapiszDoPliku(string nazwa, int *tab, int n){

	fstream plik;
	plik.open(nazwa,ios::out);

	plik << n << endl;
	for(int i=0; i<n; i++){

		plik << tab[i] << endl;
	}
	plik.close();
}

void zapiszDoPliku(string nazwa, double *tab, int n){

	fstream plik;
	plik.open(nazwa,ios::out);

	plik << n << endl;
	for(int i=0; i<n; i++){

		plik << tab[i] << endl;
	}
	plik.close();
}

void wczytajZPliku(string nazwa){

	fstream plik(nazwa);

	plik >> n;

	liczby = new int[n];
	
	for(int i=0; i<n; i++){
		plik >> liczby[i];
	}
	
	plik.close();
}

int wczytajDoTablicy(Tablica *tabkolekcja,int *tab, int n){

	Time czas;
	czas.start1();

	for(int i=0; i<n; i++)
		tabkolekcja->add(tab[i]);

	return czas.stop1();;
}

void generujLiczby(int n){


	Losuj(n);		// losowanie licz

	string nazwa = "dane/liczby";
	
	nazwa.append(to_string(n));
	nazwa.append(".txt");
	
	zapiszDoPliku(nazwa,liczby,n);

	cout << "Poprawnie zapisano w folderze dane "<< n << " liczb" << endl;
}

void dodajNaKoniecTablicy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/addkoniec" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Tablica tablica;
			czas.start1();
			for(int j=0; j<n; j++)
				tablica.add(liczby[j]);
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void dodajNaPoczatekTablicy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/addpoczatek" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Tablica tablica;
			czas.start1();
			for(int j=0; j<n; j++)
				tablica.add(liczby[j],1);
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void dodajLosowoDoTablicy(int ilosc){
	
	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/addlosowo" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			srand(time(NULL));
	
			Tablica tablica;
			czas.start1();
			for(int j=0; j<n; j++)
				tablica.add(liczby[j],(rand()%(j+1) +1));
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void usunLosowoZTablicy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/usunlosowo" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Tablica tablica;
			
			for(int j=0; j<n; j++)
				tablica.add(liczby[j]);
			
			mieszaj();	
			
			czas.start1();

			for(int j=0; j<n; j++)
				tablica.remove(liczby[j]);		

			czas.stop1();
			
			czasy[i] = czas.zwrocCzas();

			cout << tablica.getSize() << endl;
					// permutuje tablice danych
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void usunZPoczatkuTablicy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/usunzpoczatku" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Tablica tablica;
			
			for(int j=0; j<n; j++)
				tablica.add(liczby[j]);
			
			mieszaj();	
			
			czas.start1();

			for(int j=0; j<n; j++)
				tablica.removeIndex(1);		

			czas.stop1();
			
			czasy[i] = czas.zwrocCzas();

					// permutuje tablice danych
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void usunZKoncaTablicy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/usunzkonca" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Tablica tablica;
			
			for(int j=0; j<n; j++)
				tablica.add(liczby[j]);
			
			mieszaj();	
			
			czas.start1();

			for(int j=0; j<n; j++)
				tablica.removeIndex(tablica.getSize());		

			czas.stop1();
			
			czasy[i] = czas.zwrocCzas();

					// permutuje tablice danych
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
	
}

void wyszukajWTablicy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/tablica/wyszukajelement" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Tablica tablica;
			
			for(int j=0; j<n; j++)
				tablica.add(liczby[j]);
			
			mieszaj();	
			
			czas.start1();

			for(int j=0; j<n; j++)
				tablica.sprawdz(liczby[j]);		

			czas.stop1();
			
			czasy[i] = czas.zwrocCzas();

					// permutuje tablice danych
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
	
}

void dodajNaKoniecListy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/addkoniec" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Lista lista;
			czas.start1();
			for(int j=0; j<n; j++)
				lista.add(liczby[j]);		// dodanie na koniec listy
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void dodajNaPoczatekListy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/addpoczatek" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Lista lista;
			czas.start1();
			for(int j=0; j<n; j++)
				lista.add(liczby[j],0);		// dodanie na poczatek listy
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);

}

void dodajLosowoDoListy(int ilosc){
	
	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/addlosowo" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			srand(time(NULL));
	
			Lista lista;
			czas.start1();
			for(int j=0; j<n; j++)
				lista.add(liczby[j],(rand()%(j+1)));
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);

}

void UsunZKoncaListy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/usunkoniec" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Lista lista;
			
			for(int j=0; j<n; j++)
				lista.add(liczby[j]);		// dodanie na koniec listy
			
			czas.start1(); 
			for(int j=0; j<n; j++)
				lista.removeIndex(lista.getSize());
			czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
}

void UsunZPoczatekListy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/usunpoczatek" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Lista lista;
			
			for(int j=0; j<n; j++)
				lista.add(liczby[j]);		// dodanie na koniec listy
			
			czas.start1(); 
			for(int j=0; j<n; j++)
				lista.removeIndex(1);
			czas.stop1();

			czasy[i] = czas.zwrocCzas();
			cout << i << endl;
			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);


}

void UsunLosowoZListy(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/usunlosowo" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Lista lista;
			
			for(int j=0; j<n; j++)
				lista.add(liczby[j]);		// dodanie na koniec listy
			
			czas.start1(); 
			for(int j=0; j<n; j++)
				lista.removeIndex((rand()%lista.getSize()));
			czas.stop1();

			czasy[i] = czas.zwrocCzas();

			cout << i << endl;

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
}

void wyszukajWLiscie(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/lista/wyszukajelement" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Lista lista;
			
			for(int j=0; j<n; j++)
				lista.add(liczby[j],0);
			
			mieszaj();	
			
			czas.start1();

			for(int j=0; j<n; j++)
				lista.sprawdz(liczby[j]);		

			czas.stop1();
			
			cout << i << endl;

			czasy[i] = czas.zwrocCzas();

					// permutuje tablice danych
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
	
}

void dodajDoDrzewa(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/drzewo/add" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			DrzewoRB drzewo;
			czas.start1();
			for(int j=0; j<n; j++)
				drzewo.add(liczby[j]);
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);

}

void usunZDrzewa(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/drzewo/usun" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			DrzewoRB drzewo;
			
			for(int j=0; j<n; j++)
				drzewo.add(liczby[j]);		// dodanie na koniec listy
		
			mieszaj();			// permutuje tablice danych
			
			czas.start1(); 
			for(int j=0; j<n; j++)
				drzewo.remove(liczby[j]);
			czas.stop1();

			czasy[i] = czas.zwrocCzas();
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
}

void wyszukajWDrzewie(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/drzewo/wyszukaj" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			DrzewoRB drzewo;
			
			for(int j=0; j<n; j++)
				drzewo.add(liczby[j]);		// dodanie na koniec listy
		
			mieszaj();			// permutuje tablice danych
			
			czas.start1(); 
			for(int j=0; j<n; j++)
				drzewo.wyszukaj(liczby[j]);
			czas.stop1();

			czasy[i] = czas.zwrocCzas();
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);
}

void dodajDoKopca(int ilosc){

	Time czas;
	double czasy[100];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/kopiec/add" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Heap kopiec;
			czas.start1();
			for(int j=0; j<n; j++)
				kopiec.Add(liczby[j]);
			 czas.stop1();

			czasy[i] = czas.zwrocCzas();

			mieszaj();			// permutuje tablice danych
		
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,100);

}

void usunZKopca(int ilosc){

	Time czas;
	double czasy[10];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/kopiec/usun" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<10; i++){

		{
			Heap kopiec;
			
			for(int j=0; j<n; j++)
				kopiec.Add(liczby[j]);		// dodanie na koniec listy
		
			mieszaj();			// permutuje tablice danych
			
			czas.start1(); 
			for(int j=0; j<n; j++){
				kopiec.Remove(liczby[j]);
				cout << j << endl;
			}
			czas.stop1();
			cout << "Caly koniec: " << i << endl;
			czasy[i] = czas.zwrocCzas();
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,10);
}

void wyszukajWKopcu(int ilosc){

	Time czas;
	double czasy[5000];
	// ilosc elementow wybieramy z {1000, 10000, 50000, 100000, 300000}
	string nazwaZapis = "wyniki/kopiec/wyszukaj" ;
	string nazwaOdczyt = "dane/liczby";
	nazwaOdczyt.append(to_string(ilosc));
	nazwaOdczyt.append(".txt");

	wczytajZPliku(nazwaOdczyt); 

	for(int i=0; i<100; i++){

		{
			Heap kopiec;
			
			for(int j=0; j<n; j++)
				kopiec.Add(liczby[j]);		// dodanie na koniec listy
		
			mieszaj();			// permutuje tablice danych
			
			czas.start1(); 
				kopiec.Search(liczby[rand() % ilosc]);  // wyszukiwanie losowo wybranego elementu
			czas.stop1();
			cout << i << endl; 
			czasy[i] = czas.zwrocCzas();
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,5000);
}

void test(){

//	dodajNaKoniecTablicy(100);
//	dodajNaKoniecTablicy(1000);
//	dodajNaKoniecTablicy(5000);
//	dodajNaKoniecTablicy(10000);
//	dodajNaKoniecTablicy(20000);
//
//	cout << "koniec dodawania na koniec tablicy" << endl;
//
//	dodajNaPoczatekTablicy(100);
//	dodajNaPoczatekTablicy(1000);
//	dodajNaPoczatekTablicy(5000);
//	dodajNaPoczatekTablicy(10000);
//	dodajNaPoczatekTablicy(20000);
//
//	cout << "Zakoñczone dodawanie na poczatek tablicy" << endl;
//
//	dodajLosowoDoTablicy(100);
//	dodajLosowoDoTablicy(1000);
//	dodajLosowoDoTablicy(5000);
//	dodajLosowoDoTablicy(10000);
//	dodajLosowoDoTablicy(20000);
//
//		cout << "Zakoñczone dodawanie losowe tablicy" << endl;
//
//	usunLosowoZTablicy(100);
//	usunLosowoZTablicy(1000);
//	usunLosowoZTablicy(5000);
//	usunLosowoZTablicy(10000);
//	usunLosowoZTablicy(20000);
//
//		cout << "Zakoñczone usuwanie losowe z tablicy" << endl;
//
//	usunZPoczatkuTablicy(100);
//	usunZPoczatkuTablicy(1000);
//	usunZPoczatkuTablicy(5000);
//	usunZPoczatkuTablicy(10000);
//	usunZPoczatkuTablicy(20000);
//
//		cout << "Zakoñczone usuwanie z poczatek tablicy" << endl;
//
//	usunZKoncaTablicy(100);
//		cout << "Koniec 100 elementow" << endl;
//	usunZKoncaTablicy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	usunZKoncaTablicy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	usunZKoncaTablicy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	usunZKoncaTablicy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//			cout << "Zakoñczone usuwanie z konca tablicy" << endl;
//
//	wyszukajWTablicy(100);
//		cout << "Koniec 100 elementow" << endl;
//	wyszukajWTablicy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	wyszukajWTablicy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	wyszukajWTablicy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	wyszukajWTablicy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//			cout << "Zakoñczone operacje na tablicy tablicy" << endl;
////	**********************	KONIEC TABLICY *****************	
//
//	
//	dodajNaKoniecListy(100);
//		cout << "Koniec 100 elementow" << endl;
//	dodajNaKoniecListy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	dodajNaKoniecListy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	dodajNaKoniecListy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	dodajNaKoniecListy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//			cout << "Zakoñczone dodawanie na koniec listy" << endl;
//
//	dodajNaPoczatekListy(100);
//		cout << "Koniec 100 elementow" << endl;
//	dodajNaPoczatekListy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	dodajNaPoczatekListy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	dodajNaPoczatekListy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	dodajNaPoczatekListy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//	dodajLosowoDoListy(100);
//		cout << "Koniec 100 elementow" << endl;
//	dodajLosowoDoListy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	dodajLosowoDoListy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	dodajLosowoDoListy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	dodajLosowoDoListy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//	UsunZKoncaListy(100);
//		cout << "Koniec 100 elementow" << endl;
//	UsunZKoncaListy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	UsunZKoncaListy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	UsunZKoncaListy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	UsunZKoncaListy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//	UsunZPoczatekListy(100);
//		cout << "Koniec 100 elementow" << endl;
//	UsunZPoczatekListy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	UsunZPoczatekListy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	UsunZPoczatekListy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	UsunZPoczatekListy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//	UsunLosowoZListy(100);
//		cout << "Koniec 100 elementow" << endl;
//	UsunLosowoZListy(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	UsunLosowoZListy(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	UsunLosowoZListy(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	UsunLosowoZListy(20000);
//		cout << "Koniec 20000 elementow" << endl;
//
//	wyszukajWLiscie(100);
//		cout << "Koniec 100 elementow" << endl;
//	wyszukajWLiscie(1000);
//		cout << "Koniec 1000 elementow" << endl;
//	wyszukajWLiscie(5000);
//		cout << "Koniec 5000 elementow" << endl;
//	wyszukajWLiscie(10000);
//		cout << "Koniec 10000 elementow" << endl;
//	wyszukajWLiscie(20000);
//		cout << "Koniec 20000 elementow" << endl;

 //********************************* Koniec Listy **************************
	//cout << "Dodawanie Start: " << endl;

	//dodajDoKopca(100);
	//	cout << "Koniec 100 elementow" << endl;
	//dodajDoKopca(1000);
	//	cout << "Koniec 1000 elementow" << endl;
	//dodajDoKopca(5000);
	//	cout << "Koniec 5000 elementow" << endl;
	//dodajDoKopca(10000);
	//	cout << "Koniec 10000 elementow" << endl;
	//dodajDoKopca(20000);
	//	cout << "Koniec 20000 elementow" << endl;

	//cout << "Usuwanie Start: " << endl;

	//usunZKopca(100);
	//	cout << "Koniec 100 elementow" << endl;
	//usunZKopca(1000);
	//	cout << "Koniec 1000 elementow" << endl;
	//usunZKopca(5000);
	//	cout << "Koniec 5000 elementow" << endl;
	//usunZKopca(10000);
	//	cout << "Koniec 10000 elementow" << endl;
	//usunZKopca(20000);
	//	cout << "Koniec 20000 elementow" << endl;

	cout << "Wyszukiwanie Start: " << endl;
	wyszukajWKopcu(100);	
	cout << "Koniec 100" << endl;
	wyszukajWKopcu(1000);
		cout << "Koniec 1000" << endl;
	wyszukajWKopcu(5000);
		cout << "Koniec 5000" << endl;
	wyszukajWKopcu(10000);
		cout << "Koniec 10000 elementow" << endl;
	wyszukajWKopcu(20000);
		cout << "Koniec 20000 elementow" << endl;

// ******************************** Koniec Kopca ***************************
	/*dodajDoDrzewa(100);
		cout << "Koniec 100 elementow" << endl;
	dodajDoDrzewa(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajDoDrzewa(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajDoDrzewa(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajDoDrzewa(20000);
		cout << "Koniec 20000 elementow" << endl;


	usunZDrzewa(100);
		cout << "Koniec 100 elementow" << endl;
	usunZDrzewa(1000);
		cout << "Koniec 1000 elementow" << endl;
	usunZDrzewa(5000);
		cout << "Koniec 5000 elementow" << endl;
	usunZDrzewa(10000);
		cout << "Koniec 10000 elementow" << endl;
	usunZDrzewa(20000);
		cout << "Koniec 20000 elementow" << endl;


	wyszukajWDrzewie(100);
		cout << "Koniec 100 elementow" << endl;
	wyszukajWDrzewie(1000);
		cout << "Koniec 1000 elementow" << endl;
	wyszukajWDrzewie(5000);
		cout << "Koniec 5000 elementow" << endl;
	wyszukajWDrzewie(10000);
		cout << "Koniec 10000 elementow" << endl;
	wyszukajWDrzewie(20000);
		cout << "Koniec 20000 elementow" << endl;*/
	
}


int main(){

	test();
	
	/*Heap H;

	Time t;
	Heap H;
	t.start1();

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

	srand(time(NULL));
	Tablica t;
	Lista l;
	DrzewoRB d;                  
	Time t1, t2, t3;

	int tablica[1000];

	int i;
	for(i=0; i<1000; i++)
		tablica[i] = rand();

		zapiszDoPliku("plik.txt",tablica,i);


	//d.wyswietl();

	//d.rotacjaPrawo(d.wyszukaj(4));

	//d.wyswietl();


	//l.wyswietl();


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