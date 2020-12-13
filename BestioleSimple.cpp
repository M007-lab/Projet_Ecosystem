#include "ConcreteBestiole.h"
#define PI 3.14159265359


ConcreteBestiole::ConcreteBestiole(const ConcreteBestiole& b) : Bestiole(b)
{
    
}

ConcreteBestiole::~ConcreteBestiole(){
   
}
 //une bestiole simple n'a pas moyen de voir une autre bestiole, donc on renvoit false
// bool ConcreteBestiole::jeTeVois(const Bestiole& b) const {
//     return false;
// }

Comportement* ConcreteBestiole::getComportement() const{
    return this->comportement;
}

// Bestiole* Bestiole::action( std::list<Bestiole*> allBestioles )
// {
    
// }
// Bestiole* ConcreteBestiole::clone()
// {
//     Bestiole* ptr = new ConcreteBestiole(*this);
//     double newOrientation= Rand_double(0,2*PI)();
//     double distance = Rand_double(Config::getInstance()->distClonageMin,Config::getInstance()->distClonageMax)();
//     ptr->setX(ptr->getX() + std::round (cos(newOrientation)*distance));
//     ptr->setY(ptr->getY() - std::round (sin(newOrientation)*distance));
//     return ptr;
// }

// void ConcreteBestiole::draw(UImg& support){
//     double xt = (double) this->getX() - cos(this->getOrientation())*Config::getInstance()->rayon/2;
//     double yt = (double) this->getY() + sin(this->getOrientation())*Config::getInstance()->rayon/2;
//     support.draw_ellipse(xt, yt, Config::getInstance()->rayon*2, Config::getInstance()->rayon/2.5,-this->getOrientation()/M_PI*180.,this->getColor());
//     support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon,getColor());
// }
bool ConcreteBestiole::jeTeVois( const Bestiole & b ) const
{
    return false;
}


double ConcreteBestiole::getCamouflage() const {
    return 0.0;
}


double Bestiole::getProbaMort() const {
   return Config::getInstance()->probaMortCol;
}

//une fois arrivé à ConcreteBestiole, on a parcouru tous les décorateurs, on ne rajoute donc rien à la liste
// void ConcreteBestiole::getDecorateurs(std::list<std::string> &decorateurs){
//     return;
// }