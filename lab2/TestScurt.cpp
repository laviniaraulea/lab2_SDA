#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>
#include "iterator.h"

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1,1,5);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
	assert(m.element(1,2) == NULL_TELEMENT);
}

void test_iterator()
{
	Matrice m(2, 2);
	IteratorMatrice i(m);
	m.modifica(1, 1, 1);
	m.modifica(2, 2, 3);
	
	assert(i.element() == 1);
	i.urmator();
	assert(i.element() == 0);
	i.urmator();
	assert(i.element() == 0);
	i.urmator();
	assert(i.element() == 3);
	
}
