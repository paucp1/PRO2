/*
Escribe un programa que obtenga las sumas de varias secuencias de enteros.

Entrada

Una línea con dos enteros n > 0 y x. A continuación, n secuencias de enteros separadas por saltos de linea. Todas las secuencias contienen el valor x.

Salida

Para cada secuencia, la suma de todos los elementos que preceden a la primera aparición de x.

Observación

Ayuda: después de haber encontrado x, puedes saltar los restantes elementos de una línea mediante la operación getline, que viene dada por el #include <iostream>. Se usa mediante la llamada getline(cin,s); donde s es una variable cualquiera de tipo string; esto avanza hasta el principio de la siguiente línea (y guarda en s los caracteres que encuentra, que en este ejercicio no se han de tratar).

Como siempre, valida tu solución con el juego de pruebas público y prueba otros casos interesantes antes de subirla al Jutge.
  */

#include <iostream>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
      int sum = 0, xif;
      cin >> xif;
      while (xif != x) {
          sum = sum + xif;
          cin >> xif;
      }
      string s;
      getline(cin, s);
      cout << "La suma de la secuencia " << i + 1 << " es " << sum << endl;
  }
}
