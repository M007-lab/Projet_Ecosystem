#include "Milieu.h"
#include "Configuration.h"
#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{  
   
   
   // create initiale population
   // init_population();


   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}

void Milieu::init_population()
{
   
    listeComportements  = {new Gregaire,new Kamikaze } ;//, new Peureuse};//,new Prevoyante,new Multiple};
    // Chargmeent des pourcentages par Comportment
    std::vector<double> listeWeights = {Config::getInstance()->pctGregaire,Config::getInstance()->pctKamikaze};//,Config::getInstance()->pctPeureuse,Config::getInstance()->pctPrevoyante,Config::getInstance()->pctMulti};
    // On stocke les couleurs dans une liste
    // std::vector<Color> couleurs = {blue,red,yellow,green,purple};
    for(unsigned int i=0;i<listeComportements.size();++i)
    {
        // mapComportementCouleur[listeComportements[i]] = couleurs[i];
        mapComportementPct[listeComportements[i]] = listeWeights[i];
    }

    // initialisation de la population :
    int n = Config::getInstance()->nMax;
    // On utilise utils_init pour créer une liste de n comportements qui respecte les poids
    std::vector<Comportement*> _population = utils_init(listeComportements,listeWeights,n);
    for (auto element : _population)
    {
        //Color _color = mapComportementCouleur[element];
        addBestiole(creator.createBestiole(element));//,_color.color));
    }

}

void Milieu::step( void )
{   
   // check external events; key inputs
   checkInput();
   // kill expired bestioles
   killBestiole();
   // check spontaneous creation of bestioles
   newBestiole();

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for

}

void Milieu::addBestiole(const Bestiole & b )
{ 
   listeBestioles.push_back(b);
   listeBestioles.back().initCoords(width, height); 
}

void Milieu::newBestiole( ){

}

int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      //if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}

void Milieu::killBestiole()
{

}
void Milieu::checkInput()
{

}

int Milieu::getWidth( void ) const 
{ return width; };
int Milieu::getHeight( void ) const 
{ return height; };
std::vector<Bestiole> Milieu::getListeBestioles() const 
{return listeBestioles; }