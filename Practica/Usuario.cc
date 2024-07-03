/** @file Usuario.cc
    @brief Código de la clase Usuario
*/


#include "Usuario.hh"


Usuario::Usuario() {
    inscrito = false;
    problemas_intentados = 0;
    problemas_resueltos = 0;
    envios_totales = 0;
    conj_problemas_resueltos = Cjt_problemas();
    conj_problemas_enviables = Cjt_problemas();
}

Usuario::Usuario(const string& id) {
    nom = id;
    inscrito = false;
    problemas_intentados = 0;
    problemas_resueltos = 0;
    envios_totales = 0;
    conj_problemas_resueltos = Cjt_problemas();
    conj_problemas_enviables = Cjt_problemas();
}

void Usuario::inscribir(Cjt_cursos& c_curs, int i) {
    inscrito = true;
    curso_inscrito = i;
    Curso curs_act;
    c_curs.consultar_curso(i, curs_act);
    curs_act.incrementar_usuario();
    curs_act.consultar_problemas_iniciales(conj_problemas_enviables);
    Problema prob;
    while (not conj_problemas_enviables.interseccion_vacia(conj_problemas_resueltos, prob)) {
        conj_problemas_enviables.borrar_problema_usuario(prob);
        string ses;
        curs_act.sesion_problema(prob.nombre(), ses);
        Sesion ses_act;
        curs_act.consultar_sesion(ses, ses_act);
        pair<Problema, Problema> problemas_siguientes;
        ses_act.consultar_problemas_siguientes(prob.nombre(), problemas_siguientes);
        actualizar_conjuntos(problemas_siguientes, ses_act);
    }
    if (conj_problemas_enviables.numero_problemas() == 0) {
        curs_act.incrementar_usuario_completado();
        curs_act.decrementar_usuario();
        inscrito = false;
        curso_inscrito = 0;
    }
    c_curs.modificar_curso(curs_act);
    cout << curs_act.usuarios_inscritos() << endl;
}

void Usuario::actualizar_estadisticas(const Curso& curs, const string& id, int r) {
    ++envios_totales;
    Problema prob_act;
    conj_problemas_enviables.consultar_problema(id, prob_act);
    if (prob_act.envios_totales() == 0) ++problemas_intentados;
    prob_act.actualizar_estadisticas(r);
    conj_problemas_enviables.modificar_problema(prob_act);
    if (r == 1) {
        ++problemas_resueltos;
        conj_problemas_enviables.borrar_problema_usuario(prob_act);
        conj_problemas_resueltos.anadir_problema(prob_act);
        string ses;
        curs.sesion_problema(id, ses);
        Sesion ses_act;
        curs.consultar_sesion(ses, ses_act);
        pair<Problema, Problema> problemas_siguientes;
        ses_act.consultar_problemas_siguientes(id, problemas_siguientes);
        actualizar_conjuntos(problemas_siguientes, ses_act);
        if (conj_problemas_enviables.numero_problemas() == 0) {
            inscrito = false;
        }
    }
}

string Usuario::nombre() const {
    return nom;
}

int Usuario::consultar_curso() const {
    if (inscrito) return curso_inscrito;
    else return 0;
}

bool Usuario::esta_inscrito() const {
    return inscrito;
}

void Usuario::listar_problemas_resueltos() const {
    conj_problemas_resueltos.escribir_problemas_usuario();
}

void Usuario::listar_problemas_enviables() const {
    conj_problemas_enviables.escribir_problemas_usuario();
}

void Usuario::escribir() const {
    cout << nom << "(" << envios_totales << "," << problemas_resueltos << "," << problemas_intentados << ",";
    if (inscrito) cout << curso_inscrito;
    else cout << "0";
    cout << ")" << endl;
}

void Usuario::actualizar_conjuntos(const pair<Problema, Problema>& prob_seg, const Sesion& ses) {
    if (prob_seg.first.nombre() != "vacio") {
        if (conj_problemas_resueltos.existe_problema(prob_seg.first.nombre())) {
            pair<Problema, Problema> problemas_siguientes_found;
            ses.consultar_problemas_siguientes(prob_seg.first.nombre(), problemas_siguientes_found);
            actualizar_conjuntos(problemas_siguientes_found, ses);
        }
        else conj_problemas_enviables.anadir_problema(prob_seg.first);
    }
    
    if (prob_seg.second.nombre() != "vacio") {
        if (conj_problemas_resueltos.existe_problema(prob_seg.second.nombre())) {
            pair<Problema, Problema> problemas_siguientes_found;
            ses.consultar_problemas_siguientes(prob_seg.second.nombre(), problemas_siguientes_found);
            actualizar_conjuntos(problemas_siguientes_found, ses);
        }
        else conj_problemas_enviables.anadir_problema(prob_seg.second);
    }
}
