/*
Donada una seqüència d’entrada que consisteix en un codi i una paraula, si el codi és a cal incrementar la freqüència de la paraula que segueix, i si el codi és f cal escriure a la sortida estàndard la freqüència de la paraula que segueix (en la part de la seqüència llegida fins aleshores). Si la paraula no existeix, la freqüència és, òbviament, zero.

Feu servir un diccionari per a implementar aquest problema.

Entrada

L’entrada és una llista de parells (codi, paraula). El codi pot ser a o f. En el primer cas, voldrà dir que cal incrementar la freqüència de la paraula que segueix. En el segon cas, el que caldrà fer és treure per pantalla la freqüència de la paraula que segueix al codi.

Sortida

La sortida són les freqüències de les paraules que tindran el codi f a davant.

Observació Cal fer servir la classe map de les stl. Cal enviar 1 sol fitxer: program.cc.
  */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main () {
    
    map<string, int> d;
    char code;
    string paraula;
    while (cin >> code >> paraula) {
        if (code == 'a') {
            ++d[paraula];
        }
        
        else if (code == 'f') {
            cout << d[paraula] << endl;
        }
    }
}
