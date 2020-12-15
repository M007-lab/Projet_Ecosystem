#include "Bestiole.h"

#include <cstdlib>
#include <cmath>
#define PI 3.14159265359

const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;

   couleur = new T[ 3 ];
   couleur[ 0 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 1 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );
   couleur[ 2 ] = static_cast<int>( static_cast<double>( rand() )/RAND_MAX*230. );

}


Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );

}

Bestiole::Bestiole(int x,int y,int ageMax,int vitesse,int orientation)
{
    x = x; y = y; ageMax = ageMax; vitesse = vitesse; orientation = orientation;
}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}



void Bestiole::collide()
{
    double testMort = rand()/RAND_MAX; // Rand_double
    if(testMort<=this->getProbaMort())
    {
        //pour tuer la bestiole, on met son âge au maximum
        setAge(Config::getInstance()->ageMax);
    }
    else
    {
        //si la collision ne tue pas, on repart dans la direction opposée
        setOrientation(-getOrientation());
    }
}





void Bestiole::draw( UImg & support )
{

   double xt = x + cos( orientation )*AFF_SIZE/2.;
   double yt = y - sin( orientation )*AFF_SIZE/2.;

   support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180.,couleur);
   support.draw_circle(xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}




int Bestiole::getIdentite() const {
  return identite;
}

int Bestiole::getX() const {
  return x;
}

int Bestiole::getY() const {
  return y;
}

double Bestiole::getOrientation() const {
  return orientation;
}

int Bestiole::getAgeMax() const {
  return Config::getInstance()->ageMax;
}
int Bestiole::getAge() const {
  return age;
}

unsigned char* Bestiole::getColor() const {
    return (unsigned char*) this->couleur;
}

unsigned char* Bestiole::getLightColor() const { // Renvoie une couleur entre le blanc/gris et al couleur de la bestiole
    unsigned char * col = (unsigned char*) this->couleur;
    col[0] = 3*col[0]/5 + 60;
    col[1] = 3*col[1]/5 + 60;
    col[2] = 3*col[2]/5 + 60;
    return col;
}

double Bestiole::getVitesse() const {
  return vitesse;
}

//setters
void Bestiole::setX(int newX) {
    x = newX;
}
void Bestiole::setY(int newY) {
    y = newY;
}
void Bestiole::setVitesse(double newVitesse) {
    vitesse = newVitesse;
}
void Bestiole::setOrientation(double newOrientation) {
    orientation = newOrientation;
}
void Bestiole::setAge(int newAge) {
    age = newAge;
}


double Bestiole::getDistanceA(const Bestiole& b) const {
    double x_diff = this->getX() - b.getX();
    double y_diff = this->getY() - b.getY();
    return std::sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

bool Bestiole::dansDistanceDetection(const Bestiole & b, double distance) const {
    double dist = this->getDistanceA(b);
    return ( dist <= distance );
}

double Bestiole::between0and2PI(double angle) const{
    while (angle > 2.0*PI)
        angle -= 2.0*PI;
    while (angle < 0)
        angle += 2.0*PI;
    return angle;
}

bool Bestiole::dansChampsAngulaire(const Bestiole & b, double champ) const {
    double precision = 0.0001; //A voir
    double angle = between0and2PI(atan2(b.getY()-this->getY(),b.getX()-this->getX()));
    double angleFin = between0and2PI(this->getOrientation() + champ/2);
    double angleStart = between0and2PI(this->getOrientation() - champ/2);

    // A voir
    if(std::abs(angleStart - angleFin) < precision)
        return false;

    if((angleFin >= angle) && (angle>=angleStart))
        return true;
    if((angleFin <= angle) && (angle <= angleStart)) {
        return true;
    }
    return false;
}