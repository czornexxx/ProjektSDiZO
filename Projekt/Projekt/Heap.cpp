#include "Biblioteki.h"

Heap::Heap(void) //konstrukote bezargumentowy ustalający początkowe parametry obiektu
{  
	size = 0;
	tab = new int[size];
}


Heap::~Heap(void) //destruktor usuwający dynamiczną tablice
{
	delete []tab;
}



void Heap::Add(int Value) //funkcja do dodawania wartości do kopca, argumentem jest wartość wstawiana do kopca
{   
	int a, tmp;
	
	size++;
	int *tab1=new int[size];//tworzymy tablicę o jeden większą w celu przechowywania poprzednich wartości wraz z nową
	
	for(int i = 0; i<size-1; i++)//przepisanie starej tablicy
		tab1[i]=tab[i];
	
	tab1[size-1] = Value; //dopisanie nowej wartości
	delete []tab; //usuwamy stara tablice
	tab = new int[size];//tworzymy główną tablice na nowo już powiększoną
	for(int i =0; i<size; i++)//przepisujemy wartości z tablicy pomocniczej do głównej
	tab[i]=tab1[i];
	delete []tab1;//kasujemy tablice pomociczą

	a=size-1;
	

	while(a > 0 && tab[a] > tab[(a-1)/2])//sprawdzanie czy są spelnione własności kopca
	{                                    //tj. sprawdzamy czy potomek nie jest większy od ojca 
		tmp = tab[a];                // jeśli tak następuje zamiana ich miejsc
		tab[a] = tab[(a-1)/2];
		tab[(a-1)/2] = tmp;
		a = (a-1)/2;
	}
}


void Heap::BuildHeap()//funkcja do przywracania własności kopca, korzystamy z niej gdy mamy już załadowanie wartości do tablicy
{                     //i należy je tylko odpowiednio poukładać
	for( int i = size/2; i>=0; i--)
		Heapify(i);

}

void Heap::Heapify(int i)//naprawianie struktury kopca
{
	int left = 2*i+1; //wartosc lewego syna
	int right = 2*i+2;// wartosc prawego syna
	int largest,tmp;


	if ( left <= size && tab[left] > tab[i])
		largest = left;
	else 							//sprawdzamy czy spełnione są warunki kopca
		largest = i;					//dokonujemy odpowiednich przeksztalcen
	if ( right <= size && tab[right] > tab[largest])
		largest = right;
	if ( largest != i)
	{
		tmp = tab[i];		//zamiana
		tab[i] = tab[largest];  //miejscami węzłów
		tab[largest] = tmp;
		Heapify(largest);//wywołujemy rekurencyjnie funkcje
	}

}

void Heap::RemoveRoot()//usuwanie korzenia z kopca
{
	int i,j,v;

  if(size--)
  {
    v = tab[size];//zapamietujemy ostani lisc kopca

    i = 0;
    j = 1;

    while(j < size)
    {
      if(j + 1 < size && tab[j + 1] > tab[j]) j++;
      if(v >= tab[j]) break;
      tab[i] = tab[j];
      i = j;
      j = 2 * j + 1;
    }//wstawiamy w miejsce naszego korzenia ostatni lisc i przywracamy własnosci kopca

    tab[i] = v;
  }

}


void Heap::ReadFromFile()// funkcja do bezpośredniego wczytania liczb z pliku do tablicy kopca
{
	fstream plik;
	string sizee;
	int i = 0;
	
	plik.open( "liczby.txt" );
	getline(plik, sizee);
	size= (atoi(sizee.c_str()));//wczytujemy pierwsza linie pliku która jest romiarem tablicy

	int *tablica = new int[size];
	for(int i=0; i< size; i++)
		tablica[i] = tab[i];

	delete[] tab;

	tab = tablica;

	

	while( !plik.eof() )
	{
   
		plik>>tab[i];//wczytanie kolejnych wartosci z pliku do tablicy
		i++;
	}

plik.close();

}

void Heap::Write(string sp, string sn, int v) //funkcja rysująca kopiec na ekranie
{
	string s;
	cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;

  if(v < size)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    Write(s + cp, cr, 2 * v + 2);

    s = s.substr(0,sp.length()-2);

    cout << s << sn << tab[v] << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    Write(s + cp, cl, 2 * v + 1);
  }
}


bool Heap::Search(int Value)//wyszukiwanie wartości Value w kopcu
{
	for( int i = size; i>=0; i--)
	{
		if(tab[0] == Value){//sprawdzamy czy nasz korzen zapisany w tab[0] to szukana wartośc
			return true;}//jesli tak, przerywamy funkcje, jeśli nie usuwamy korzen i szukamy dalej
		RemoveRoot();
	}
	return false;
}

void Heap::Remove(int Value)//funkcja do usuwania wartosci Value
{
	sizebuff=0;
	buff=new int[sizebuff]; //tworzymy tablice pomocnicza do przechowywania ściągniętych z kopca wartości
	for( int i = size; i>=0; i--)
	{
		if(tab[0] == Value)
		{RemoveRoot();break;//sprawdzamy czy korzeń jest naszą wartością do usunięcia
		}                   //jeśli tak to usuwamy go i kończymy
		else
			{AddBuff(tab[0]);//jeśli nie to zapisujemy jego wartość w tablicy pomocniczej i usuwamy go
			RemoveRoot();
		}

		}
	for (int i =sizebuff; i>0; i--)//po znalezieniu i usunieciu wartosci przepisujemy liczby z tablicy omocniczego do głownej
	{
		Add(buff[i-1]);
	}
	
	delete []buff;//usuwamy tablice pomocincza
	
}

void Heap::AddBuff(int Value)//funkcja do zapisywania wartości z kopca do tablicy pomocniczej
{
	int *tmp;
	
	tmp = new int[sizebuff + 1];//tablica pomocnicza dynamiczne zwiększana

	for(int i=0; i<sizebuff; i++)
		tmp[i] = buff[i];//przepisanie wartości do tmp z buff

	delete[] buff;

	tmp[sizebuff] = Value;//dopisanie nowej wartosci
	
	buff = tmp;

	sizebuff ++;//zwiekszenie rozmiaru tablicy pomocniczej
		
}
