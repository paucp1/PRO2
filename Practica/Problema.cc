/** @file Problema.cc
    @brief Código de la clase Problema
*/


#include "Problema.hh"

Problema::Problema() {
    e_realizados = 0;
    e_correctos = 0;
    rat = 1;
}
    
Problema::Problema(const string& id) {
    nom = id;
    e_realizados = 0;
    e_correctos = 0;
    rat = 1;
}

void Problema::actualizar_estadisticas(int r) {
    ++e_realizados;
    if (r == 1) ++e_correctos;
    calcular_ratio();
}

string Problema::nombre() const {
    return nom;
}
    
int Problema::envios_totales() const {
    return e_realizados;
}

int Problema::envios_correctos() const {
    return e_correctos;
}

double Problema::ratio() const {
    return rat;
}

bool Problema::operator<(const Problema& p) const {
    if (rat != p.rat) return rat < p.rat;
    return nom < p.nom;
}
  
void Problema::escribir() const {
    cout << nom << "(" << e_realizados << "," << e_correctos << "," << rat << ")" << endl;
}
 
void Problema::escribir_problema_usuario() const {
    cout << nom << "(" << e_realizados << ")" << endl;
}

void Problema::calcular_ratio() {
    double num = e_realizados + 1;
    double den = e_correctos + 1;
    rat = num/den;
}
