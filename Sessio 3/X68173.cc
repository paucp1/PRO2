/*
Heu de modificar la classe Cjt_estudiants afegint l’atribut privat imax que enregistra la posició de l’estudiant amb la nota màxima i modificant totes les funcions de la classe afectades pel nou atribut. Feu servir un valor especial d’imax, per exemple -1, per a quan cap estudiant tingui nota.

Posteriorment heu d’afegir dues noves operacions:

void Cjt_estudiants::esborrar_estudiant(int dni)
/* Pre: existeix un estudiant al parametre implıcit amb DNI = dni */
/* Post: el parametre implıcit conte els mateixos estudiants que 
l’original menys l’estudiant amb DNI = dni */
Estudiant Cjt_estudiants::estudiant_nota_max( ) const
/* Pre: el parametre implıcit conte almenys un estudiant amb nota */
/* Post: el resultat es l’estudiant del parametre implıcit amb 
nota maxima; si en te mes d’un, es el de DNI mes petit */
Observació Tingueu en compte que en els fitxers públics (icona del gatet) hi ha un fitxer Cjt_Estudiants.hh amb l’especificació de l’operació auxiliar privada recalcular_posicio_imax que heu de respectar. Assegureu-vos de fer servir recalcular_posicio_imax només quan sigui imprescindible, per guanyar eficiència.

Noteu que només heu d’enviar el fitxer Cjt_estudiants.cc, amb la implementació de la classe Cjt_estudiants. El Jutge comprova totes les accions i funcions de la classe, per tant, abans d’enviar la solució al Jutge, assegureu-vos que funcionen correctament.
  */

  #include "Cjt_estudiants.hh"
#include <algorithm>

Cjt_estudiants::Cjt_estudiants() {
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
  imax = -1;
}
  
Cjt_estudiants::~Cjt_estudiants() {}
 
void Cjt_estudiants::afegir_estudiant(const Estudiant& est) {
  if (nest >= MAX_NEST) throw PRO2Excepcio("Conjunt ple");
  int i = nest-1;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i >= 0 && b == 0) {  
    if ( dni> vest[i].consultar_DNI()) b = true;
    else {
      vest[i+1]=vest[i];
      --i;
    }
  }
  // i es la posicio mes avancada amb el DNI mes petit que dni, si n'hi ha;
  vest[i+1] = est;
  ++nest;
  if (imax != -1 && imax >= i + 1) ++imax;
  if(est.te_nota() && imax != -1){
    if(est.consultar_nota() > vest[imax].consultar_nota()){
      imax = i + 1;
    }
    else if(est.consultar_nota() == vest[imax].consultar_nota()){
      if(est.consultar_DNI() < vest[imax].consultar_DNI()) imax = i + 1;
    }
    else if (est.consultar_nota() < vest[imax].consultar_nota()){
      if(est.consultar_DNI() < vest[imax].consultar_DNI()){ 
      }
    }
  }
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant>& vest, int left, int right, int x) {
/* Pre: vest esta ordenat */
  int i;
  bool found = false;
  while (left <= right && found == 0) { 
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1; 
    else found = true;
  }
  // i es la posicio, si l'element existeix
  if (found) return i; 
  else return -1;  
}  

void Cjt_estudiants::modificar_estudiant(const Estudiant& est) {
  /* Pre: existeix un estudiant al parametre implicit amb el dni d'est  */
  int x = est.consultar_DNI();
  int i = cerca_dicot(vest,0,nest-1,x);
  vest[i] = est;
  if(i == imax || imax == -1) recalcular_posicio_imax();
  else if (est.te_nota() && imax != -1){
    if(est.consultar_nota() > vest[imax].consultar_nota()){
    imax = i;
    }
    else if (est.consultar_nota() == vest[imax].consultar_nota()){
      if(est.consultar_DNI() < vest[imax].consultar_DNI()) imax = i;
    }
  }
}    
  		
void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est) {
  if (i < 1 || i > nest) throw PRO2Excepcio("Index no valid per a modificar_iessim");
  vest[i-1] = est;
  if(i-1 == imax || imax == -1) recalcular_posicio_imax();
  else if (est.te_nota() && imax != -1){
    if(est.consultar_nota() > vest[imax].consultar_nota()){
      imax = i - 1;
    }
    else if (est.consultar_nota() == vest[imax].consultar_nota()){
      if(est.consultar_DNI() < vest[imax].consultar_DNI()) imax = i-1;
    }
  }
}

int Cjt_estudiants::mida() const {
  return nest;
}
  
int Cjt_estudiants::mida_maxima() {
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const {
  int i= cerca_dicot(vest,0,nest-1,dni);
  return (i != -1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const {
  int i=cerca_dicot(vest,0,nest-1,dni);
  return vest[i];
}
 
Estudiant Cjt_estudiants::consultar_iessim(int i) const {
 if (i < 1 || i > nest) throw PRO2Excepcio("Index no valid per a consultar_iessim");
  return vest[i-1];
}

bool comp(const Estudiant& e1, const Estudiant& e2){
  return (e1.consultar_DNI() < e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants() {
  sort(vest.begin(),vest.begin()+nest,comp);
}

void Cjt_estudiants::llegir() {
  cin >> nest;
  if (nest > MAX_NEST) throw PRO2Excepcio("El conjunt no pot ser mes gran que la mida maxima");
  for (int i = 0; i < nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
  recalcular_posicio_imax();
}


void Cjt_estudiants::escriure() const {
  for (int i = 0; i < nest; ++i)
    vest[i].escriure();
}

void Cjt_estudiants::esborrar_estudiant(int dni){
    int i = cerca_dicot(vest,0,nest-1,dni);
    for (int j = i; j < nest-1; ++j){
        vest[j] = vest[j+1];
    }
    --nest;
    if(i == imax) recalcular_posicio_imax();
    else if (imax > i) --imax;
}

Estudiant Cjt_estudiants::estudiant_nota_max() const{
    return vest[imax];
}

void Cjt_estudiants::recalcular_posicio_imax(){
    double nota_max = -1;
    for(int i = nest -1; i >= 0; --i){
        if(vest[i].te_nota()){
            if(nota_max <= vest[i].consultar_nota()){
                nota_max = vest[i].consultar_nota();
                imax = i;
            }
        }
    }
}
