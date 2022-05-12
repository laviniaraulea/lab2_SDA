#pragma once

typedef int TElem;


#define NULL_TELEMENT 0

class Nod;

typedef Nod* Pnod;

typedef struct A{
	TElem val;
	int i;
	int j;
}triplet;

class Nod
{
	public:
		friend class Matrice;
		friend class Iterator;
		triplet valoare;
		Pnod urm;
		Pnod pre;

	private:
	//	triplet valoare;
		//Pnod urm;
		//Pnod pre;

};
class Matrice {

private:
	int n, m;
	Pnod prim;
	int lungime;
	/*
	* Cauta un element dupa linie si coloana in lista de resprezentare a matricii, si returneaa pointerul care contine acea valoare
	* return NULL altfel
	*/
public:

	Pnod get_prim() const;

	//return nr de elemente
	int get_lungime() const;
	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice() {};

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);

};







