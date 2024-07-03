/*
Feu un programa que obtingui la classificació de N equips en una lliga representada per una matriu m de mida N × N de parells de naturals. Una entrada

mi,j = (x,y) 
amb i ≠ j i 0 ≤ i, j < N representa el resultat d’un partit entre els equips i i j en el qual l’equip i ha marcat x gols i el j n’ha marcat y. Les entrades de la diagonal no són rellevants.

Tenint en compte que cada equip rep 3 punts per partit guanyat i 1 en cas d’empat, el programa ha d’obtenir, per a cada equip, el total dels punts aconseguits, dels gols marcats i dels rebuts i, en funció d’això, produir una sortida com es detalla més avall.

Entrada

Un enter N ≥ 2 seguit dels parells de la matriu m (escrits sense parèntesis ni comes) des de la primera fila fins la N-èsima i, dins de cada fila, des de la primera columna fins la N-èsima.

Sortida

N línies corresponents als equips on cada línia conté el número de l’equip, el nombre total de punts, els gols marcats i els rebuts. Les línies han d’aparèixer per ordre decreixent dels punts; quan hi ha empat, per ordre decreixent dels gols marcats menys els rebuts i, si persisteix l’empat, per ordre creixent del número d’equip.

Observació Per ordenar, podeu fer servir sort (veure “Normes de programació de P1”).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct equip {
    int numero, punts, marcats, rebuts;
};

int resultat(int x, int y) {
    if (x > y) return 1;
    else if (y > x) return 2;
    else return -1;
}

bool cmp(equip a, equip b) {
    if (a.punts != b. punts) return a.punts > b.punts;
    if (a.marcats - a.rebuts != b.marcats - b.rebuts) return a.marcats - a.rebuts > b.marcats - b.rebuts;
    return a.numero < b.numero;
}

int main () {
    int n;
    cin >> n;
    vector<equip> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].numero = i + 1;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x, y;
            cin >> x >> y;
            if (i != j) {
                v[i].marcats = v[i].marcats + x;
                v[j].marcats = v[j].marcats + y;
                v[i].rebuts = v[i].rebuts + y;
                v[j].rebuts = v[j].rebuts + x;
                int res = resultat(x, y);
                if (res == 1) v[i].punts = v[i].punts + 3;
                else if (res == 2) v[j].punts = v[j].punts + 3;
                else {
                    ++v[i].punts;
                    ++v[j].punts;
                }
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < n; ++i) {
        cout << v[i].numero << " " << v[i].punts << " " << v[i].marcats << " " << v[i].rebuts << endl;
    }
}
