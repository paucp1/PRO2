/*
Volem calcular els valors màxim i mínim d’un vector d’enters mitjançant un sol recorregut.

Heu de lliurar un únic fitxer amb tres versions diferents de l’operació que fa la tasca demanada. Feu servir les següents capçaleres i declaracions. NO heu de lliurar cap mètode main.

 
 #include <vector>
 using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
 // codi
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
 // codi
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
 // codi
 }
 

Per provar la vostra solució podeu fer servir els vectorIOint.* que trobareu a la carpeta “public” clicant l’icona del gatet. En qualsevol cas, us recomanen que feu un programa a part amb un main per fer les proves abans de lliurar la solució.
*/

   #include <vector>
 using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
     parint p;
     p.prim = v[0];
     p.seg = v[0];
     for (int i = 1; i < v.size(); ++i) {
         if (p.prim < v[i]) p.prim = v[i];
         if (p.seg > v[i]) p.seg = v[i];
     }
     return p;
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
     pair<int, int> resul;
     resul.first = v[0];
     resul.second = v[0];
     for (int i = 1; i < v.size(); ++i) {
         if (v[i] > resul.first) resul.first = v[i];
         if (v[i] < resul.second) resul.second = v[i];
     }
     return resul;
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
     x = v[0];
     y = v[0];
     for (int i = 1; i < v.size(); ++i) {
         if (v[i] > x) x = v[i];
         if (v[i] < y) y = v[i];
     }
 }
  
