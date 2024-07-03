/** @file Cjt_usuarios.cc
    @brief Código de la clase Cjt_usuarios
*/


#include "Cjt_usuarios.hh"


Cjt_usuarios::Cjt_usuarios() {
    conjunto_usuarios = map<string, Usuario>();
}

void Cjt_usuarios::anadir_usuario(const Usuario& u) {
    conjunto_usuarios.insert(make_pair(u.nombre(), u));
}

void Cjt_usuarios::eliminar_usuario(Cjt_cursos& conj_curs, const string& id) {
    Usuario usu;
    consultar_usuario(id, usu);
    if (usu.esta_inscrito()) {
        Curso c_act;
        conj_curs.consultar_curso(usu.consultar_curso(), c_act);
        c_act.decrementar_usuario();
        conj_curs.modificar_curso(c_act);
    }
    conjunto_usuarios.erase(id);
}

void Cjt_usuarios::modificar_usuario(const Usuario& u) {
    conjunto_usuarios[u.nombre()] = u;
}

int Cjt_usuarios::numero_usuarios() const {
    return conjunto_usuarios.size();
}

bool Cjt_usuarios::existe_usuario(const string& id) const {
    map<string, Usuario>::const_iterator it = conjunto_usuarios.find(id);
    return it != conjunto_usuarios.end();
}

void Cjt_usuarios::consultar_usuario(const string& id, Usuario& u) const {
    map<string, Usuario>::const_iterator it = conjunto_usuarios.find(id);
    u = it->second;
}

void Cjt_usuarios::escribir() const {
    map<string, Usuario>::const_iterator it = conjunto_usuarios.begin();
    while (it != conjunto_usuarios.end()) {
        it->second.escribir();
        ++it;
    }
}
