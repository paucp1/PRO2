/*
Feu un programa que calculi les mitjanes de les notes de M estudiants en un subconjunt donat de les assignatures A1, …, AN.

Entrada L’entrada consta de tres enters inicials: M (nombre d’estudiants), N (nombre d’assignatures) i S (nombre d’assignatures seleccionades), on M, N ≥ 1 i 1 ≤ S ≤ N. A continuació, vénen S valors b1,…,bS (amb 1 ≤ bi ≤ N, per a tot i), on bi representa l’assignatura Abi. Finalment hi ha M files que comencen pel DNI d’un estudiant seguit de N notes amb valors entre 0 i 10, on la nota i-èsima és la que té l’estudiant en l’assignatura Ai.

Sortida

M files formades pel DNI de cada estudiant (ordenades descendentment per nota i en cas d’empat ascendentment per dni) seguit de la nota mitjana que ha obtingut en les assignatures Ab1,…,AbS.

Observació

Encara que el Jutge no ho comprova necessàriament, una solució òptima hauria de visitar cada nota de cada estudiant en cada assignatura una sola vegada; en particular, no s’haurien de guardar aquestes notes en un vector auxiliar abans de tractar-les.

Només s’ha d’enviar el programa principal en el qual, entre d’altres, s’inclourà la classe Estudiant mitjançant

#include "Estudiant.hh"
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
using namespace std;

bool cmp (const Estudiant& a,const Estudiant& b) {
    if (a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
    return a.consultar_DNI() < b.consultar_DNI();
}

/* Escribir vector */
void escribir_vector_est(const vector<Estudiant>& v) {
  for (int i=0; i<v.size();++i)
    v[i].escriure();
}

int main () {
    int M, N, S;
    cin >> M >> N >> S;
    vector<bool> sub(N, false);
    vector<Estudiant> v;
    for (int i = 0; i < S; ++i) {
        int b;
        cin >> b;
        sub[b - 1] = true;
    }
    
    for (int i = 0; i < M; ++i) {
        int iden;
        double suma = 0;
        cin >> iden;
        Estudiant est(iden);
        for (int j = 0; j < N; ++j) {
            double grade;
            cin >> grade;
            if (sub[j]) {
                suma = suma + grade;
            }
        }
        est.afegir_nota(suma/S);
        v.push_back(est);
    }
    
    sort(v.begin(), v.end(), cmp);
    escribir_vector_est(v);
}
