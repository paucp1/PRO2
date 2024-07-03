/** @file Cjt_cursos.cc
    @brief Código de la clase Cjt_cursos
*/


#include "Cjt_cursos.hh"


Cjt_cursos::Cjt_cursos() {
    conjunto_cursos = map<int, Curso>();
}

void Cjt_cursos::anadir_curso(const Curso& c) {
    conjunto_cursos.insert(make_pair(c.identificador(), c));
}

void Cjt_cursos::modificar_curso(const Curso& c) {
        conjunto_cursos[c.identificador()] = c;
}

int Cjt_cursos::numero_cursos() const {
    return conjunto_cursos.size();
}

bool Cjt_cursos::existe_curso(int i) const {
    map<int, Curso>::const_iterator it = conjunto_cursos.find(i);
    return it != conjunto_cursos.end();
}

bool Cjt_cursos::sesion_problema_conj(int i, const string& p, string& result) const {
    map<int, Curso>::const_iterator it = conjunto_cursos.find(i);
    return it->second.sesion_problema(p ,result);
}

void Cjt_cursos::consultar_curso(int i, Curso& curs) const {
    map<int, Curso>::const_iterator it = conjunto_cursos.find(i);
    curs = it->second;
}

void Cjt_cursos::escribir () const {
    map<int, Curso>::const_iterator it = conjunto_cursos.begin();
    while (it != conjunto_cursos.end()) {
        it->second.escribir();
        ++it;
    }
}
