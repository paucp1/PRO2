/*
Donada una expressió amb parèntesis de dos tipus diferents, escriviu un programa que avaluï la seva correctesa utilitzant piles.

Entrada Una seqüència de parèntesis (, ), [, ] acabada en punt. La seqüència pot ocupar més d’una línia.

Sortida Escriu “Correcte” o “Incorrecte” segons sigui el cas. Cas de ser incorrecte, escriu la darrera posició de l’expressió (un número entre 1 i la mida) que cal visitar per afirmar-ho. Visitar més posicions de les necessàries es considera ineficient (tracteu aquest exercici com a un problema de cerca).

Observació

Heu d’enviar un sol fitxer amb el programa.
  */

#include <iostream>
#include <stack>
using namespace std;

int main () {
    char p;
    stack<char> pila;
    cin >> p;
    bool correcte = true;
    while (correcte and p != '.') {
        if (p == '(' or p == '[') {
            pila.push(p);
        }
        
        else if (p == ')') {
            if (pila.empty() or pila.top() != '(') {
                correcte = false;
            }
            else pila.pop();
        }
        
        else if (p == ']') {
            if (pila.empty() or pila.top() != '[') {
                correcte = false;
            }
            else pila.pop();
        }
        
        cin >> p;
    }
    
    if (correcte and pila.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
