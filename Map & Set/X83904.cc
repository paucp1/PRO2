/*
Un entrenador vol controlar les activitats en que participen els seus jugadors. Els demana que apuntin diariament el seu cognom a la llista de les activitats en que hagin participat aquell dia. A final de mes vol saber quins jugadors han participat en totes les activitas i quins no n’han fet cap.

Entrada Una llista amb el cognom (tots diferents) de tots els jugadors acabada en punt. Un enter indicant el nombre d’activitats programades i tantes llistes com activitats programades, totes acabades en punt i possiblement amb cognoms repetits.

Sortida El text ”Totes les activitats: ” seguida de la llista de cognoms que les han fetes i el text ”Cap activitat: ” seguida de la llista de cognoms que no n’han fet cap.

Observació

Envieu només un fitxer program.cc. Es un problema per exercitar-se amb la classe set.
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main () {
    set<string> totes, cap, falta;
    string cognom;
    cin >> cognom;
    while (cognom != ".") {
        totes.insert(cognom);
        cin >> cognom;
    }
    cap = totes;
    
    int activitats;
    cin >> activitats;
    
    for (int i = 0; i < activitats; ++i) {
        falta = totes;
        cin >> cognom;
        while (cognom != ".") {
            cap.erase(cognom);
            falta.erase(cognom);
            cin >> cognom;
        }
        
        for (set<string>::iterator it = falta.begin(); it != falta.end(); ++it) {
            totes.erase(*it);
        }
    }
        
    cout << "Totes les activitats:";
    for (set<string>::iterator it = totes.begin(); it != totes.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;
    
    cout << "Cap activitat:";
    for (set<string>::iterator it = cap.begin(); it != cap.end(); ++it) {
        cout << " " << *it;
    }
    cout << endl;    
}
