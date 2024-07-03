/** @file Problema.hh
    @brief Especificación de la clase Problema 
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
using namespace std;


/** @class Problema
    @brief Representa un problema de programación
    
    Se caracteriza por su nombre, el número total de envíos realizados, cuántos de ellos han sido juzgados como correctos y el ratio.
*/
class Problema
{
public:
    //Constructoras
    
    /** @brief Creadora por defecto 

        Se ejecuta automáticamente al declarar un problema.
        \pre <em>cierto</em>
        \post El resultado es un problema sin nombre, número de envíos 0, número de envíos correctos 0 y ratio 1.
    */
    Problema();
    
    /** @brief Creadora con valores concretos

        \pre <em>cierto</em> 
        \post El resultado es un problema con nombre id, número de envíos 0, número de envíos correctos 0 y ratio 1.
    */
    Problema(const string& id);
    
    //Modificadoras
    
    /** @brief Actualizadora de las estadísticas
     
        \pre r = 1 o r = 0
        \post Se incrementa una unidad el número de envíos totales al parámetro implícito. Si r = 1 se incrementa una unidad el número de envíos correctos. Se actualiza el ratio.
    */
    void actualizar_estadisticas(int r);
    
    //Consultoras
    
    /** @brief Consultora del nombre
    
        \pre <em>cierto</em>
        \post El resultado es el nombre del parámetro implícito.
    */
    string nombre() const;

    /** @brief Consultora del número de envíos totales
    
        \pre <em>cierto</em>
        \post El resultado es el número de envíos totales al parámetro implícito.
    */    
    int envios_totales() const;
    
    /** @brief Consultora del número de envíos correctos
     
        \pre <em>cierto</em>
        \post El resultado es el número de envíos correctos al parámetro implícito.
    */
    int envios_correctos() const;
    
    /** @brief Consultora del ratio
     
        \pre <em>cierto</em>
        \post El resultado es el ratio del parámetro implícito.
    */
    double ratio() const;
    
    /** @brief Consultora del orden de dos problemas
     
        \pre <em>cierto</em>
        \post El resultado indica si el parámetro implícito es menor al problema p.
    */
    bool operator<(const Problema& p) const;
    
    // Escritura de problema
    
    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito los atributos del parámetro implícito en el canal
      standard de salida. 
    */   
    void escribir() const;
    
    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se han escrito el nombre del parámetro implícito y el número de envíos realizados en el canal
      standard de salida. 
    */ 
    void escribir_problema_usuario() const;
    
private:
    /** @brief Identificador del problema  */
    string nom;
    
    /** @brief Envíos totales al problema  */
    int e_realizados;
    
    /** @brief Envíos correctos al problema  */
    int e_correctos;
    
    /** @brief Ratio del problema  */
    double rat;
    
    /** @brief Calculadora del ratio

      \pre <em>cierto</em>
      \post Se ha calculado el ratio del parámetro implícito. 
    */
    void calcular_ratio();   
};
#endif
