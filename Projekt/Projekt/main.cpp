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
			}
			czas.stop1();
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
			czasy[i] = czas.zwrocCzas();
		}
	}

	nazwaZapis.append(to_string(ilosc));
	nazwaZapis.append(".txt");

	zapiszDoPliku(nazwaZapis,czasy,5000);
}

void test(){

	dodajNaKoniecTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	dodajNaKoniecTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajNaKoniecTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajNaKoniecTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajNaKoniecTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Koniec dodawania na koniec tablicy" << endl;

	dodajNaPoczatekTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	dodajNaPoczatekTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajNaPoczatekTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajNaPoczatekTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajNaPoczatekTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone dodawanie na poczatek tablicy" << endl;

	dodajLosowoDoTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	dodajLosowoDoTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajLosowoDoTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajLosowoDoTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajLosowoDoTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone dodawanie losowe tablicy" << endl;

	usunLosowoZTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	usunLosowoZTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	usunLosowoZTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	usunLosowoZTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	usunLosowoZTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone usuwanie losowe z tablicy" << endl;

	usunZPoczatkuTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	usunZPoczatkuTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	usunZPoczatkuTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	usunZPoczatkuTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	usunZPoczatkuTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone usuwanie z poczatek tablicy" << endl;

	usunZKoncaTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	usunZKoncaTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	usunZKoncaTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	usunZKoncaTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	usunZKoncaTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone usuwanie z konca tablicy" << endl;

	wyszukajWTablicy(100);
		cout << "Koniec 100 elementow" << endl;
	wyszukajWTablicy(1000);
		cout << "Koniec 1000 elementow" << endl;
	wyszukajWTablicy(5000);
		cout << "Koniec 5000 elementow" << endl;
	wyszukajWTablicy(10000);
		cout << "Koniec 10000 elementow" << endl;
	wyszukajWTablicy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone operacje na tablicy tablicy" << endl;
////	**********************	KONIEC TABLICY *****************	

	
	dodajNaKoniecListy(100);
		cout << "Koniec 100 elementow" << endl;
	dodajNaKoniecListy(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajNaKoniecListy(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajNaKoniecListy(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajNaKoniecListy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone dodawanie na koniec listy" << endl;

	dodajNaPoczatekListy(100);
		cout << "Koniec 100 elementow" << endl;
	dodajNaPoczatekListy(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajNaPoczatekListy(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajNaPoczatekListy(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajNaPoczatekListy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone dodawanie na poczatek listy" << endl;

	dodajLosowoDoListy(100);
		cout << "Koniec 100 elementow" << endl;
	dodajLosowoDoListy(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajLosowoDoListy(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajLosowoDoListy(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajLosowoDoListy(20000);
		cout << "Koniec 20000 elementow" << endl;

			cout << "Zakoñczone dodawanie losowo do listy" << endl;

	UsunZKoncaListy(100);
		cout << "Koniec 100 elementow" << endl;
	UsunZKoncaListy(1000);
		cout << "Koniec 1000 elementow" << endl;
	UsunZKoncaListy(5000);
		cout << "Koniec 5000 elementow" << endl;
	UsunZKoncaListy(10000);
		cout << "Koniec 10000 elementow" << endl;
	UsunZKoncaListy(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone usuwania z konca listy" << endl;

	UsunZPoczatekListy(100);
		cout << "Koniec 100 elementow" << endl;
	UsunZPoczatekListy(1000);
		cout << "Koniec 1000 elementow" << endl;
	UsunZPoczatekListy(5000);
		cout << "Koniec 5000 elementow" << endl;
	UsunZPoczatekListy(10000);
		cout << "Koniec 10000 elementow" << endl;
	UsunZPoczatekListy(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone usuwania z poczatku listy" << endl;

	UsunLosowoZListy(100);
		cout << "Koniec 100 elementow" << endl;
	UsunLosowoZListy(1000);
		cout << "Koniec 1000 elementow" << endl;
	UsunLosowoZListy(5000);
		cout << "Koniec 5000 elementow" << endl;
	UsunLosowoZListy(10000);
		cout << "Koniec 10000 elementow" << endl;
	UsunLosowoZListy(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone usuwania losowo z listy" << endl;

	wyszukajWLiscie(100);
		cout << "Koniec 100 elementow" << endl;
	wyszukajWLiscie(1000);
		cout << "Koniec 1000 elementow" << endl;
	wyszukajWLiscie(5000);
		cout << "Koniec 5000 elementow" << endl;
	wyszukajWLiscie(10000);
		cout << "Koniec 10000 elementow" << endl;
	wyszukajWLiscie(20000);
		cout << "Koniec 20000 elementow" << endl;
					cout << "Zakoñczone wyszukiwania elementow z listy" << endl;
 //********************************* Koniec Listy **************************
	//cout << "Dodawanie Start: " << endl;

<<<<<<< HEAD
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
=======
	dodajDoKopca(100);
		cout << "Koniec 100 elementow" << endl;
	dodajDoKopca(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajDoKopca(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajDoKopca(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajDoKopca(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone dodawanie do kopca" << endl;

	usunZKopca(100);
		cout << "Koniec 100 elementow" << endl;
	usunZKopca(1000);
		cout << "Koniec 1000 elementow" << endl;
	usunZKopca(5000);
		cout << "Koniec 5000 elementow" << endl;
	usunZKopca(10000);
		cout << "Koniec 10000 elementow" << endl;
	usunZKopca(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone usuwania z kopca" << endl;

		cout << "Wyszukiwanie Start: " << endl;
	wyszukajWKopcu(100);	
		cout << "Koniec 100" << endl;
>>>>>>> robocza
	wyszukajWKopcu(1000);
		cout << "Koniec 1000" << endl;
	wyszukajWKopcu(5000);
		cout << "Koniec 5000" << endl;
	wyszukajWKopcu(10000);
		cout << "Koniec 10000 elementow" << endl;
	wyszukajWKopcu(20000);
		cout << "Koniec 20000 elementow" << endl;
				cout << "Zakoñczone wyszukiwania w kopcu" << endl;

// ******************************** Koniec Kopca ***************************
	dodajDoDrzewa(100);
		cout << "Koniec 100 elementow" << endl;
	dodajDoDrzewa(1000);
		cout << "Koniec 1000 elementow" << endl;
	dodajDoDrzewa(5000);
		cout << "Koniec 5000 elementow" << endl;
	dodajDoDrzewa(10000);
		cout << "Koniec 10000 elementow" << endl;
	dodajDoDrzewa(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone dodawanie do drzewa" << endl;

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

				cout << "Zakoñczone usuwania z drzewa" << endl;

	wyszukajWDrzewie(100);
		cout << "Koniec 100 elementow" << endl;
	wyszukajWDrzewie(1000);
		cout << "Koniec 1000 elementow" << endl;
	wyszukajWDrzewie(5000);
		cout << "Koniec 5000 elementow" << endl;
	wyszukajWDrzewie(10000);
		cout << "Koniec 10000 elementow" << endl;
	wyszukajWDrzewie(20000);
		cout << "Koniec 20000 elementow" << endl;

				cout << "Zakoñczone wyszukiwania w drzewie" << endl;
}

void menuTablica(){

	char znak;
	Tablica tab;
	string nazwa;
	int liczba, index;
	system("cls");
	
	do{	
		std::system("cls");

		cout << "MENU Tablica" << endl << endl;
		cout << "1 -> Wczytaj z pliku" << endl;
		cout << "2 -> Usun" << endl;
		cout << "3 -> Dodaj" << endl;
		cout << "4 -> Znajdz" << endl;
		cout << "5 -> Wyswietl" << endl;
		cout << "k -> MENU" << endl << endl;
		cout << "Dokonaj wyboru: ";
		cin >> znak;

		switch(znak){
			
		case '1': 
			{
					std::system("cls");

					cout << "Wczytaj z pliku. Podaj nazwê pliku, lub sciezke do plikow przykladowych np: 'dane/liczby100.txt'" << endl;
					cout << "Podaj nazwe pliku: ";
					cin >> nazwa;

					fstream plik(nazwa);
					plik >> n;	
					int x;
			
					for(int i=0; i<n; i++){
						plik >> x;
						tab.add(x);
					}
	
				plik.close();
				cout << "Poprawnie wczytano: " << n << " liczb. " << endl;
				std::getchar();
				std::getchar();
			}
				break;
		case '2':
			std::system("cls");
			cout << "Podaj indeks do usuniecia: (indeks z przedzialu 1 do n) ";
			cin >> liczba;

			if(tab.removeIndex(liczba))
				cout << "Poprawnie usunieto liczbe." << endl;
			else
				cout << "Usuniecie liczby nie powiodlo sie. Brak indeksu w tablicy!" << endl;
			std::getchar(); std::getchar();
			break;
		case '3':
			std::system("cls");
			cout << "Dodaj liczbe podaj indeks(1-n) oraz wartosc " << endl;
			cout << "Podaj indeks z przedzialu: 1 - " << (tab.getSize() +1 ) << " : ";
			cin >> index;
			cout << "Podaj wartosc elementu do wstawienia: ";
			cin >> liczba;
			if(index <1 || index > (tab.getSize()+1)){
				cout << "Niepoprawny indeks. Zostanie zmieniony na 1 element tablicy" << endl;
				index = 1;
			}
			tab.add(liczba,index);
			cout << "Dodano: " << liczba << " na pozycji: " << index;
			std::getchar(); std::getchar();
				break;
		case '4': 
			std::system("cls");
			cout << "Podaj liczbê do wyszukania: ";
			cin >> liczba;
			if(tab.sprawdz(liczba))
				cout << "Liczba jest w kolekcji." << endl;
			else
				cout << "Brak liczby w kolekcji." << endl;
			std::getchar(); std::getchar();
				break;
		case '5': 
			std::system("cls");
			tab.wyswietl();
			std::getchar(); std::getchar();
				break;
		case 'k': 
				break;
		};
	}while(znak != 'k');

	std::system("cls");
}

void menuLista(){

	char znak;
	string nazwa;
	int liczba,liczIndex;
	Lista lista;

	do{	
		std::system("cls");
		cout << "MENU Lista" << endl << endl;
		cout << "1 -> Wczytaj z pliku" << endl;
		cout << "2 -> Usun" << endl;
		cout << "3 -> Dodaj" << endl;
		cout << "4 -> Znajdz" << endl;
		cout << "5 -> Wyswietl" << endl;
		cout << "k -> MENU" << endl << endl;
		cout << "Dokonaj wyboru: ";
		cin >> znak;

		switch(znak){
			
		case '1': 

			{
					std::system("cls");

					cout << "Wczytaj z pliku. Podaj nazwê pliku, lub sciezke do plikow przykladowych np: 'dane/dane100.txt'" << endl;
					cout << "Podaj nazwe pliku: ";
					cin >> nazwa;

					fstream plik(nazwa);
					plik >> n;	
					int x;
			
					for(int i=0; i<n; i++){
						plik >> x;
						lista.add(x);
					}
	
				plik.close();
				cout << "Poprawnie wczytano: " << n << " liczb. " << endl;
				std::getchar();
				std::getchar();

			}
				break;
		case '2':
			std::system("cls");
			cout << "Podaj liczbe do usuniêcia: ";
			cin >> liczba;

			if(lista.remove(liczba))
				cout << "Poprawnie usunieto liczbe.  " << lista.getSize() << endl;
			else
				cout << "Usuniecie liczby nie powiodlo sie. Brak liczby! " << lista.getSize() << endl;
			std::getchar(); std::getchar();
			break;
		case '3':
			std::system("cls");
			cout << "Podaj liczby do wstawienia" << endl;
			cout << "Podaj wartosc za ktora wstawic: ";
			cin >> liczIndex;
			cout << "Podaj liczbe do wstawienia: ";
			cin >> liczba;

			if(lista.getNrElementu(liczIndex) == -1){
				cout << "Brak liczby, zostanie wstawiona na poczatku." << endl;
				liczIndex = 1;
				lista.add(liczba,0);
			}
			else
				lista.add(liczba,lista.getNrElementu(liczIndex));
			cout << "Dodano: " << liczba;
			std::getchar(); std::getchar();
				break;
		case '4': 
			std::system("cls");
			cout << "Podaj liczbe do wyszukania: ";
			cin >> liczba;
			if(lista.sprawdz(liczba))
				cout << "Liczba jest w tablicy." << endl;
			else
				cout << "Brak liczby w tablicy." << endl;
			std::getchar(); std::getchar();
				break;
		case '5': 
			std::system("cls");
			lista.wyswietl();
			std::getchar(); std::getchar();
				break;
		case 'k': 
				break;
		};

	}while(znak != 'k');


	system("cls");
}

void menuKopiec(){

	char znak;
	string nazwa;
	Heap kopiec;
	int liczba;
	system("cls");

	do{

		std::system("cls");
		cout << "MENU Lista" << endl << endl;
		cout << "1 -> Wczytaj z pliku:" << endl;
		cout << "2 -> Usun" << endl;
		cout << "3 -> Dodaj" << endl;
		cout << "4 -> Znajdz" << endl;
		cout << "5 -> Wyswietl" << endl;
		cout << "k -> MENU" << endl << endl;
		cout << "Dokonaj wyboru: ";
		cin >> znak;

		switch(znak){
			
		case '1': 
			{
					std::system("cls");

					cout << "Wczytaj z pliku. Podaj nazwê pliku, lub sciezke do plikow przykladowych np: 'dane/liczby100.txt'" << endl;
					cout << "Podaj nazwe pliku: ";
					cin >> nazwa;

					fstream plik(nazwa);
					plik >> n;	
					int x;
			
					for(int i=0; i<n; i++){
						plik >> x;
						kopiec.Add(x);
					}
	
				plik.close();
				cout << "Poprawnie wczytano: " << n << " liczb. " << endl;
				std::getchar();
				std::getchar();

			}
				break;
		case '2':
			std::system("cls");
			cout << "Podaj liczbe do usuniêcia: ";
			cin >> liczba;

			if(kopiec.Search(liczba)){
				kopiec.Remove(liczba);
				cout << "Poprawnie usunieto liczbe." << endl;
			}
			else
				cout << "Usuniecie liczby nie powiodlo sie. Brak liczby!" << endl;
			std::getchar(); std::getchar();
			break;
		case '3':
			std::system("cls");
			cout << "Podaj liczbê do dodania: ";
			cin >> liczba;
			kopiec.Add(liczba);
			cout << "Dodano: " << liczba;
			std::getchar(); std::getchar();
				break;
		case '4': 
			std::system("cls");
			cout << "Podaj liczbe do wyszukania: ";
			cin >> liczba;
			if(kopiec.Search(liczba))
				cout << "Liczba jest w tablicy." << endl;
			else
				cout << "Brak liczby w tablicy." << endl;
			std::getchar(); std::getchar();
				break;
		case '5': 
			std::system("cls");
			kopiec.Write("","",0);
			std::getchar(); std::getchar();
				break;
		case 'k': 
				break;
		};

	}while(znak != 'k');

	system("cls");
}

void menuDrzewo(){

	char znak;
	int liczba;
	DrzewoRB drzewo;
	string nazwa;

	do{	
		std::system("cls");	
		cout << "MENU Drzewo" << endl << endl;
		cout << "1 -> Wczytaj z pliku:" << endl;
		cout << "2 -> Usun" << endl;
		cout << "3 -> Dodaj" << endl;
		cout << "4 -> Znajdz" << endl;
		cout << "5 -> Wyswietl" << endl;
		cout << "k -> MENU" << endl << endl;
		cout << "Dokonaj wyboru: ";
		cin >> znak;

		switch(znak){
			
		case '1': 
			{
					std::system("cls");

					cout << "Wczytaj z pliku. Podaj nazwê pliku, lub sciezke do plikow przykladowych np: 'dane/liczby100.txt'" << endl;
					cout << "Podaj nazwe pliku: ";
					cin >> nazwa;

					fstream plik(nazwa);
					plik >> n;	
					int x;
			
					for(int i=0; i<n; i++){
						plik >> x;
						drzewo.add(x);
					}
	
				plik.close();
				cout << "Poprawnie wczytano: " << n << " liczb. " << endl;
				std::getchar();
				std::getchar();

			}
				break;
		case '2':
			std::system("cls");
			cout << "Podaj liczbe do usuniecia: ";
			cin >> liczba;

			if(drzewo.remove(liczba))
				cout << "Poprawnie usunieto liczbe." << endl;
			else
				cout << "Usuniecie liczby nie powiodlo sie. Brak liczby!" << endl;
			std::getchar(); std::getchar();
			break;
		case '3':
			std::system("cls");
			cout << "Podaj liczbê do dodania: ";
			cin >> liczba;
			drzewo.add(liczba);
			cout << "Dodano: " << liczba;
			std::getchar(); std::getchar();
				break;
		case '4': 
			std::system("cls");
			cout << "Podaj liczbê do wyszukania: ";
			cin >> liczba;
			if(drzewo.wyszukaj(liczba) != 0)
				cout << "Liczba jest w kolekcji." << endl;
			else
				cout << "Brak liczby w kolekcji." << endl;
			std::getchar(); std::getchar();
				break;
		case '5': 
			std::system("cls");
			drzewo.wyswietl();
			std::getchar(); std::getchar();
				break;
		case 'k': 
				break;
		};

	}while(znak != 'k');


	system("cls");
}

void menuTesty(){

		char znak;

	do{	
		system("cls");

		cout << "Testy wydajnosciowe!!!" << endl << endl;
		cout << "1 -> Info wazne!!!" << endl;
		cout << "2 -> Uruchom testy" << endl;
		cout << "k -> wyjscie" << endl << endl;
		cout << "Dokonaj wyboru: ";
		cin >> znak;

		switch(znak){
			
		case '1':
			cout << "Aby przeprowadzic testy nalezy folder przekopiowac na dysk aby bylo mozliwe zapisanie danych wynikowych";
			cout << " Testy ida dosc dlugo w zaleznosci od wydajnosci komputera. Sa przeprowadzane na danych nastepujacych wielkosci";
			cout << " 100, 1000, 5000, 10000, 20000 liczb. Aby zakonczyc testy przed ich samoczynnym zakoczeniem nalezy zamnac program";
				getchar(); getchar();
				break;
		case '2': 
			test();
				break;
		case 'k': 
				break;
		};

	}while(znak != 'k');

}

void menu(){

	char znak;

	do{	
		system("cls");

		cout << "MENU Projekt SDiZO 2014" << endl << endl;
		cout << "1 -> Tablica" << endl;
		cout << "2 -> Lista" << endl;
		cout << "3 -> Kopiec" << endl;
		cout << "4 -> Drzewo RB" << endl;
		cout << "5 -> TESTY - wydajnosciowe" << endl;
		cout << "k -> wyjscie" << endl << endl;
		cout << "Dokonaj wyboru: ";
		cin >> znak;

		switch(znak){
			
		case '1': menuTablica();
				break;
		case '2': menuLista();
				break;
		case '3': menuKopiec();
				break;
		case '4': menuDrzewo();
				break;
		case '5': menuTesty();
				break;
		case 'k': 
				break;
		};

	}while(znak != 'k');
}

int main(){

	menu();

	return 0;
}