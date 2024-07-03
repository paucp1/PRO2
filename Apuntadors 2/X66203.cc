/*
Afegiu una operació pública a la classe genèrica ArbreNari vista a teoria que calculi el valor més gran que conté l’arbre. Feu servir la següent especificació:

T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
No utilitzeu cap de les operacions primitives dels arbres n-aris, accediu directament als atributs de la classe ArbreNari.

Entrada

L’entrada és un arbre n-ari, que serà llegit en preordre, en el paràmetre implícit.

Sortida

La sortida és el valor màxim de l’arbre d’entrada.

Observació

Només s’ha d’enviar un fitxer anomenat program.hh, que no ha de fer cap cout, que contingui la funció amb la capçalera de l’enunciat i qualsevol altra funció auxiliar que cregueu convenient, sense la funció main i sense posar-hi cap include. A l’apartat Public files trobareu els fitxers que us calen per construir la vostra solució.
  */

  void maxim_rec(node_arbreNari* node, T& max, int N) const {
    if (node != NULL) {
        if (node -> info > max) max = node -> info;
        for (int j = 0; j < N; ++j) {
            maxim_rec(node -> seg[j], max, N);
        }
    }
}

T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
    T max = primer_node -> info;
    for (int i = 0; i < N; ++i) {
        maxim_rec(primer_node -> seg[i], max, N);
    }
    return max;
}
