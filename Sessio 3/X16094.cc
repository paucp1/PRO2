/*
Volem modificar la classe Estudiant eliminant l’atribut privat amb_nota que enregistra si l’estudiant té nota i modificant totes les funcions de la classe afectades per l’eliminació de l’atribut. Feu servir un valor especial de nota, per exemple -1, per a quan l’estudiant no tingui nota.

En segon lloc, volem implementar noves operacions: els operadors == i !=, i una altra que serveixi per exemple com a auxiliar d’un sort de vectors d’estudiants.

   
  bool operator==(const Estudiant& est) const;
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. i est tenen el mateix DNI */

  bool operator!=(const Estudiant& est) const;
  /* Pre: cert */
  /* Post: el resultat indica si el p.i. i est tenen DNIs diferents */

  static bool comp(const Estudiant& e1, const Estudiant& e2);
  /* Pre: cert  */
  /* Post: el resultat indica si e1 te DNI mes petit que e2 */
No feu servir consultores de la classe, treballeu directament amb els camps.

Observació Tingueu en compte que als fitxers públics (icona del gatet) hi ha un fitxer Estudiant.hh amb les novetats incorporades.

Noteu que només heu d’enviar el fitxer Estudiant.cc, i que el Jutge en prova totes les operacions. Per tant, abans d’enviar la solució al Jutge, assegureu-vos que funcionen correctament.
  */

  #include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  nota = -1;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  nota = -1;
}

//Estudiant::~Estudiant(){}

void Estudiant::afegir_nota(double nota)
{
  if (this->nota != -1) 
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota; 
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (this->nota == -1) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
    if (this->nota == -1) return false;
    else return true;
}

double Estudiant::consultar_nota() const
{
  if (this->nota == -1) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

bool Estudiant::comp(const Estudiant& e1, const Estudiant& e2)
{
    return e1.dni < e2.dni;
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x; 
  }
  else this->nota = -1;
}

void Estudiant::escriure() const
{
  if (this->nota != -1)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
