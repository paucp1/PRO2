/*
Volem una operació per obtenir la intersecció de dues llistes ordenades d’enters, sense visitar elements de forma innecessària i sense fer servir estructures auxiliars.

Per exemple, les llistes L1: [-7 1 5 12] L2: [1 3 4 5] tenen com a intersecció [1 5].

Observació

Feu servir la següent especificació:

 void inter(list<int>& uno, const list<int>& dos )
 /* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */

Només s’ha d’enviar un fitxer que contengui la funció amb la capçalera de l’enunciat i qualsevol altra funció auxiliar que cregueu convenient, sense la funció main. Afegiu-hi també els includes de les classes que utilitzeu.
  */

  #include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos ) {
 /* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();
    while (it1 != uno.end() and it2 != dos.end()) {
        if (*it1 < *it2) {
            it1 = uno.erase(it1);
        }
     
        else if (*it2 < *it1) {
            ++it2;
        }
     
        else {
            ++it1;
            ++it2;
        }
    }
 
    while (it1 != uno.end()) {
        it1 = uno.erase(it1);
    }
}
