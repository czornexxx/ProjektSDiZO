#include "Biblioteki.h"

Heap::Heap(void)
{  
	size = 0;
	tab = new int[size];
}


Heap::~Heap(void)
{
	delete []tab;
}



void Heap::Add(int Value)
{   int a, tmp;

	size++;
	int *tab1=new int[size];
	for(int i = 0; i<size-1; i++)
	tab1[i]=tab[i];
	tab1[size-1] = Value;
	delete []tab;
	tab = new int[size];
	for(int i =0; i<size; i++)
	tab[i]=tab1[i];
	delete []tab1;

	a=size-1;
	

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

void Heap::Write(string sp, string sn, int v)
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

void Heap::Remove(int Value)
{
	sizebuff=0;
	buff=new int[sizebuff];
	for( int i = size; i>=0; i--)
	{
		if(tab[0] == Value)
		{RemoveRoot();break;
		}
		else
			{AddBuff(tab[0]);
			RemoveRoot();
		}

		}
	for (int i =sizebuff; i>0; i--)
	{
		Add(buff[i-1]);
	}
	
	delete []buff;
	
}

void Heap::AddBuff(int Value)
{
	int *tmp;
	//sizebuff=sizebuff + 1;
	//a = sizebuff-1;
	tmp = new int[sizebuff + 1];

	for(int i=0; i<sizebuff; i++)
		tmp[i] = buff[i];

	delete[] buff;

	tmp[sizebuff] = Value;
	
	buff = tmp;

	sizebuff ++;
		
}