/*
Feu un programa que simuli els movimients del mostrador de devolucions d’una biblioteca. No cal que el programa sigui completament modular, però es obligatori fer servir la clase stack.

Els llibres i altres materials disponibles en la biblioteca estan clasificats en n categories y cada una de elles te associada una pila en el mostrador. n és un enter més gran que cero i serà una dada del programa. Un llibre tindrà dos atributs: el seu títol, que serà una string, i la seva categoria, que serà un enter entre 1 y n. Hi ha dos tipus de movimients: un usuari retorna un llibre i ho posa en la pila de devolucions corresponent a la seva categoria (opció -1) el personal de la biblioteca retira un cert nombre de llibres correlativament a partir de la cima d’una de las pilas del mostrador; tal nombre no pot ser major que la alçada de la pila (opció -2) A més, inclouem una opció -3, consistent en escriure el contengut d’una de las piles del mostrador. Organitzeu el programa principal como un procés iteratiu que, després d’inicializar tots els components, llegeixi un valor entre -1 y -4 indicatiu de l’opció que volem aplicar (la opció -4 serà la de terminar el programa), després llegeixi les dades necessàries i l’apliqui. La resta de processos iteratius (escriure una pila treure elements d’una pila) han de programar-se en operacions a part.

Entrada

Veure jocs de proves

Sortida

Veure jocs de proves

Observació

Per resoldre aquest exercici, els únics contenidors que hauríeu d’usar són piles d’string i vectors.
  */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void treure_elements(stack<string>& s, int n) {
    for (int i = 0; i < n; ++i) {
        s.pop();
    }
}

void escriure_pila(stack<string>& s, int n) {
    stack<string> copia;
    copia = s;
    cout << "Pila de la categoria " << n << endl;
    for (int i = 0; i < s.size(); ++i) {
        cout << copia.top() << endl;
        copia.pop();
    }
    cout << endl;
}


int main () {
    int categories, operacio, cat_llibre;
    string titol;
    cin >> categories;
    vector<stack<string>> biblio(categories);
    cin >> operacio;
    while (operacio != -4) {
        if (operacio == -1) {
            cin >> titol >> cat_llibre;
            biblio[cat_llibre - 1].push(titol);
        }
        
        else if (operacio == -2) {
            int retirar;
            cin >> retirar >> cat_llibre;
            treure_elements(biblio[cat_llibre - 1], retirar);
        }
        
        else if (operacio == -3) {
            cin >> cat_llibre;
            escriure_pila(biblio[cat_llibre - 1], cat_llibre);
        }
        
        cin >> operacio;
    }
}
