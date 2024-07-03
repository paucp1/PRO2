/*
Afegiu una operació pública a la classe genèrica ArbreNari vista a teoria que calculi l’arbre suma de l’arbre d’entrada. Feu servir la següent especificació:

void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
Un exemple per un arbre 3-ari

    a =       5           arbre de sumes d'a =       31
            / | \                                  /  |  \
          7   1   3                              10   1   15
        /  \      | \                           /   \     | \ 
       2    1     8  4                         2     1    8  4
No utilitzeu cap de les operacions primitives dels arbres n-aris, accediu directament als atributs de la classe ArbreNari.

Entrada

L’entrada és un arbre n-ari, que serà llegit en preordre, en el paràmetre implícit.

Sortida

La sortida és l’arbre suma de l’arbre d’entrada.

Observació

Només s’ha d’enviar un fitxer anomenat program.hh, que no ha de fer cap cout, que contingui la funció amb la capçalera de l’enunciat i qualsevol altra funció auxiliar que cregueu convenient, sense la funció main i sense posar-hi cap include. A l’apartat Public files trobareu els fitxers que us calen per construir la vostra solució.
  */
void arbsuma_rec(node_arbreNari* node, node_arbreNari* &node_suma, int& suma) const {
    if (node == NULL) suma = 0;
    else {
        suma = node -> info;
        node_suma = new node_arbreNari;
        node_suma -> seg = vector<node_arbreNari*>(node -> seg.size());
        for (int i = 0; i < node -> seg.size(); ++i) {
            node_arbreNari* aux = NULL;
            int suma1;
            arbsuma_rec(node -> seg[i], aux, suma1);
            suma += suma1;
            node_suma -> seg[i] = aux;
        }
        
        node_suma -> info = suma;
    }
}
            

void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
    int suma = 0;
    asum.N = N;
    arbsuma_rec(primer_node, asum.primer_node, suma);
}
  
