/*
Considerem la representació habitual amb nodes de la classe Pila per manegar piles genèriques d’elements de tipus T que podeu trobar als fitxers publics.

Els nodes són simplement encadenats amb punter al següent (seguent). Una pila té dos atributs; la altura i un punter pel primer element (primer_node).

Volem implementar dins d’aquesta classe la versió iterativa d’una operació nova amb la següent especificació pre/post:

node_pila* copia_node_pila_it(node_pila* m) 
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
  
i redefinir l’operador d’assignacio de tal manera que utilitzi aquesta operacio per fer l’assignacio:

Pila& operator=(const Pila& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
  
Implementeu aquestes operacions accedint directament als atributs de la classe Pila, sense utilitzar cap de les operacions públiques. L’única operació de la classe que podeu fer servir és esborra_node_pila_it

Observació

Només s’ha d’enviar un fitxer de nom “program.hh”que contengui la funció amb la capçalera de l’enunciat i la redefinicio de l’operador assignació, sense la funció main i sense posar-hi cap “include”.
*/

node_pila* copia_node_pila_it(node_pila* m) 
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
    {
        if (m == NULL) return NULL;
        node_pila *n, *aux;
        n = aux = new node_pila;
        n->info = m->info;
        m = m->seguent;
        while (m != NULL) {
            aux->seguent = new node_pila;
            aux = aux->seguent;
            aux->info = m->info;
            m = m->seguent;
        }
        aux->seguent = NULL;
        return n;
    }


    
Pila& operator=(const Pila& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
    {
    if (this != &original) {
        altura = original.altura;
        esborra_node_pila(primer_node);
        primer_node = copia_node_pila_it(original.primer_node);
    }
    return *this;
  }
