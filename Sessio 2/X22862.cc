/*
Escribe una miniaplicación que lea un conjunto de estudiantes y ofrezca la posibilidad de aplicarle los siguientes tratamientos.

añadir un nuevo estudiante (opción -1); si no es posible, escribir un mensaje informando del motivo
consultar la nota de un estudiante a partir de su DNI (opción -2); si no es posible, escribir un mensaje informando del motivo
modificar la nota de un estudiante (opción -3); si no es posible, escribir un mensaje informando del motivo
redondear la nota, a la décima más cercana, a todos los estudiantes del conjunto (opción -4)
escribir el conjunto de estudiantes (opción -5)
Organiza el programa principal como un proceso iterativo que, tras leer el conjunto, lea un valor entre -1 y -6 indicativo de la opción que queremos aplicar (la opción -6 será la de terminar el programa), después lea los datos necesarios para ella y proceda a aplicarla.

Observa que las opciones -1, -2, -3 y -5 corresponden a operaciones que ya existen en la clase Cjt_estudiants, por lo que solo necesitarás comprobar la precondición de las mismas antes de realizar las correspondientes llamadas. En caso de no cumplirse la precondición no debe realizarse la llamada, simplemente ha de escribirse un mensaje informando de la situación. En algunos casos necesitarás también operaciones de la clase Estudiant.

La opción -4 requiere programar una operación nueva en el propio fichero solution.cc (o como se llame tu solución). Dicha operación estará basada en operaciones de las clases Estudiant y Cjt_estudiants. Para evitar problemas de precisión con el tipo double al realizar los redondeos, copia y usa el siguiente código en tu solución

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 
Entrada

Una secuencia de instrucciones, definidas mediante los valores de -1 a -6, cada una con datos en el formato adecuado, que se puede deducir del juego de pruebas público.

Salida

Los resultados o los mensajes producidos por las instrucciones de la entrada. El formato exacto se puede deducir del juego de pruebas público.

Observación

Solo has de entregar el programa principal, que deberá contener los #include necesarios para poder usar las clases Estudiant y Cjt_estudiants. Importante: usa las versiones de dichas clases que te proporcionamos con los “public files” (icono del gatito).

Como siempre, valida tu solución con el juego de pruebas público y prueba otros casos interesantes antes de subirla al Jutge, como por ejemplo que el conjunto esté vacío.
  */

#include "Cjt_estudiants.hh"
#include "Estudiant.hh"
#include <iostream>
using namespace std;

double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

int main () {
    Cjt_estudiants c;
    c.llegir();
    int option;
    cin >> option;
    
    int iden;
    double grade;
    Estudiant est;
    while (option != -6) {
        if (option == -1) {
            cin >> iden >> grade;
            if (not c.existeix_estudiant(iden) and c.mida() < c.mida_maxima()) {
                Estudiant est(iden);
                if (grade >= 0 and grade <= est.nota_maxima()) {
                    est.afegir_nota(grade);
                    c.afegir_estudiant(est);
                }
                
                else {
                    c.afegir_estudiant(est);
                }
            }
            
            else if (c.existeix_estudiant(iden)) {
                cout << "el estudiante " << iden << " ya estaba" << endl << endl;
            }
            
            else {
                cout << "el conjunto esta lleno" << endl << endl;
            }
        }
        
        else if (option == -2) {
            cin >> iden;
            if (c.existeix_estudiant(iden)) {
                if (c.consultar_estudiant(iden).te_nota()) {
                    cout << "el estudiante " << iden << " tiene nota " << c.consultar_estudiant(iden).consultar_nota() << endl << endl;
                }
                else {
                    cout << "el estudiante " << iden << " no tiene nota" << endl << endl;
                }
            }
            
            else {
                cout << "el estudiante " << iden << " no esta" << endl << endl;
            }
        }
        
        else if (option == -3) {
            cin >> iden >> grade;
            if (c.existeix_estudiant(iden)) {
                est = c.consultar_estudiant(iden);
                if (est.te_nota()) {
                    est.modificar_nota(grade);
                }
                else {
                    est.afegir_nota(grade);
                }
                c.modificar_estudiant(est);
            }
            
            else {
                cout << "el estudiante " << iden << " no esta" << endl << endl;
            }
        }
        
        else if (option == -4) {
            int tam = c.mida();
            for (int i = 1; i <= tam; ++i) {
                est = c.consultar_iessim(i);
                if (est.te_nota()) {
                    est.modificar_nota(redondear(est.consultar_nota()));
                    c.modificar_iessim(i, est);
                }
            }
        }
        
        else if (option == -5) {
            c.escriure();
            cout << endl;
        }
        
        cin >> option;
    }
}
