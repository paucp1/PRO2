/*
Implementeu eficientment l’operació poda_subarbre especificada a continuació.

 bool poda_subarbre(BinTree<int> &a, int x);

Entrada

L’entrada és un arbre binari d’enters a, sense repeticions, i un enter x.

Sortida

La sortida es un valor booleà que indica si x hi és l’arbre. En cas afirmatiu, s’han eliminat de l’arbre l’element x i tots els successors.

Exemple: considereu els arbres següents

  a =   1              b =   1             c =   5
       / \                  / \                 / \
      2   3                2   3               2   7
     / \                  /                       / \
    5   4                5                       6   8
       / \
      7   6
Si cridem poda_subarbre(a,4) el resultat és cert i a passa a tenir la forma de b. Si cridem poda_subarbre(c,3), el resultat és fals i l’arbre c no canvia.

Observació

Cal fer servir la classe BinTree que us donem

Només s’ha d’enviar un fitxer que contengui la funció amb la capçalera de l’enunciat i qualsevol altra funció auxiliar que cregueu convenient, sense la funció main. Afegiu-hi també l’include de la classe BinTree mitjançant


#include "BinTree.hh"
*/

#include "BinTree.hh"
using namespace std;


bool poda_subarbre(BinTree<int> &a, int x) {
    if (a.empty()) return false;
    else {
        if (a.value() == x) {
            a = BinTree<int>();
            return true;
        }
        
        else {
            BinTree<int> a1 = a.left();
            BinTree<int> a2 = a.right();
            bool resl = poda_subarbre(a1,x);
            bool resr = poda_subarbre(a2,x);
            a = BinTree<int>(a.value(), a1, a2);
            return (resl || resr);
        }
    }
}
