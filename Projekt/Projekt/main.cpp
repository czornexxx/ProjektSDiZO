#include <iostream>
#include "Tablica.h"

using namespace std;

int main(){

	Tablica *t = new Tablica();

	for(int i=0; i<20000; i++)
		t->add(i);

	cout << "Doda³em wszystkie 20000 elementow" << endl;

	cout << t->getPozycja(1223) << endl;

	system("Pause");
	return 0;
}