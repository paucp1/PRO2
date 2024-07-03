/*
Considerem una seqüència de nombres enters compresos entre -1000 y 1000, amb instruccions d’esborrat intercalades en qualsevol moment. Cada cop que es llegeixi o s’esborri un nombre, s’ha d’obtenir el mínim, el màxim i la mitjana dels nombres que s’hagin llegit fins el moment, excepte els que s’hagin esborrat. Qualsevol nombre més gran que 1000 o mes petit que -1001 marca el final de la seqüència. El nombre -1001 representa una instrucció d’esborrat, en concret de l’element més antic de la seqüència. Si després d’un esborrat la seqüència està buida (tant si és perque s’ha esborrat el seu únic element, o perque ja ho estava), només sha d’escriure un zero. Tot procés iteratiu auxiliar de les estadístiques ha de programar-se en operació a part. En cada tractament només és pot recórrer la seqüència una cop com a molt i només si és estrictament necessari.

Entrada

Veure joc de proves.

Sortida

Veure joc de proves.

Observació

Per resoldre aquest exercici, només cal fer servir una cua d’enters. Cal lliurar només un fitxer amb el programa complet.
*/

#include <iostream>
#include <queue>
using namespace std;

int recalcular_min(const queue<int>& q) {
    queue<int> copia(q);
    int min = 1001;
    while (not copia.empty()) {
        if (copia.front() < min) min = copia.front();
        copia.pop();
    }
    return min;
}

int recalcular_max(const queue<int>& q) {
    queue<int> copia(q);
    int max = -1001;
    while (not copia.empty()) {
        if (copia.front() > max) max = copia.front();
        copia.pop();
    }
    return max;
}

void escriure(const queue<int>& q, int min, int max, double mitja) {
    if (q.empty()) cout << "0" << endl;
    else {
        cout << "min " << min << "; max " << max << "; media " << mitja << endl;
    }
}


int main () {
    int min = 1001, max = -1001, act;
    double suma = 0;
    double mitja = 0;
    queue<int> q;
    cin >> act;
    while (act <= 1000 and act >= -1001) {
        if (act == -1001) {
            if (not q.empty()) {
                int primer = q.front();
                q.pop();
                suma = suma - primer;
                if (primer == min) min = recalcular_min(q);
                if (primer == max) max = recalcular_max(q);
            }
        }
        
        else {
            suma += act;
            q.push(act);
            if (act > max) max = act;
            if (act < min) min = act;
        }
        
        if (not q.empty()) mitja = suma/q.size();
        escriure(q, min, max, mitja);
        cin >> act;
    }
}
