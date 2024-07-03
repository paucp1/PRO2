/*
Useu una pila per determinar, per un enter n i una seqüència d’enters donada de longitud n, si la seqüència és un palíndrom o no. És a dir, cal indicar si la seqüència es llegeix igual d’esquerra a dreta que a l’inrevés (sense invertir els dígits dins de cada enter).

Entrada

L’entrada consisteix en un enter n i una seqüència d’enters de longitud n.

Sortida

Cal escriure "SI" o bé "NO" segons convingui.

Observació

Per resoldre aquest exercici, només cal fer servir una pila d’enters per guardar la primera meitat de la seqüència i tractar cada enter restant només un cop.
  */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main () {
    int c, e;
    cin >> c;
    stack<int> pila;
    int meitat = c/2;
    for (int i = 0; i < meitat; ++i) {
        cin >> e;
        pila.push(e);
    }
    
    if (c%2 != 0) cin >> e;
    
    int i = 0;
    bool palindrom = true;
    while (palindrom and i < meitat) {
        cin >> e;
        if (pila.top() != e) {
            palindrom = false;
        }
        pila.pop();
        ++i;
    }
    
    if (palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;
}
