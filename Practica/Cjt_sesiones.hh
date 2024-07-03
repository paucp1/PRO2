/** @file Cjt_sesiones.hh
    @brief Especificación de la clase Cjt_sesiones 
*/

#ifndef _CJT_SESIONES_HH_
#define _CJT_SESIONES_HH_

#include "Sesion.hh"


#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

/** @class Cjt_sesiones
    @brief Representa un repositorio de sesiones compuestas por problemas de la colección

    Los elementos del repositorio (de tipo Sesion) se encuentran ordenados crecientemente por el nombre. Se pueden consultar y añadir nuevos elementos.
*/

class Cjt_sesiones
{
public:
    //Constructora
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una colección de problemas.
        \pre <em>cierto</em>
        \post El resultado es un repositorio de sesiones vacio.
    */
    Cjt_sesiones();
    
    //Modificadoras
    
    /** @brief Añade una sesión al repositorio 

        \pre El parámetro implícito no contine ninguna sesión con el nombre de s.
        \post El parámetro implícito contiene la sesión s.
    */
    void anadir_sesion(const Sesion& s);
    
    //Consultoras
    
    /** @brief Consulta el número de sesiones del repositorio 

        \pre <em>cierto</em>
        \post El resultado es el número de sesiones del parámetro implícito.
    */
    int numero_sesiones() const;
    
    /** @brief Consulta si existe una sesión en el repositorio 

        \pre <em>cierto</em>
        \post El resultado indica si existe una sesión con el nombre id en el parámetro implícito.
    */
    bool existe_sesion(const string& id) const;
    
    /** @brief Consulta una sesión del repositorio 

        \pre Existe una sesión con el nombre id en el parámetro implícito.
        \post ses contiene la sesión con el nombre id del parámetro implícito.
    */
    void consultar_sesion(const string& id, Sesion& ses) const;
    
    //Escritura
    
    /** @brief Operación de escritura
     
        \pre <em>cierto</em>
        \post Se han escrito en el canal standard de salida las sesiones del parámetro implícito en orden creciente por el nombre. Cada sesión muestra su número de problemas y los nombres de dichos problemas, siguiendo su estructura de prerequisitos en postorden.
    */
    void escribir() const;

private:
    /** @brief Contenedor de sesiones  */
    map<string, Sesion> repositorio_ses;
};
#endif
