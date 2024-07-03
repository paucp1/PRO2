/** @file Curso.cc
    @brief Código de la clase Curso
*/


#include "Curso.hh"


Curso::Curso() {
    usu_completado = 0;
    usu_inscritos = 0;
    vec_ses = vector<Sesion>();
    problemas_curso = map<string, string>();
}

Curso::Curso(int i) {
    ident = i;
    usu_completado = 0;
    usu_inscritos = 0;
    vec_ses = vector<Sesion>();
    problemas_curso = map<string, string>();
}    

void Curso::incrementar_usuario() {
    ++usu_inscritos;
}

void Curso::decrementar_usuario() {
    --usu_inscritos;
}

void Curso::incrementar_usuario_completado() {
    ++usu_completado;
}

int Curso::identificador() const {
    return ident;
}

int Curso::usuarios_inscritos() const {
    return usu_inscritos;
}

bool Curso::sesion_problema(const string& id, string& ses) const {
    map<string, string>::const_iterator it = problemas_curso.find(id);
    if (it != problemas_curso.end()) {
        ses = it->second;
        return true;
    }
    return false;
}

void Curso::consultar_problemas_iniciales(Cjt_problemas& c_prob) const {
    int mida = vec_ses.size();
    for (int i = 0; i < mida; ++i) {
        Problema prob;
        vec_ses[i].problema_inicial(prob);
        c_prob.anadir_problema(prob);
    }
}

void Curso::consultar_sesion(const string& id, Sesion& ses) const {
    int i = 0;
    int size = vec_ses.size();
    bool trobat = false;
    while (i < size and not trobat) {
        if (vec_ses[i].nombre() == id) trobat = true;
        ++i;
    }
    ses = vec_ses[i - 1];
}

void Curso::leer_comprovar(const Cjt_sesiones& c_ses, bool& v) {
    int n_ses;
    int i = 0;
    v = true;
    cin >> n_ses;
    string id_ses;
    while (v and i < n_ses) {
        cin >> id_ses;
        Sesion ses_act;
        c_ses.consultar_sesion(id_ses, ses_act);
        v = ses_act.problemas_contenidos(problemas_curso);
        if (v) vec_ses.push_back(ses_act);
        ++i;
    }
    
    while (i < n_ses) {
        cin >> id_ses;
        ++i;
    }
}

void Curso::leer(const Cjt_sesiones& c_ses) {
    int n_ses;
    cin >> n_ses;
    string id_ses;
    for (int i = 0; i < n_ses; ++i) {
        cin >> id_ses;
        Sesion ses_act;
        c_ses.consultar_sesion(id_ses, ses_act);
        ses_act.problemas_contenidos(problemas_curso);
        vec_ses.push_back(ses_act);
    }
}

void Curso::escribir() const {
    cout << ident << " " << usu_completado << " " << usu_inscritos << " " << vec_ses.size() << " (";
    cout << vec_ses[0].nombre();
    for (int i = 1; i < vec_ses.size(); ++i) {
        cout << " " << vec_ses[i].nombre();
    }
    cout << ")" << endl;
}
