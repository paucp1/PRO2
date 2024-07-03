/**
 * @mainpage EVALUATOR:  Plataforma de gestión de problemas y cursos de programación.
 
En esta práctica se construye un programa modular que ofrece un menú de opciones para gestionar una plataforma de gestión de problemas y cursos de programación. Se introducen las clases <em>Problema</em>, <em>Cjt_problemas</em>, <em>Sesion</em>, <em>Cjt_sesiones</em>, <em>Curso</em>, <em>Cjt_cursos</em>, <em>Usuario</em> y <em>Cjt_usuarios</em>.

Se documentan elementos públicos y privados.
*/

/** @file program.cc
    @brief Programa principal para la práctica de PRO2 <em>program</em>.
*/


#include "Problema.hh"
#include "Cjt_problemas.hh"
#include "Sesion.hh"
#include "Cjt_sesiones.hh"
#include "Curso.hh"
#include "Cjt_cursos.hh"
#include "Usuario.hh"
#include "Cjt_usuarios.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;

/** @brief Programa principal para la práctica de PRO2 <em>program</em>.
*/
int main () {

    //lectura de la coleccion inicial de problemas;
    Cjt_problemas coleccion_prob;
    int P;
    cin >> P;
    for (int i = 0; i < P; ++i) {
        string id;
        cin >> id;
        Problema prob(id);
        coleccion_prob.anadir_problema(prob);
    }

    //lectura del repositorio inicial de sesiones;
    Cjt_sesiones repo_ses;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string id;
        cin >> id;
        Sesion ses(id);
        ses.leer();
        repo_ses.anadir_sesion(ses);
    }

    //lectura del conjunto inicial de cursos;
    Cjt_cursos conj_cursos;
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        Curso curs(i);
        curs.leer(repo_ses);
        conj_cursos.anadir_curso(curs);
    }

    //lectura de los usuarios iniciales;
    Cjt_usuarios conj_usuarios;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        string id;
        cin >> id;
        Usuario usu(id);
        conj_usuarios.anadir_usuario(usu);
    }

    //lee comando;
    string comando;
    cin >> comando;

    while (comando != "fin") {
        int c; 
        int r;
        string p; 
        string s; 
        string u;
        
        if (comando == "nuevo_problema" or comando == "np") {
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            if (coleccion_prob.existe_problema(p)) {
                cout << "error: el problema ya existe" << endl;
            }
            
            else {
                Problema prob(p);
                coleccion_prob.anadir_problema(prob);
                cout << coleccion_prob.numero_problemas() << endl;
            }
        }
    
        else if (comando == "nueva_sesion" or comando == "ns") {
            cin >> s;
            cout << "#" << comando << " " << s << endl;
            Sesion ses(s);
            ses.leer();
            if (repo_ses.existe_sesion(s)) {
               cout << "error: la sesion ya existe" << endl;
            }
            
            else {
                repo_ses.anadir_sesion(ses);
                cout << repo_ses.numero_sesiones() << endl;
            }
        }
    
        else if (comando == "nuevo_curso" or comando == "nc") {
            cout << "#" << comando << endl;
            int mida = conj_cursos.numero_cursos();
            Curso curs(mida + 1);
            bool valido;
            curs.leer_comprovar(repo_ses, valido);
            if (valido) {
                conj_cursos.anadir_curso(curs);
                cout << curs.identificador() << endl;
            }                

            else {
               cout << "error: curso mal formado" << endl;
            }
        }
    
        else if (comando == "alta_usuario" or comando == "a") {
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (conj_usuarios.existe_usuario(u)) {
               cout << "error: el usuario ya existe" << endl;
            }
            
            else {
                Usuario usu(u);
                conj_usuarios.anadir_usuario(usu);
                cout << conj_usuarios.numero_usuarios() << endl;
            }
        }
    
        else if (comando == "baja_usuario" or comando == "b") {
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (not conj_usuarios.existe_usuario(u)) {
               cout << "error: el usuario no existe" << endl;
            }
            
            else {
                conj_usuarios.eliminar_usuario(conj_cursos, u);
                cout << conj_usuarios.numero_usuarios() << endl;
            }
        }
    
        else if (comando == "inscribir_curso" or comando == "i") {
            cin >> u >> c;
            cout << "#" << comando << " " << u << " " << c << endl;
            if (not conj_usuarios.existe_usuario(u)) {
                cout << "error: el usuario no existe" << endl;
            }
            
            else if (not conj_cursos.existe_curso(c)) {
                cout << "error: el curso no existe" << endl;
            }
            
            else {
                Usuario usu;
                conj_usuarios.consultar_usuario(u, usu);
                if (usu.esta_inscrito()) {
                    cout << "error: usuario inscrito en otro curso" << endl;
                }
                else {
                    usu.inscribir(conj_cursos, c);
                    conj_usuarios.modificar_usuario(usu);
                }
            }
        }
    
        else if (comando == "curso_usuario" or comando == "cu") {
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (not conj_usuarios.existe_usuario(u)) {
                cout << "error: el usuario no existe" << endl;
            }
            
            else {
                Usuario usu;
                conj_usuarios.consultar_usuario(u, usu);
                cout << usu.consultar_curso() << endl;
            }
        }
    
        else if (comando == "sesion_problema" or comando == "sp") {
            cin >> c >> p;
            cout << "#" << comando << " " << c << " " << p << endl;
            if (not conj_cursos.existe_curso(c)) {
                cout << "error: el curso no existe" << endl;
            }
            
            else if (not coleccion_prob.existe_problema(p)) {
                cout << "error: el problema no existe" << endl;
            }
            
            else {
                string result;
                bool b = conj_cursos.sesion_problema_conj(c, p, result);
                if (b) cout << result << endl;
                else cout << "error: el problema no pertenece al curso" << endl;
            }
                
        }
    
        else if (comando == "problemas_resueltos" or comando == "pr") {
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (not conj_usuarios.existe_usuario(u)) {
                cout << "error: el usuario no existe" << endl;
            }
            
            else {
                Usuario usu;
                conj_usuarios.consultar_usuario(u, usu);
                usu.listar_problemas_resueltos();
            }
        }
    
        else if (comando == "problemas_enviables" or comando == "pe") {
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (not conj_usuarios.existe_usuario(u)) {
                cout << "error: el usuario no existe" << endl;
            }
    
            else {
                Usuario usu;
                conj_usuarios.consultar_usuario(u, usu);
                if (not usu.esta_inscrito()) {
                    cout << "error: usuario no inscrito en ningun curso" << endl;
                }
                else usu.listar_problemas_enviables();
            }
        }
    
        else if (comando == "envio" or comando == "e") {
            cin >> u >> p >> r;
            cout << "#" << comando << " " << u << " " << p << " " << r << endl;
            Problema prob;
            coleccion_prob.consultar_problema(p, prob);
            prob.actualizar_estadisticas(r);
            coleccion_prob.modificar_problema(prob);
            Usuario usu;
            conj_usuarios.consultar_usuario(u, usu);
            int id_curs = usu.consultar_curso();
            Curso curs;
            conj_cursos.consultar_curso(id_curs, curs);
            usu.actualizar_estadisticas(curs, p, r);
            conj_usuarios.modificar_usuario(usu);
            if (not usu.esta_inscrito()) {
                curs.decrementar_usuario();
                curs.incrementar_usuario_completado();
                conj_cursos.modificar_curso(curs);
            }
        }
    
        else if (comando == "listar_problemas" or comando == "lp") {
            cout << "#" << comando << endl;
            coleccion_prob.escribir();
        }
    
        else if (comando == "escribir_problema" or comando == "ep") {
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            if (not coleccion_prob.existe_problema(p)) {
                cout << "error: el problema no existe" << endl;
            }
            
            else {
                Problema prob;
                coleccion_prob.consultar_problema(p, prob);
                prob.escribir();
            }
        }
    
        else if (comando == "listar_sesiones" or comando == "ls") {
            cout << "#" << comando << endl;
            repo_ses.escribir();
        }
    
        else if (comando == "escribir_sesion" or comando == "es") {
            cin >> s;
            cout << "#" << comando << " " << s << endl;
            if (not repo_ses.existe_sesion(s)) {
                cout << "error: la sesion no existe" << endl;
            }
            
            else {
                Sesion ses;
                repo_ses.consultar_sesion(s, ses);
                ses.escribir();
            }
        }
    
        else if (comando == "listar_cursos" or comando == "lc") {
            cout << "#" << comando << endl;
            conj_cursos.escribir();
        }
    
        else if (comando == "escribir_curso" or comando == "ec") {
            cin >> c;
            cout << "#" << comando << " " << c << endl;
            if (not conj_cursos.existe_curso(c)) {
                cout << "error: el curso no existe" << endl;
            }
            
            else {
                Curso curs;
                conj_cursos.consultar_curso(c, curs);
                curs.escribir();
            }
        }
    
        else if (comando == "listar_usuarios" or comando == "lu") {
            cout << "#" << comando << endl;
            conj_usuarios.escribir();
        }
    
        else if (comando == "escribir_usuario" or comando == "eu") {
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (not conj_usuarios.existe_usuario(u)) {
                cout << "error: el usuario no existe" << endl;
            }
            
            else {
                Usuario usu;
                conj_usuarios.consultar_usuario(u, usu);
                usu.escribir();
            }
        }
    
        cin >> comando;
    }
}
    
