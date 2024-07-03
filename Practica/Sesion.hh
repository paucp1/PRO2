/** @file Sesion.hh
    @brief Especificación de la clase Sesion 
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "BinTree.hh"
#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <list>
#include <map>
#endif

/** @class Sesion
    @brief Representa una sesión compuesta por problemas de la colección

    Tiene un nombre que la identifica y está formada por un subconjunto de problemas de la colección estructurados según unas relaciones de prerequisitos.
*/

class Sesion
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una sesión.
        \pre <em>cierto</em>
        \post El resultado es una sesión sin nombre y sin ningún problema.
    */
    Sesion();
    
    /** @brief Creadora con valores concretos 

        \pre <em>cierto</em>
        \post El resultado es una sesión con nombre id y sin ningún problema.
    */
    Sesion(const string& id);
    
    //Consultoras
    
    /** @brief Consultora del nombre 

        \pre <em>cierto</em>
        \post El resultado es el nombre del parámetro implícito.
    */
    string nombre() const;
    
    /** @brief Consultora del problema inicial 

        \pre <em>cierto</em>
        \post prob contiene el problema inicial del parámetro implícito.
    */
    void problema_inicial(Problema& prob) const;
    
    /** @brief Consultora del número de problemas de la sesión 

        \pre <em>cierto</em>
        \post El resultado es el número de problemas que contiene el parámetro implícito.
    */
    int numero_problemas() const;
    
    /** @brief Consulta la intersección entre una sesión y m.

        \pre <em>cierto</em>
        \post El resultado indica si la intersección entre los problemas del parámetro implícito y m es vacía. En caso de que lo sea, m contiene los identificadores del los problemas del parámetro implícito.
    */
    bool problemas_contenidos(map<string, string>& m) const;
    
    /** @brief Consulta los problemas que tienen como precondición el problema con nombre id. 

        \pre id es un problema del parámetro implícito.
        \post p contiene los problemas que tienen como precondición el problema con nombre id.
    */
    void consultar_problemas_siguientes(const string& id, pair<Problema, Problema>& p) const;
    
    //Lectura y escritura
    
    /** @brief Operación de lectura 

        \pre Están preparados en el canal standard de entrada una secuencia de nombres de problemas distintos de la colección, siguiendo un recorrido en preorden de su estructura de prerequisitos.
        \post El parámetro implícito contine el subconjunto de problemas de la colección.
    */
    void leer();
    
    /** @brief Operación de escritura 

        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida el nombre del parámetro implícito, su número de problemas y los nombres de dichos problemas, siguiendo su estructura de prerequisitos en postorden.
    */
    void escribir() const;

private:
    /** @brief Identificador de la sesión  */    
    string nom;
    
    /** @brief Estructura de la sesión  */
    BinTree<string> bt_ses;
    
    /** @brief Cálculo del número de problemas de un árbol  

        \pre <em>cierto</em>
        \post El resultado es el número de problemas que contiene a.
    */
    static int mida(const BinTree<string>& a);
    
    /** @brief Consulta si la intesección entre los problemas de un árbol determinado y m es vacía 

        \pre <em>cierto</em>
        \post El resultado indica si la intersección entre a y m es vacía. En caso de que lo sea, m contiene los identificadores de los problemas de a.
    */
    static bool consultar_problemas_sesion(const BinTree<string>& a, const string& id, map<string, string>& m);
    
    /** @brief Consultora de un subarbol con raíz determinada  

        \pre El problema con nombre id forma parte de a.
        \post arb contiene el subarbol de a cuya raíz es id.
    */
    static void consultar_arbol(const BinTree<string>& a, const string& id, BinTree<string>& arb);
    
    /** @brief Lectura en preorden del árbol de una sesión  

        \pre Están preparados en el canal standard de entrada una secuencia de nombres de problemas distintos de la colección, siguiendo un recorrido en preorden de su estructura de prerequisitos.
        \post El resultado es el árbol con los nombre de los problemas introducidos.
    */
    static BinTree<string> leer_preorden();
    
    /** @brief Consultora de la raíz del árbol 

        \pre <em>cierto</em>
        \post prob contiene un problema con el nombre de la raíz de a. En caso de que a sea vacío, prob contiene un problema con nombre "vacio".
    */
    static void problema_siguiente(const BinTree<string>& a, Problema& prob);
    
    /** @brief Escritura en postorden del árbol de una sesión 

        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida los nombres de los problemas de a, siguiendo su estructura de prerequisitos en postorden.
    */
    static void escribir_postorden(const BinTree<string>& a);
};
#endif
