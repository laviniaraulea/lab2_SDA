#include <iostream>
#include "Matrice.h"
#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;
/*
* TAD  Matrice-reprezentare  sub  forma  unei  matrice  rare,  folosind  o  LDI  cu  triplete  
de  forma <linie, coloană, valoare> (valoare), memorate în ordine lexicografică după (linie, coloană).
*/
int main() {

		testAll();
		test_iterator();
		testAllExtins();

	cout << "End";
}
