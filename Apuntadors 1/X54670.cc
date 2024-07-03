/*
Considerem la representació habitual amb nodes de la classe Cua per manegar cues genèriques d’elements de tipus T que podeu trobar als fitxers públics. Els nodes són simplement encadenats amb punters al següent (seguent). Una cua té tres atributs: la longitud i dos punters a nodes, un pel pimer element (primer_node) i un per l’últim (ultim_node).

Diem que el resultat de concatenar una cua q2 a una cua q1 és la cua q1 modificada amb els elements de q2 afegits pel final.

Volem implementar dins de la classe Cua una operació nova amb la següent especificació:

void concat(Cua &c)
/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
Exemples:

Si el p.i. és originalment
 1   5   14   25   8
i c és

 99   3
llavors el p.i. ha de quedar.

 1   5   14   25   8  99  3
Dissenyeu aquesta operació sense utilitzar cap de les operacions primitives de les cues, accedint directament als atributs de la classe Cua.

Entrada

L’entrada son dues cues.

Sortida

La sortida és la concatenació de les dues cues sobre la primera.

Observació

Només s’ha d’enviar un fitxer anomenat ”program.hh” que contingui la funció amb la capçalera de l’enunciat i qualsevol altra funció auxiliar que cregueu convenient, sense la funció main i sense posar-hi cap ”include”. El jutge ho compilarà fent un ”include” del vostre fitxer dins de la classe Cua, per aquesta rao podeu utilitzar els atributs privats de la classe Cua.

Abans d’enviar la solució al Jutge, assegureu-vos que funciona en tots els casos previstos (que les dues cues siguin buides, que una ho sigui i l’altra no, etc). Tingueu en compte que una solució ineficient també us pot donar semàfor vermell.
  */

  void concat(Cua &c)
/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
{
    if (c.primer_node != NULL) {
        if (primer_node == NULL) {
            primer_node = c.primer_node;
            ultim_node = c.ultim_node;
            longitud = c.longitud;
        }
    
        else {
            ultim_node->seguent = c.primer_node;
            ultim_node = c.ultim_node;
            longitud += c.longitud;
        }
    
        c.primer_node = NULL;
        c.ultim_node = NULL;
        c.longitud = 0;
    }
}
