/*
Considerem dos conjunts d’estudiants que representen els resultats de dos actes avaluatoris d’un mateix grup d’estudiants. Programeu i proveu una operació que actualitzi el primer conjunt, de forma que cada estudiant es quedi amb la millor de les notes dels dos conjunts originals. Considereu que qualsevol nota, fins i tot zero, és millor que no tenir nota. El segon conjunt no s’ha de modificar. El programa principal ha de tenir l’estructura

declaracions
llegir el primer conjunt mitjançant llegir (de la classe Cjt_estudiants)
llegir el segon conjunt mitjançant llegir (de la classe Cjt_estudiants)
actualitzar el primer conjunt mitjançant la nova operació
escriure el primer conjunt actualitzat mitjançant escriure (de la classe Cjt_estudiants)
Entrada

Dos conjunts d’estudiants.

Sortida

El primer conjunt actualitzat.

Observació

Tingueu en compte que les operacions de consulta i modificació de l’element i-èssim d’un conjunt són molt més eficients que les corresponents consultores i modificadores per DNI.

Només s’ha d’enviar el programa principal en el qual s’inclouran, entre d’altres, les classes Estudiant i Cjt_estudiants mitjançant

#include "Estudiant.hh"

#include "Cjt_estudiants.hh"
*/

#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
using namespace std;

void act_conjunt(Cjt_estudiants& conj1, const Cjt_estudiants& conj2) {
    int size = conj1.mida();
    for (int i = 1; i <= size; ++i) {
        if (conj1.consultar_iessim(i).te_nota() and conj2.consultar_iessim(i).te_nota()) {
            if (conj1.consultar_iessim(i).consultar_nota() < conj2.consultar_iessim(i).consultar_nota()) {
                conj1.modificar_iessim(i, conj2.consultar_iessim(i));
            }
        }
        
        else if (not conj1.consultar_iessim(i).te_nota()) {
            if (conj2.consultar_iessim(i).te_nota()) {
               conj1.modificar_iessim(i, conj2.consultar_iessim(i));
            }
        }
    }
}
    

int main () {
    Cjt_estudiants conj1;
    Cjt_estudiants conj2;
    conj1.llegir();
    conj2.llegir();
    act_conjunt(conj1, conj2);
    conj1.escriure();
}
