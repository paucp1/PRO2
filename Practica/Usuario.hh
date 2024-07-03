/** @file Usuario.hh
    @brief Especificación de la clase Usuario 
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "Problema.hh"
#include "Cjt_problemas.hh"
#include "Sesion.hh"
#include "Curso.hh"
#include "Cjt_cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#include <vector>
#endif

/** @class Usuario
    @brief Representa un usuario

    Tiene un nombre que lo identifica y se guardan estadísticas del número de problemas intentados, cuántos de ellos ha solucionado y el número total de envíos. También se mantiene un registro de todos los problemas resueltos, así como de los que aún no ha resuelto del curso en el cual está inscrito y puede hacerlo. 
*/

class Usuario
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar una sesión
        \pre <em>cierto</em>
        \post El resultado es un usuario sin nombre.
    */
    Usuario();
    
    /** @brief Creadora con valores concretos 

        \pre <em>cierto</em>
        \post El resultado es un usuario con nombre id.
    */
    Usuario(const string& id);
    
    //Modificadoras
    
    /** @brief Se inscribe un usuario a un curso

        \pre El parámetro implícito está registrado a la plataforma y no está inscrito a ningún curso. El curso con identificador i existe.
        \post El parámetro implícito pasa a estar inscrito al curso i. 
    */
    void inscribir(Cjt_cursos& c_curs, int i);
    
    /** @brief Actualizadora de las estadísticas
     
        \pre El parámetro implícito está inscrito en el curso donde aparece el problema con nombre id. El problema con nombre id pertenece al conjunto de problemas a los que el parámetro implícito puede enviar una solución por cumplir los prerequisitos. Además r = 1 o r = 0.
        \post Se incrementa una unidad el número de envíos por parte del parámetro implícito a id. Se incrementa una unidad el número de envíos totales del parámetro implícito. En caso de que sea la primera vez que el parámetro implícito envía una solución a id, se incrementa una unida el número de problemas intentados por el parámetro implícito. Si r = 1 se incrementa una unidad el número de problemas correctamente resueltos por el parámetro implícito y se lleva a cabo la actualización de los problemas resueltos y enviables del parámetro implícito. Si con ello el parámetro implícito ha completado el curso, deja de estar inscrito a este.
    */
    void actualizar_estadisticas(const Curso& curs, const string& id, int r);
    
    //Consultoras
    
    /** @brief Consultora del nombre 

        \pre <em>cierto</em>
        \post El resultado es el nombre del parámetro implícito.
    */
    string nombre() const;
    
    /** @brief Consultora del curso 

        \pre <em>cierto</em>
        \post El resultado es el identificador del curso en el que está inscrito el parámetro implícito. Si el parámetro implícito no está inscrito a ningún curso, se retorna un 0.
    */
    int consultar_curso() const;
    
    /** @brief Consultora de si un usuario está inscrito a algún curso 

        \pre <em>cierto</em>
        \post El resultado indica si parámetro implícito está inscrito a algún curso.
    */
    bool esta_inscrito() const;
    
    //Escritura
    
    /** @brief Operación de escritura de los problemas solucionados con éxito por el usuario

        \pre El parámetro implícito está registrado a la plataforma.
        \post Se ha escrito en el canal standard de salida en orden creciente por nombre todos los problemas solucionados con éxito por el parámetro implícito, ya sea en el curso en el cual está inscrito actualmente o en cursos anteriores. También se escribe el número de envíos realizados por el parámetro implícito para cada problema.
    */
    void listar_problemas_resueltos() const;
    
    /** @brief Operación de escritura de los problemas que el usuario no ha solucionado todavía en el curso en el que está inscrito, pero a los cuales ya puede realizar un envío.

        \pre El parámetro implícito está registrado a la plataforma e inscrito en algún curso.
        \post Se ha escrito en el canal standard de salida en orden creciente por nombre los problemas no solucionados todavía por el parámetro implícito en el curso actual, pero a los cuales puede realizar envíos. También se escribe el número de envíos realizados por el parámetro implícito para cada problema.
    */
    void listar_problemas_enviables() const;
    
        /** @brief Operación de escritura

        \pre El parámetro implícito está registrado a la plataforma.
        \post Se ha escrito en el canal standard de salida el nombre del parámetro implícito, así como el número de envíos totales que ha realizado, el número de problemas resueltos satisfactoriamente, el número de problemas que ha intentado resolver y el identificador del curso en el que está inscrito, o un zero en caso de que no esté inscrito en ninguno.
    */
    void escribir() const;
    
private:
    /** @brief Identificador del usuario  */
    string nom;
    
    /** @brief Indica si el usuario está inscrito a algún curso  */
    bool inscrito;
    
    /** @brief Curso al cual el usuario está inscrito, en caso de que lo esté en alguno  */
    int curso_inscrito;
    
    /** @brief Número de problemas intentados por el usuario  */
    int problemas_intentados;
    
    /** @brief Número de problemas resueltos por el usuario  */
    int problemas_resueltos;
    
    /** @brief Número de envíos totales a problemas del usuario  */
    int envios_totales;
    
    /** @brief Conjunto de problemas resueltos por el usuario  */
    Cjt_problemas conj_problemas_resueltos;
    
    /** @brief Conjunto de problemas enviables por el usuario  */
    Cjt_problemas conj_problemas_enviables;
    
    /** @brief Actualizadora de los conjuntos de problemas enviables y resueltos por parte del usuario 

        \pre Los problemas de prob_seg forman parte de ses o són problemas vacíos.
        \post Se actualiza el conjunto de problemas enviables con los  problemas de prob_seg que no sean vacíos. En caso de que alguno de estos problemas forme parte del conjunto de problemas resueltos, se repite el proceso con los problemas siguientes del problema en cuestión de ses. 
    */
    void actualizar_conjuntos(const pair<Problema, Problema>& prob_seg, const Sesion& ses);
};
#endif
