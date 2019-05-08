#include "Particule.h"
#include "ConstantesPhysiques.h"

using  namespace ConstantesPhysiques;
using namespace std;

//DEFINITION DES METHODES DE LA CLASSE PARTICULE ET SURCHARGE DE SES OPERATEURS

//METHODE PRIVEE DE LA CLASSE PARTICULE
double Particule::transformMassGeVToKg(){
    return (const_e*1e+9*scal_m)/(const_c*const_c);}

double Particule::calculateDeviationAngle(double _dt){
    return asin((_dt*vec_f.norme())/(2*FacteurGamma()*transformMassGeVToKg()*vec_v.norme()));}

//METHODES PUBLIQUES DE LA CLASSE PARTICULE
Particule::Particule(Vecteur3D _r, Vecteur3D _p, double _m, double _q, SupportADessin* _support,Element* _courant)
:Dessinable(_support), vec_r(_r), scal_m(_m), scal_q(_q), elem_courant(_courant) {
    vec_v=_p*(const_c/sqrt((_m*_m)+_p.norme2()));
    vec_f=*new Vecteur3D();}

Particule::Particule(Vecteur3D _r, Vecteur3D _vitessedirective, double _energie, double _m, double _q, SupportADessin* _support,Element* _courant )
:Dessinable(_support), vec_r(_r), scal_m(_m), scal_q(_q), elem_courant(_courant) {
    vec_v=(~_vitessedirective)*(const_c*sqrt(1-(scal_m*scal_m)/(_energie*_energie)));
    vec_f=*new Vecteur3D();}

double Particule::Energie() const
{return FacteurGamma()*scal_m;}

double Particule::FacteurGamma() const
{return 1/sqrt(1-(vec_v.norme2()/(const_c*const_c)));}

void Particule::ajouteForceMagnetique(Vecteur3D _B, double _dt){
    if(_B==(*new Vecteur3D)){
        vec_f=(*new Vecteur3D);}
    else{
        vec_f=(scal_q*vec_v)^_B;
        cout<<"     avant rotation corrective :"<<vec_f<<endl;
        vec_f.rotation((vec_v^vec_f), calculateDeviationAngle(_dt));
        cout<<"     Angle de correction : "<<calculateDeviationAngle(_dt)<<endl;
        cout<<"     après rotation corrective :"<<vec_f<<endl;}} 
    
void Particule::bouger(double _dt){
    vec_v+=_dt*(1/(FacteurGamma()*transformMassGeVToKg()))*vec_f;
    vec_r+=vec_v*(_dt);
    vec_f=*new Vecteur3D();}

ostream& Particule::affiche(ostream& sortie) const{
    return sortie<<"Une particule :"<<endl<<
    "   position :"<<vec_r<<endl<<
    "   vitesse :"<<vec_v<<endl<<
    "   gamma :"<<FacteurGamma()<<endl<<
    "   enregie (GeV) :"<<Energie()<<endl<<
    "   masse (Gev)/c^2 :"<<scal_m<<endl<<
    "   charge :"<<scal_q<<endl<<
    "   force :"<<vec_f<<endl;}

void Particule::change_element(Element* suivant){
    elem_courant=suivant;}

//OPERATEUR INTERNE DE LA CLASSE PARTICULE   
Particule& Particule::operator*=(double coef) {
	scal_m*=coef;
	scal_q*=coef;
	return *this;}

//OPERATEURS EXTERNES A LA CLASSE PARTICULE UTILISANT LES METHODES DE LA CLASSE
ostream& operator<<(ostream& sortie, Particule const& P){
   return P.affiche(sortie);}
   
//const Particule Particule::operator*(double coef, Particule const& p) {
//	return (p*=coef);}
	
//const Particule::operator*(Particule const& p, double coef) {
//	return (p*=coef); }

