/** @file Cjt_sesiones.cc
    @brief Código de la clase Cjt_sesiones
*/


#include "Cjt_sesiones.hh"


Cjt_sesiones::Cjt_sesiones() {
    repositorio_ses = map<string, Sesion>();
}

void Cjt_sesiones::anadir_sesion(const Sesion& s) {
    repositorio_ses.insert(make_pair(s.nombre(), s));
}

int Cjt_sesiones::numero_sesiones() const {
    return repositorio_ses.size();
}

bool Cjt_sesiones::existe_sesion(const string& id) const {
    map<string, Sesion>::const_iterator it = repositorio_ses.find(id);
    return it != repositorio_ses.end();
}

void Cjt_sesiones::consultar_sesion(const string& id, Sesion& ses) const {
    map<string, Sesion>::const_iterator it = repositorio_ses.find(id);
    ses = it->second;
}

void Cjt_sesiones::escribir() const {
    map<string, Sesion>::const_iterator it = repositorio_ses.begin();
    while (it != repositorio_ses.end()) {
        it->second.escribir();
        ++it;
    }
}
