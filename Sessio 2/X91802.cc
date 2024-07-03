/*
Feu una funció que calculi les posicions dels estudiants de notes màxima i mínima d’un vector d’estudiants. En cas d’empat, s’ha d’obtenir en cada cas la posició de l’estudiant amb mínim DNI. Pot haver-hi estudiants sense nota però no compten per a res. Si al vector no hi ha cap estudiant amb nota, el resultat ha de ser -1 per les dues posicions.

Observació

Feu servir la següent especificació:

pair<int,int>  max_min_vest(const vector<Estudiant>& v)
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
   resultat es la posicio de l'estudiant de nota maxima de v i la segona
   component es la posicio de l'estudiant de nota minima de v (si hi ha
   empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
   hi ha cap estudiant amb nota, totes dues components valen -1 */

La funció no ha d’escriure res.

Només s’ha d’enviar un fitxer que contingui la funció amb aquesta capçalera, sense el main o d’altres operacions auxiliars. Afegiu-hi també el #include de les classes Estudiant i vector mitjançant

#include "Estudiant.hh"

#include <vector>


Tot i que el Jutge no ho comprova necessàriament, es demana no fer servir cap vector o contenidor auxiliar. A més, cal fer un únic recorregut sobre el vector v.

Abans de fer el primer lliurament, completeu tot el codi necessari per provar la solució a la vostra màquina i garantiu que és bona per jocs de proves senzills.
*/

  #include "Estudiant.hh"
#include <vector>
using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v)
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
 {
     pair<int, int> maxmin;
     maxmin.first = -1;
     maxmin.second = -1;
     int max = -1;
     int min = 11;
     int tam = v.size();
     for (int i = 0; i < tam; ++i) {
         if (v[i].te_nota()) {
             if (v[i].consultar_nota() >= max) {
                 if (v[i].consultar_nota() == max) {
                     if (v[i].consultar_DNI() < v[maxmin.first].consultar_DNI()) {
                         maxmin.first = i;
                         max = v[i].consultar_nota();
                     }
                 }
                 
                 else {
                     maxmin.first = i;
                     max = v[i].consultar_nota();
                 }
             }
             
             if (v[i].consultar_nota() <= min) {
                 if (v[i].consultar_nota() == min) {
                    if (v[i].consultar_DNI() < v[maxmin.second].consultar_DNI()) {
                         maxmin.second = i;
                         min = v[i].consultar_nota();
                     }
                 }
                 
                 else {
                     maxmin.second = i;
                     min = v[i].consultar_nota();
                 }
             }
         }
     }
     
     return maxmin;
 }
