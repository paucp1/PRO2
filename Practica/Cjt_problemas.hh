/** @file Cjt_problemas.hh
    @brief Especificación de la clase Cjt_problemas 
*/

#ifndef _CJT_PROBLEMAS_HH_
#define _CJT_PROBLEMAS_HH_

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <set>
#include <string>
#endif

/** @class Cjt_problemas
    @brief Representa una colección de problemas de programación

    Los elementos de la colección (de tipo Problema) se encuentran ordenados crecientemente por el nombre. Se pueden consultar y modificar sus elementos.
*/

class Cjt_problemas
{
public:
    //Constructora
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una colección de problemas.
        \pre <em>cierto</em>
        \post El resultado es una colección de problemas vacia.
    */
    Cjt_problemas();
    
    //Modificadoras
    
    /** @brief Añade un problema a la colección 

        \pre El parámetro implícito no contine ningun problema con el nombre de p.
        \post El parámetro implícito contiene el problema p.
    */
    void anadir_problema(const Problema& p);
    
    /** @brief Modifica un problema de la colección 

        \pre El parámetro implícito contine un problema con el nombre de p.
        \post El problema del parámetro implícito original con el nombre de p ha quedado sustituido por p.
    */
    void modificar_problema(const Problema& p);
    
    /** @brief Elimina un problema de la colección 

        \pre El parámetro implícito contine un problema con el nombre de p.
        \post El problema con el nombre de p ha quedado eliminado del parámetro implícito.
    */
    void borrar_problema_usuario(const Problema& p);
    
    //Consultoras
    
    /** @brief Consulta el número de problemas de la colección 

        \pre <em>cierto</em>
        \post El resultado es el número de problemas del parámetro implícito.
    */
    int numero_problemas() const;
    
    /** @brief Consulta si existe un problema en la colección 

        \pre <em>cierto</em>
        \post El resultado indica si existe un problema con el nombre id en el parámetro implícito.
    */
    bool existe_problema(const string& id) const;
    
    /** @brief Consulta si la intersección entre dos conjuntos es vacía 

        \pre <em>cierto</em>
        \post El resultado indica si la intersección entre los problemas del parámetro implícito y los problemas del conjunto c_prob es vacía. En caso que no lo sea, prob contiene el primer problema repetido.
    */
    bool interseccion_vacia(const Cjt_problemas& c_prob, Problema& prob) const;
    
    /** @brief Consulta un problema de la colección 

        \pre Existe un problema con el nombre id en el parámetro implícito.
        \post prob contiene el problema con el nombre id del parámetro implícito.
    */
    void consultar_problema(const string& id, Problema& prob) const;
    
    //Escritura
    
    /** @brief Operación de escritura
     
        \pre <em>cierto</em>
        \post Se han escrito en el canal standard de salida los problemas del parámetro implícito en orden creciente por el ratio. En caso de empate, por orden creciente del nombre. Para cada problema también se muestra el número de envíos totales y el número de envíos con éxito a dicho problema. 
    */
    void escribir() const;
    
    /** @brief Operación de escritura
     
        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida en orden creciente por nombre los problemas del parámetro implícito. También se escribe el número de envíos realizados a cada problema.
    */
    void escribir_problemas_usuario() const;
    
private:
    /** @brief Contenedor de problemas  */
    map<string, Problema> colec_prob;
};
#endif
