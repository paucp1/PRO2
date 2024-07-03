/** @file Cjt_problemas.cc
    @brief Código de la clase Cjt_problemas
*/


#include "Cjt_problemas.hh"


Cjt_problemas::Cjt_problemas() {
    colec_prob = map<string, Problema>();
}

void Cjt_problemas::anadir_problema(const Problema& p) {
    colec_prob.insert(make_pair(p.nombre(), p));
}

void Cjt_problemas::modificar_problema(const Problema& p) {
    colec_prob[p.nombre()] = p;
}

void Cjt_problemas::borrar_problema_usuario(const Problema& p) {
    colec_prob.erase(p.nombre());
}

int Cjt_problemas::numero_problemas() const {
    return colec_prob.size();
}

bool Cjt_problemas::existe_problema(const string& id) const {
    map<string, Problema>::const_iterator it = colec_prob.find(id);
    return it != colec_prob.end();
}

bool Cjt_problemas::interseccion_vacia(const Cjt_problemas& c_prob, Problema& prob) const {
    map<string, Problema>::const_iterator it_1 = colec_prob.begin();
    while (it_1 != colec_prob.end()) {
        if (c_prob.existe_problema(it_1 ->first)) {
            prob = it_1 -> second;
            return false;
        }
        ++it_1;
    }
    return true;
}

void Cjt_problemas::consultar_problema(const string& id, Problema& prob) const {
    map<string, Problema>::const_iterator it = colec_prob.find(id);
    prob = it->second;
}

void Cjt_problemas::escribir() const {
    set<Problema> colec_prob_aux;
    map<string, Problema>::const_iterator it = colec_prob.begin();
    while (it != colec_prob.end()) {
        colec_prob_aux.insert(it -> second);
        ++it;
    }
    set<Problema>::const_iterator it_aux = colec_prob_aux.begin();
    while (it_aux != colec_prob_aux.end()) {
        it_aux->escribir();
        ++it_aux;
    }
}

void Cjt_problemas::escribir_problemas_usuario() const {
    map<string, Problema>::const_iterator it = colec_prob.begin();
    while (it != colec_prob.end()) {
        it->second.escribir_problema_usuario();
        ++it;
    }
}   

