/*
Cal fer un programa que calculi estadístiques d’una seqüència de parell d’enters. Cada parell d’enters es composa de parells <codi nombre> un codi d’operació (un enter negatiu) i d’un enter (en aquest ordre). Si el codi és -1 això vol dir que el nombre que té com a parella compta com a vàlid. Si el codi és -2 llavors vol dir que cal invalidar qualsevol de les aparicions del nombre que segueix a continuació. (seria equivalent al fet que s’hagués esborrat una de les aparicions prèvies vàlides d’aquest element a la seqüència). Si el nombre s’ha d’invalidar però no té cap aparició prèvia vàlida, llavors no cal esborrar res. Cada vegada que processem una parella de la seqüència, cal treure per la sortida estàndard el mínim, al màxim i la mitjana dels elements vàlids que hi hagin al tros de seqüència que haurem processat.

En cas que no hi hagi cap element vàlid, llavors cal escriure només un zero.

Entrada

L’entrada és parells codi, nombre acabada amb el parell 0 0.

Sortida

La sortida són el mínim, màxim i mitjana dels elements dels elements vàlids, i si no n’hi ha cap, zero.

Observació

Cal fer servir la classe list de les stl. Cal enviar 1 sol fitxer: program.cc.
*/

#include <iostream>
#include <list>
using namespace std;

void afegir(list<int>& l, int num) {
    l.push_back(num);
}

bool eliminar(list<int>& l, int num) {
    list<int>::iterator it = l.begin();
    bool trobat = false;
    while (not trobat and it != l.end()) {
        if (*it == num) {
            it = l.erase(it);
            trobat = true;
        }
        
        else ++it;
    }
    return trobat;
}

void recalcular_min_max(list<int>& l, int& min, int& max) {
    if (not l.empty()) {
        list<int>::iterator it = l.begin();
        min = *it;
        max = *it;
        ++it;
        while (it != l.end()) {
            if (*it < min) min = *it;
            if (*it > max) max = *it;
            ++it;
        }
    }
}
        

int main () {
    int code, num, min, max;
    double suma = 0;
    list<int> l;
    cin >> code >> num;
    while (code != 0 and num != 0) {
        if (code == -1) {
            if (l.empty() or min > num) min = num;
            if (l.empty() or max < num) max = num;
            afegir(l, num);
            suma = suma + num;
        }
        
        if (code == -2) {
            bool eliminat = eliminar(l, num);
            if (eliminat) suma = suma - num;
            if (num == min or num == max) {
                recalcular_min_max(l, min, max);
            }
        }
        
        if (not l.empty()) cout << min << " " << max << " " << suma/l.size() << endl;
        else cout << '0' << endl;
        cin >> code >> num;
    }
}
