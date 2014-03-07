#include <iostream>
#include "Tablica.h"

using namespace std;

int main(){

	Tablica *t = new Tablica();

	for(int i=0; i<20000; i++)
		t->add(i);

	//t->wypisz();

	system("Pause");
	return 0;
}