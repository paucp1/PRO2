/*
Feu un programa que simplifiqui les notes d’un vector d’estudiants triant la nota més alta de cadascun d’ells.

Entrada

Una seqüència no buida d’estudiants (DNI i nota) en la qual hi pot haver més d’una nota d’un mateix estudiant però, en aquest cas, hi apareixeran de forma consecutiva. Tots els DNIs són diferents de 0.

Sortida

Una seqüència dels estudiants de l’entrada en el mateix ordre però amb la diferència que cada estudiant només hi apareix un cop amb la nota més alta de les donades a l’entrada.

Observació

Només s’ha d’enviar el programa principal en el qual s’inclourà la classe Estudiant mitjançant


#include "Estudiant.hh"


Tot i que el Jutge no ho comprova, es demana fer servir un vector que emmagatzemi l’entrada i un altre on desar-hi la sortida. Després de llegir l’entrada en el vector d’entrada, feu un únic recorregut sobre aquest vector.
  */

#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

/* Leer vector */
void leer_vector_est(vector<Estudiant>& v) {// version accion
  int numEst;
  cin >> numEst;
  v = vector<Estudiant> (numEst);
  for (int i=0; i<numEst;++i)
    v[i].llegir();
}

/* Escribir vector */
void escribir_vector_est(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    v[i].escriure();
}

vector<Estudiant> simpl_vec_est(const vector<Estudiant>& v) {
    int tam = v.size();
    int i = 0;
    vector<Estudiant> res;
    while (i < tam) {
        Estudiant aux(v[i].consultar_DNI());
        double nmax = -1;
        int ident = v[i].consultar_DNI();
        while (i < tam and v[i].consultar_DNI() == ident) {
            if (v[i].te_nota()) {
                if (v[i].consultar_nota() > nmax) {
                    nmax = v[i].consultar_nota();
                    if (aux.te_nota()) {
                        aux.modificar_nota(nmax);
                    }
                    else {
                        aux.afegir_nota(nmax);
                    }
                }
            }
            ++i;
        }
        res.push_back(aux);
    }
    
    return res;
}
            

int main () {
    vector<Estudiant> v;
    leer_vector_est(v);
    vector<Estudiant> res = simpl_vec_est(v);
    escribir_vector_est(res);
}
