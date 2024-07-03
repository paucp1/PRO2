/** @file Cjt_cursos.hh
    @brief Especificación de la clase Cjt_cursos 
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#endif

/** @class Cjt_cursos
    @brief Representa un conjunto de cursos compuestos por sesiones del repositorio

    Los elementos del conjunto (de tipo Curso) se encuentran ordenados crecientemente por el identificador. Se pueden consultar y añadir nuevos elementos.
*/

class Cjt_cursos
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una colección de problemas.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de cursos vacio.
    */
    Cjt_cursos();
    
    //Modificadoras
    
    /** @brief Añade un curso al conjunto 

        \pre El parámetro implícito no contine ningun curso con el identificador de c.
        \post El parámetro implícito contiene el curso c.
    */
    void anadir_curso(const Curso& c);
    
    /** @brief Modifica un curso del conjunto 

        \pre El parámetro implícito contine un curso con el identificador de c.
        \post El curso del parámetro implícito original con el identificador de i ha quedado sustituido por c. En ningún caso se modifica el contenido del curso, sólo el número de usuarios inscritos actualmente o el número de usuarios que lo han completado.
    */
    void modificar_curso(const Curso& c);
    
    //Consultoras
    
    /** @brief Consulta el número de cursos del conjunto 

        \pre <em>cierto</em>
        \post El resultado es el número de cursos del parámetro implícito.
    */
    int numero_cursos() const;
    
    /** @brief Consulta si existe un curso en el conjunto 

        \pre <em>cierto</em>
        \post El resultado indica si existe un curso con el identificador i en el parámetro implícito.
    */
    bool existe_curso(int i) const;
    
    /** @brief Consulta la sesión de un problema en un curso 

        \pre i es un curso válido del parámetro implícito.
        \post ses el nombre de la sesión donde se realiza el problema con nombre id en el curso i del parámetro implícito. Si el problema id no pertenece al curso i se retorna false.
    */
    bool sesion_problema_conj(int i, const string& p, string& result) const;
    
    /** @brief Consulta un curso del conjunto 

        \pre Existe un curso con el identificador i en el parámetro implícito.
        \post curs contiene el curso con el identificador i del parámetro implícito.
    */
    void consultar_curso(int i, Curso& curs) const;
    
    //Escritura
    
    /** @brief Operación de escritura
     
        \pre <em>cierto</em>
        \post Se han escrito en el canal standard de salida los cursos del parámetro implícito en orden creciente por el identificador. Cada curso muestra el número de usuarios totales que lo han completado, el número de usuarios inscritos actualmente, el número de sesiones que lo forman y los identificadores de dichas sesiones en el mismo orden en el que se leyeron cuando se creo el curso.
    */
    void escribir () const;
    
private:
    /** @brief Contenedor de cursos  */
    map<int, Curso> conjunto_cursos;
};
#endif
