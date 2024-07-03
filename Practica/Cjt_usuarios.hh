/** @file Cjt_usuarios.hh
    @brief Especificación de la clase Cjt_usuarios 
*/

#ifndef _CJT_USUARIOS_HH_
#define _CJT_USUARIOS_HH_

#include "Usuario.hh"
#include "Curso.hh"
#include "Cjt_cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

/** @class Cjt_usuarios
    @brief Representa un conjunto de usuarios

    Los elementos del conjunto (de tipo Usuario) se encuentran ordenados crecientemente por el nombre. Se pueden consultar, añadir y eliminar sus elementos.
*/

class Cjt_usuarios
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una colección de problemas.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de usuarios vacio.
    */
    Cjt_usuarios();
    
    //Modificadoras
    
    /** @brief Añade un usuario al conjunto 

        \pre El parámetro implícito no contine ningun usuario con el nombre de u.
        \post El parámetro implícito contiene el usuario u.
    */
    void anadir_usuario(const Usuario& u);
    
    /** @brief Elimina un usuario del conjunto 

        \pre El parámetro implícito contine un usuario con nombre id.
        \post El parámetro implícito no contiene el usuario con nombre id.
    */
    void eliminar_usuario(Cjt_cursos& conj_curs, const string& id);
    
    /** @brief Modifica un usuario del conjunto 

        \pre El parámetro implícito contine un usuario con el nombre de u.
        \post El usuario del parámetro implícito original con el nombre de u ha quedado sustituido por u.
    */
    void modificar_usuario(const Usuario& u);
    
    //Consultoras
    
    /** @brief Consulta el número de usuarios del conjunto 

        \pre <em>cierto</em>
        \post El resultado es el número de usuarios del parámetro implícito.
    */
    int numero_usuarios() const;
    
    /** @brief Consulta si existe un usuario en el conjunto 

        \pre <em>cierto</em>
        \post El resultado indica si existe un usuario con el nombre id en el parámetro implícito.
    */
    bool existe_usuario(const string& id) const;
    
    /** @brief Consulta un usuario del conjunto 

        \pre Existe un usuario con el nombre id en el parámetro implícito.
        \post u contiene el usuario con el nombre id del parámetro implícito.
    */
    void consultar_usuario(const string& id, Usuario& u) const;
    
    //Escritura
    
    /** @brief Operación de escritura
     
        \pre <em>cierto</em>
        \post Se han escrito en el canal standard de salida los usuarios del parámetro implícito en orden creciente por el nombre. Cada usuario muestra el número de envíos totales que ha realizado, el número de problemas resueltos satisfactoriamente, el número de problemas que ha intentado resolver y el identificador del curso en el que está inscrito, o un zero en caso de que no esté inscrito en ninguno.
    */
    void escribir() const;
    
private:
    /** @brief Contenedor de cursos  */
    map<string, Usuario> conjunto_usuarios;
};
#endif
