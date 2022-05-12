#include "Iterator.h"
#include "Matrice.h"
#include <iostream>

using namespace std;
IteratorMatrice::IteratorMatrice(const Matrice& m) : mat(m) {
	this->curent = mat.get_prim();
	lungime_curenta = 1;
	n = m.nrLinii();
	c = m.nrColoane();
	i = 1;
	j = 1;

	/*
	* Pseudocod
	* 
	* Functie IteratorMatrice( matrice m)
	* [curent]<-m.get_prim()
	* lungime<-1
	* Sf functie
	* 
	*/
}

void IteratorMatrice::prim() {
	i = 0;
	j = 0;
	this->curent = mat.get_prim();
	/*
	* Pseudocod
	*post: reseteaza interatorul
	* 
	* Functie prim( )
	* curent<-m.get_prim()
	* Sf functie
	*
	*/
}



void IteratorMatrice::urmator() {
	this->curent = this->curent->urm;
	lungime_curenta++;
	if (i == n)
	{
		i = 0;
		j++;
	}
	i++;

	/*
	* Pseudocod
	*
	* Functie urmator( )
	* curent<-[curent].urmator
	* lungime_curenta<-lungime_curenta+1
	* Sf functie
	*
	*/
}


bool IteratorMatrice::valid() const {
	if (lungime_curenta==n*c)
		return false;
	return true;
	/*
	* Pseudocod
	*
	* Functie valid()
	* curent<-[curent].urmator
	* Sf functie
	*
	*/
}
TElem IteratorMatrice::element() const {
	if (this->curent->valoare.i == i && this->curent->valoare.j == j)
		return this->curent->valoare.val;
	else
		return NULL_TELEMENT;
	/*
* Pseudocod
*
* Functie element()
* curent<-[[curent].valoare].val
* Sf functie
*
*/
}

