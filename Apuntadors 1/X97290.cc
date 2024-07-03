/*
Considerem la representació habitual amb nodes de la classe Llista per manegar llistes genèriques d’elements de tipus T que podeu trobar als fitxers publics.

Els nodes són doblement encadenats amb punters al següent (seg) i a l’anterior (ant). Una llista té quatre atributs; la longitud i tres punters a nodes, un pel primer element (primer_node), un per l’ultim (ultim_node) i un altre per l’element actual (act), on tenim situat el punt d’interès de la llista.

Recordeu que si l’act d’una llista no buida té valor null significa que el punt d’interès està situat a la dreta de tot, a sobre d’un element fictici posterior a l’últim element real.

Volem implementar dins d’aquesta classe la versió iterativa d’una nova operacióamb la següent especificació pre/post:

node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
         node_llista* &u, node_llista* &a)
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */

i redefinir l’operador d’assignacio de tal manera que utilitzi aquesta operacio per fer l’assignacio:

Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
  
Implementeu aquestes operacions accedint directament als atributs de la classe Llista, sense utilitzar cap de les operacions públiques. L’única operació de la classe que podeu fer servir és esborra_node_llista_it

Observació

Només s’ha d’enviar un fitxer de nom “program.hh”que contengui la funció amb la capçalera de l’enunciat, la redefinicio de l’operador assignació i qualsevol altra funció auxiliar que cregueu convenient, sense la funció main i sense posar-hi cap “include”.
*/

node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
         node_llista* &u, node_llista* &a)
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
{
    if (m == NULL) {
        u = NULL;
        a = NULL;
        return NULL;
    }
    
    a = NULL;
    node_llista* n, *aux, *p;
    n = aux = p = new node_llista;
    n -> info = m -> info;
    n -> ant = NULL;
    m = m -> seg;
    while (m != NULL) {
        aux -> seg = new node_llista;
        aux = aux -> seg;
        aux -> info = m -> info;
        aux -> ant = n;
        if (m == oact) a = aux;
        n = n -> seg;
        m = m -> seg;
    }
    
    u = n;
    aux -> seg = NULL;
    return p;
}

Llista& operator=(const Llista& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */

    {
        if (this != &original) {
            longitud = original.longitud;
            esborra_node_llista(primer_node);
            primer_node = copia_node_llista_it (original.primer_node, original.act, ultim_node, act);
        }
        return *this;
    }
