/** @file Sesion.cc
    @brief Código de la clase Sesion
*/


#include "Sesion.hh"


Sesion::Sesion() {
    bt_ses = BinTree<string>();
}

Sesion::Sesion(const string& id) {
    nom = id;
    bt_ses = BinTree<string>();
}

string Sesion::nombre() const {
    return nom;
}

void Sesion::problema_inicial(Problema& prob) const {
    Problema p(bt_ses.value());
    prob = p;
}

int Sesion::numero_problemas() const {
    return mida(bt_ses);
}

bool Sesion::problemas_contenidos(map<string, string>& m) const {
    return consultar_problemas_sesion(bt_ses, nom, m);
}

void Sesion::consultar_problemas_siguientes(const string& id, pair<Problema, Problema>& p) const {
    BinTree<string> arb;
    consultar_arbol(bt_ses, id, arb);
    problema_siguiente(arb.left(), p.first);
    problema_siguiente(arb.right(), p.second);
}

void Sesion::leer() {
    bt_ses = leer_preorden();
}

void Sesion::escribir() const {
    cout << nom << " " << mida(bt_ses) << " ";
    escribir_postorden(bt_ses);
    cout << endl;
}
    
int Sesion::mida(const BinTree<string>& a) {
    int x;
    if (a.empty()) x = 0;
    else x = mida(a.left()) + mida(a.right()) + 1;
    return x;
}

bool Sesion::consultar_problemas_sesion(const BinTree<string>& a, const string& id, map<string, string>& m) {
    if (not a.empty()) {
        pair<map<string, string>::iterator, bool> p;
        p = m.insert(make_pair(a.value(), id));
        if (not p.second) return false;
        bool b = consultar_problemas_sesion(a.left(), id, m);
        if (not b) return false;
        else return consultar_problemas_sesion(a.right(), id, m);
    }
    return true;
}

void Sesion::consultar_arbol(const BinTree<string>& a, const string& id, BinTree<string>& arb) {
    if (not a.empty()) {
        if (a.value() == id) arb = a;
        else {
            consultar_arbol(a.left(), id, arb);
            consultar_arbol(a.right(), id, arb);
        }
    }
}

BinTree<string> Sesion::leer_preorden() {
    string name;
    cin >> name;
    if (name == "0") return BinTree<string>();
    else {
        BinTree<string> a1 = leer_preorden();
        BinTree<string> a2 = leer_preorden();
        return BinTree<string> (name, a1, a2);
    }
}

void Sesion::problema_siguiente(const BinTree<string>& a, Problema& prob) {
    if (not a.empty()) {
        Problema p(a.value());
        prob = p;
    }
    else {
        Problema prob_vacio("vacio");
        prob = prob_vacio;
    }
}
    

void Sesion::escribir_postorden(const BinTree<string>& a) {
    if (not a.empty()) {
        cout << "(";
        escribir_postorden(a.left());
        escribir_postorden(a.right());
        cout << a.value() << ")";
    }
}
