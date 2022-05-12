#pragma once
#include "matrice.h"

class Nod;
typedef Nod* Pnod;
class Matrice;
typedef int TElem;

class IteratorMatrice
{
public:
	friend class Matrice;
	friend class Nod;
	IteratorMatrice(const Matrice &m);
	const Matrice& mat;
	Pnod curent;
	int i;
	int j;
	int n;
	int c;
	int lungime_curenta;

public:
	//resetreaza pozitia
	void prim();


	//muta iteratorul pe urmatorul element
	void urmator();

	//se verifica daca numarul e valid
	bool valid() const;
	
	//returneaza valoarea elementului ferefit de iterator
	TElem element() const;

}; 