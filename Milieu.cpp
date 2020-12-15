#include "Milieu.h"
#include "Configuration.h"
#include <cstdlib>
#include <ctime>


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{  
   
   graphicSupport = UImg( width, height, 1, 3 );
   // create initiale population
   init_population();


   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;
   for (auto it = idToBestioles.begin(); it != idToBestioles.end();)
    {
        //it->second->toString(); std::cout <<  " va être supprimée " << std::endl;
        delete it->second;
        idToBestioles.erase(it++);
    }

    for(auto e : listeComportements)
       delete e;
    listeComportements.clear();
    mapComportementWeight.clear();
    mapComportementColor.clear();
    std::cout << "Liste des comportements a été supprimée " << std::endl;

}

void Milieu::init_population()
{
   
    listeComportements  = {new Gregaire,new Kamikaze } ;//, new Peureuse};//,new Prevoyante,new Multiple};
    // Loading Comportement percentage
    std::vector<double> weights = {Config::getInstance()->pctGregaire,Config::getInstance()->pctKamikaze};//,Config::getInstance()->pctPeureuse,Config::getInstance()->pctPrevoyante,Config::getInstance()->pctMulti};
    // list of pre-defined colors
    std::vector<Color> colors = {blue,red,yellow,green,purple};
    for(unsigned int i=0;i<listeComportements.size();++i)
    {
        // mapComportementColor[listeComportements[i]] = couleurs[i];
        mapComportementWeight[listeComportements[i]] = weights[i];
    }

    // initialisation de la population :
    int n = Config::getInstance()->nMax;
    // On utilise utils_init pour créer une liste de n comportements qui respecte les poids
    std::vector<Comportement*> population = init_n_elements(listeComportements,weights,n);
    for (auto element : population)
    {
        Color c = mapComportementColor[element];
        addBestiole(creator.createBestiole(element,c.color));
    }

}

void Milieu::step( void )
{   
   // check spontaneous creation of bestioles
   newBestiole();
   // kill expired bestioles and get new updated list
   list<Bestiole*> listeBestioles = getBestiolesList();
   

   //cimg_forXY( *this, width, height ) fillC( width, height, 0, white[0], white[1], white[2] );
   for(auto b : listeBestioles)
   {

      Bestiole* bClone = b->action( getBestiolesList() );
      if(bClone != nullptr)
      {
         addBestiole(bClone);
         bClone->bouge(width,height);

      }
      b->draw(graphicSupport);

   } // for

}

void Milieu::addBestiole(Bestiole * b )
{ 
   if(idToBestioles.find(b->getIdentite()) == idToBestioles.end()){
            idToBestioles[b->getIdentite()] = b;
            b->toString();
   }     
   b->initCoords(width, height); 
}

void Milieu::newBestiole( ){
   Rand_double rd(0,1);
   if(rd() <= Config::Config::getInstance()->probaNouveau)
   {
       std::vector<double> weights;
       std::vector<Comportement*> comportements;
       for(auto element : mapComportementWeight)
       {
           weights.push_back(element.second);
           comportements.push_back(element.first);
       }
       Comportement* c = random_element(comportements,weights);
       Color _color = mapComportementColor[c];
       addBestiole(creator.createBestiole(c,_color.color));
   }
}

// int Milieu::nbVoisins( const Bestiole & b )
// {

//    int         nb = 0;


//    for ( std::vector<Bestiole>::iterator it = idToBestioles.begin() ; it != idToBestioles.end() ; ++it )
//       //if ( !(b == *it) && b.jeTeVois(*it) )
//          ++nb;

//    return nb;

// }
void Milieu::killBestiole(int id)
{
   if (idToBestioles.find(id) != idToBestioles.end())
    {
        delete idToBestioles.find(id)->second;
        idToBestioles.erase(idToBestioles.find(id));
        std::cout << "La bestiole : " << id << " a été tuée " << std::endl;
    }
}

// Used when mouse click to kill bestiole
void Milieu::killBestiole(int x, int y)
{
   for(auto b: getBestiolesList()){
        double distance = std::sqrt( (x-b->getX())*(x-b->getX()) + (y-b->getY())*(y-b->getY()));
        if(distance<Config::getInstance()->rayon){
            this->killBestiole(b->getIdentite());
            break;
        }
    }
}

std::list<Bestiole*> Milieu::getBestiolesList()
{
    std::list<Bestiole*> listeBestioles;
    // Mise à jour de la MAP et _listeBestioles
    for (auto it = idToBestioles.begin(); it != idToBestioles.end();)
    {
        if(it->second->getAge() >= it->second->getAgeMax())
        {
            delete it->second;
            idToBestioles.erase(it++);
        }
        else
        {
            listeBestioles.push_back(it->second);
            (++it);
        }
    }
    return listeBestioles;

}

int Milieu::getWidth( void ) const 
{ return width; }
int Milieu::getHeight( void ) const 
{ return height; }
CImg<T>&  Milieu::getGraphicSupport()
{
    return graphicSupport;
}