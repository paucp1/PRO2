/** @file Curso.hh
    @brief Especificación de la clase Curso 
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include "Problema.hh"
#include "Cjt_problemas.hh"
#include "Sesion.hh"
#include "Cjt_sesiones.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <string>
#endif

/** @class Curso
    @brief Representa un curso compuesto por sesiones del repositorio

    Tiene un entero que lo identifica y está formado por un subconjunto de sesiones distintas del repositorio. La intersección entre cualquier par de sesiones del curso es vacía. 
*/

class Curso
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una sesión.
        \pre <em>cierto</em>
        \post El resultado es un curso sin identificador y sin ninguna sesión.
    */
    Curso();
    
    /** @brief Creadora con valores concretos 

        \pre <em>cierto</em>
        \post El resultado es un curso con identificador i y sin ninguna sesión.
    */
    Curso(int i);
    
    //Modificadoras
    
    /** @brief Incrementador del número de usuarios inscritos actualmente al curso 

        \pre <em>cierto</em>
        \post Se incrementa en una unidad el número de usuarios inscritos actualmente al parámetro implícito.
    */
    void incrementar_usuario();
    
    /** @brief Decrementador del número de usuarios inscritos actualmente al curso 

        \pre <em>cierto</em>
        \post Se decrementa en una unidad el número de usuarios inscritos actualmente al parámetro implícito.
    */
    void decrementar_usuario();
    
    /** @brief Actualizadora del número de usuarios que han completado el curso 

        \pre <em>cierto</em>
        \post Se incrementa en una unidad el número de usuarios que han completado el parámetro implícito.
    */
    void incrementar_usuario_completado();
    
    //Consultoras
    
    /** @brief Consultora del identificador 

        \pre <em>cierto</em>
        \post El resultado es el identificador del parámetro implícito.
    */
    int identificador() const;
    
    /** @brief Consultora del número de usuarios inscritos actualmente al curso 

        \pre <em>cierto</em>
        \post El resultado es el nombre de usuarios inscritos actualmente al parámetro implícito.
    */
    int usuarios_inscritos() const;
    
    /** @brief Consulta la sesión de un problema en un curso 

        \pre <em>cierto</em>
        \post ses el nombre de la sesión donde se realiza el problema con nombre id en el parámetro implícito. Si el problema id no pertenece al parámetro implícito se retorna false.
    */
    bool sesion_problema(const string& id, string& ses) const;
    
    /** @brief Consulta los problemas iniciales de las sesiones 

        \pre <em>cierto</em>
        \post c_prob contiene los problemas iniciales de las sesiones que forman parte del parámetro implícito.
    */
    void consultar_problemas_iniciales(Cjt_problemas& c_prob) const;
    
    /** @brief Consulta la sesión de un curso 

        \pre Existe una sesión con nombre id en el parámetro implícito.
        \post ses contiene la sesión con nombre id del parámetro implícito.
    */
    void consultar_sesion(const string& id, Sesion& ses) const;
    
    //Lectura y escritura
    
    /** @brief Operación de lectura y comprovación de la correción del curso

        \pre Está preparado en el canal standard de entrada un número de sesiones S, seguido de una secuencia de S nombres de sesiones. c_ses es un Cjt_sesiones válido.
        \post El parámetro implícito contine el subconjunto de sesiones del repositorio en caso de que el curso esté formado correctamente, es decir, que la intersección entre las sesiones leídas sea vacía.
    */
    void leer_comprovar(const Cjt_sesiones& c_ses, bool& v);
    
    /** @brief Operación de lectura 

        \pre Está preparado en el canal standard de entrada un número de sesiones S, seguido de una secuencia de S nombres de sesiones. c_ses es un Cjt_sesiones válido.
        \post El parámetro implícito contine el subconjunto de sesiones del repositorio.
    */
    void leer(const Cjt_sesiones& c_ses);
    
    /** @brief Operación de escritura 

        \pre <em>cierto</em>
        \post Se ha escrito en el canal standard de salida el identificador del parámetro implícito, el número de usuarios totales que lo han completado, el número de usuarios inscritos actualmente, el número de sesiones que lo forman y los identificadores de dichas sesiones en el mismo orden en el que se leyeron cuando se creo el curso.
    */
    void escribir() const;

private:
    /** @brief Identificador del curso  */
    int ident;
    
    /** @brief Número de usuarios que han completado el curso  */
    int usu_completado;
    
    /** @brief Número de usuarios inscritos actualmente al curso  */
    int usu_inscritos;
    
    /** @brief Sesiones del curso  */
    vector<Sesion> vec_ses;
    
    /** @brief Problemas del curso  */
    map<string, string> problemas_curso;
};
#endif
