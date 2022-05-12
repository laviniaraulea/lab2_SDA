#include "Matrice.h"
#include <iostream>
#include <exception>

using namespace std;


Matrice::Matrice(int m, int n) {
	if (n * m <= 0)
		throw exception();
	else
	{
		this->lungime = 0;
		this->prim = (Pnod)malloc(sizeof(Nod));
		this->prim->pre = (Pnod)malloc(sizeof(Nod));
		this->prim->urm = (Pnod)malloc(sizeof(Nod));

		this->prim->pre = this->prim;
		this->prim->urm = this->prim;
		this->m = m;
		this->n = n;
	}
}

int Matrice::nrLinii() const {
	/*
	* theta(1)
	*/
	return this->n;
}


int Matrice::nrColoane() const {
	/*
	* theta(1)
	*/
	return this->m;
}
int Matrice::get_lungime() const {
	return this->lungime;
}
Pnod Matrice::get_prim() const
{
	return this->prim;
}

TElem Matrice::element(int i, int j) const {
	/*
	* O(n)
	*/
	if(i<0 || j<0 || i>this->nrLinii()  || j>this->nrColoane())
		throw exception();
	else
	{
		Pnod curent = (Pnod)malloc(sizeof(Nod));
		curent->pre = (Pnod)malloc(sizeof(Nod));
		curent->urm = (Pnod)malloc(sizeof(Nod));
		curent->pre = this->prim->pre;
		curent->urm = this->prim->urm;
		curent->valoare = this->prim->valoare;
		while (curent && curent!=this->prim)
		{
			if (curent->valoare.i == i && curent->valoare.j == j)
			{
				return curent->valoare.val;
			}
			else
			{
				curent = curent->urm;
			}
		}
		return NULL_TELEMENT;
	}
}
TElem Matrice::modifica(int i, int j, TElem e) {
	/*
	* O(n)
	*/
	if ( i<0 || j<0 || i>this->nrLinii() || j > this->nrColoane())
		throw exception();
	else
	{
		if (this->lungime == 0)
		{
			this->prim->valoare.i = i;
			this->prim->valoare.j = j;
			this->prim->valoare.val = e;
			this->lungime++;
		}
		else
		{
			Pnod curent = (Pnod)malloc(sizeof(Nod));
			curent->pre = (Pnod)malloc(sizeof(Nod));
			curent->urm = (Pnod)malloc(sizeof(Nod));
			curent = this->prim;
			while (i > curent->valoare.i && curent != this->prim)
			{
				curent = curent->urm;
			}
			while (j> curent->valoare.j && i== curent->valoare.i && curent!=this->prim)
			{
				curent = curent->urm;
			}
			if (j == curent->valoare.j && curent->valoare.i == i)
			{
				curent->valoare.val = e;
			}
			else
			{
				Pnod urmator = (Pnod)malloc(sizeof(Nod));
				urmator->pre = (Pnod)malloc(sizeof(Nod));
				urmator->urm = (Pnod)malloc(sizeof(Nod));
				urmator->pre = curent;
				urmator->urm = curent->urm;
				curent->urm = urmator;
				urmator->valoare.i = i;
				urmator->valoare.j = j;
				urmator->valoare.val = e;
				this->lungime++;
			}
		}

	}
}
