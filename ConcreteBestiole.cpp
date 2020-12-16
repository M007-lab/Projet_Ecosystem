#include "ConcreteBestiole.h"
#define PI 3.14159265359

ConcreteBestiole::ConcreteBestiole(int _x,int _y, int _ageMax, double _vitesse, double _orientation) : Bestiole(_x,_y,_ageMax,_vitesse,_orientation)
{
    
}

ConcreteBestiole::ConcreteBestiole(const ConcreteBestiole& b) : Bestiole(b)
{
    
}

ConcreteBestiole::~ConcreteBestiole(){
    
}
 //une bestiole simple n'a pas moyen de voir une autre bestiole, donc on renvoit false
// bool ConcreteBestiole::jeTeVois(const Bestiole& b) const {
//     return false;
// }


double ConcreteBestiole::getCamouflage() const {
  return 0.0;
}

double ConcreteBestiole::getProbaMort() const {
  return Config::getInstance()->probaMortCol;
}
ConcreteBestiole* ConcreteBestiole::action(std::list<Bestiole*> allBestioles)
{
   
   bouge(Config::getInstance()->width, Config::getInstance()->height);
   

    std::list<Bestiole*> bestioles = getVoisins(allBestioles);
    for(auto b: bestioles)
    {
        if(b->getIdentite()!=this->getIdentite() && this->getDistanceA(*b)<2*Config::getInstance()->rayon)
        {
            this->collide(*b);
            
            b->collide(*this);
        }
    }
    
    return checkClone();

}

ConcreteBestiole* ConcreteBestiole::checkClone()
{
    
    if(this->getAge()<this->getAgeMax()){

      Rand_double testClonage = Rand_double(0,1);
      if(testClonage()<=Config::getInstance()->probaClonage)
      {
         
          return this->clone();
      }
      else
      {
          
          return nullptr;
      }
    }
    return 0;
}

bool ConcreteBestiole::jeTeVois( const Bestiole & b ) const
{
    return false;
}
// Bestiole* ConcreteBestiole::clone()
// {
//     Bestiole* ptr = new ConcreteBestiole(*this);
//     double newOrientation= Rand_double(0,2*PI)();
//     double distance = Rand_double(Config::getInstance()->distClonageMin,Config::getInstance()->distClonageMax)();
//     ptr->setX(ptr->getX() + std::round (cos(newOrientation)*distance));
//     ptr->setY(ptr->getY() - std::round (sin(newOrientation)*distance));
//     return ptr;
// }

void ConcreteBestiole::collide(Bestiole& autre)
{   
    //get killed with a probability 
    double testMort = Rand_double(0,1)();
    if(testMort<=this->getProbaMort())
    {
        // to kill it we force its age to max age
        this->setAge(Config::getInstance()->ageMax);
    }
    else
    {
        //if not killed, go in the opposite direction
        this->setOrientation(PI - getOrientation());
    }
}

void ConcreteBestiole::draw(UImg& support){
    double xt = (double) this->getX() - cos(this->getOrientation())*Config::getInstance()->rayon/2;
    double yt = (double) this->getY() + sin(this->getOrientation())*Config::getInstance()->rayon/2;
    support.draw_ellipse(xt, yt, Config::getInstance()->rayon*2, Config::getInstance()->rayon/2.5,-this->getOrientation()/M_PI*180.,this->getColor());
    support.draw_circle(this->getX(),this->getY(),Config::getInstance()->rayon,getColor());
}

std::list<Bestiole*> ConcreteBestiole::getVoisins(std::list<Bestiole*> allBestioles)
{   
    std::list<Bestiole*> voisins;
    for (auto b : allBestioles)
    {
           if (this->jeTeVois(*b) && !(*this == *b)) // == is overloaded based on Identite
           {
              voisins.push_back(b);
           }

    }
   return voisins;
}


void ConcreteBestiole::toString() const
{
    std::cout<< "ID : " << this->getIdentite() <<  ", AGE : " << this->getAge()  << ", X : " << this->getX() << ", Y : " << this->getY() << ", V : " << this->getVitesse() 
    << ", O : " << this->getOrientation() << ", BHV : " << getComportement()->getName() << " CAM : " 
    << getCamouflage() << ", PMR: "  << getProbaMort() << std::endl;
}

void ConcreteBestiole::toString(std::ofstream&  stream) const
{
    stream << "ID : " << this->getIdentite() <<  ", AGE : " << this->getAge()  << ", X = " << this->getX() << ", Y : " << this->getY() << ", V : " << this->getVitesse() 
    << ", O : " << this->getOrientation() << ", BHV : " << getComportement()->getName()  << " CAM : " 
    << getCamouflage() << ", PMR: "  << getProbaMort() << std::endl;
}


//setters
void ConcreteBestiole::setX(int newX) {
    this->x = newX;
}
void ConcreteBestiole::setY(int newY) {
    this->y = newY;
}
void ConcreteBestiole::setVitesse(double newVitesse) {
    this->vitesse = newVitesse;
}
void ConcreteBestiole::setOrientation(double newOrientation) {
    this->orientation = newOrientation;
}
void ConcreteBestiole::setAge(int newAge) {
    this->age = newAge;
}


double ConcreteBestiole::getVitesse() const
{
    return vitesse;
}