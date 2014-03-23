#include "Biblioteki.h"

Heap::Heap(void)
{
	tab = new int[0];
	size = 0;
}


Heap::~Heap(void)
{
	delete []tab;
}

void Heap::Add(int Value)
{
	int tmp,a;
	size=size + 1;
	a = size-1;
	tab[a] = Value;

	while(a > 0 && tab[a] > tab[(a-1)/2])
	{
		tmp = tab[a];
		tab[a] = tab[(a-1)/2];
		tab[(a-1)/2] = tmp;
		a = (a-1)/2;
	}
}


void Heap::BuildHeap()
{
	for( int i = size/2; i>=0; i--)
		Heapify(i);

}

void Heap::Heapify(int i)
{
	int left = 2*i+1;
	int right = 2*i+2;
	int largest,tmp;


	if ( left <= size && tab[left] > tab[i])
		largest = left;
	else 
		largest = i;
	if ( right <= size && tab[right] > tab[largest])
		largest = right;
	if ( largest != i)
	{
		tmp = tab[i];
		tab[i] = tab[largest];
		tab[largest] = tmp;
		Heapify(largest);
	}

}

void Heap::RemoveRoot()
{
	int i,j,v;

  if(size--)
  {
    v = tab[size];

    i = 0;
    j = 1;

    while(j < size)
    {
      if(j + 1 < size && tab[j + 1] > tab[j]) j++;
      if(v >= tab[j]) break;
      tab[i] = tab[j];
      i = j;
      j = 2 * j + 1;
    }

    tab[i] = v;
  }

}


void Heap::ReadFromFile()
{
	fstream plik;
	string sizee;
	int i = 0;
	
	plik.open( "liczby.txt" );
	getline(plik, sizee);
	size= (atoi(sizee.c_str()));

	int *tablica = new int[size];
	for(int i=0; i< size; i++)
		tablica[i] = tab[i];

	delete[] tab;

	tab = tablica;

	

	while( !plik.eof() )
	{
   
		plik>>tab[i];
		i++;
	}

plik.close();

}

void Heap::Write()
{
	for(int i=0; i<size; i++)
		cout << tab[i] << endl;
}


bool Heap::Search(int Value)
{
	for( int i = size; i>=0; i--)
	{
		if(tab[0] == Value){
			return true;}
		RemoveRoot();
	}
	return false;
}

