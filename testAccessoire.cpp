
#include <memory>
#include "Aquarium.h"
#include "Milieu.h"
#include "Configuration.h"
#include "FactoryBestiole.h"
#include "Nageoire.h"
#include "Carapace.h"
#include <iostream>

std::list<Bestiole*> make_test(int test, std::list<Bestiole*> bestioles,std::unique_ptr<FactoryBestiole>& creator ){
    
    unsigned char col[3] = {255, 0, 255};
    ConcreteBestiole* newBestiole = creator->createBestiole(new Gregaire, col);
    switch(test) {  
    case 0 : // Test le changement de vitesse de Nageoire
    {
      bestioles.front()->setVitesse(5);
      newBestiole->setVitesse(5);
      std::cout << newBestiole->getVitesse();
      newBestiole = new Nageoire(newBestiole, 10);
      bestioles.back() = newBestiole;
      std::cout << newBestiole->getVitesse();
      break;
    }
    case 1 : // Test le changement de vitesse de Carapace
    {
      bestioles.front()->setVitesse(7);
      newBestiole->setVitesse(7);
      newBestiole = new Carapace(newBestiole, 0, 10);
      bestioles.back() = newBestiole;
      
      break;
    }
    case 2 : // Test le changement de robustesse de Carapace
    {
      bestioles.front()->setVitesse(5);
      newBestiole->setVitesse(5);
      newBestiole = new Carapace(newBestiole, 1000000, 10);
      bestioles.back() = newBestiole;
      bestioles.back()->collide(*newBestiole); // La probabilité de mort étant 1, la survie de cette bestiole prouve le fonctionnement
      break;
    }
    case 3: // Test le camouflage
    {
      ConcreteBestiole* autreBestiole = creator->createBestiole(new Gregaire, col);
      autreBestiole = new Camouflage(autreBestiole, 1);
      bestioles.front() = autreBestiole;
      bestioles.front()->setX(10);
      bestioles.front()->setY(10);
      newBestiole->setX(30);
      newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
      newBestiole->setOrientation(0);
      newBestiole = new Oreille(newBestiole, 1, 25);
      bestioles.back() = newBestiole;
      // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
      if (newBestiole->jeTeVois(*bestioles.front())) {
        bestioles.front()->setX(42);
      }
      break;
    }
    }
    return bestioles;

}

bool check_test(int test, std::list<Bestiole*> listeBestioles)
{

    switch(test)
    {
        case 0: {
        double v0 = listeBestioles.front()->getVitesse();
        double v1 = listeBestioles.back()->getVitesse();
        return (v1/v0 == 10);
        }
        case 1: {
        double v0 = listeBestioles.front()->getVitesse();
        double v1 = listeBestioles.back()->getVitesse();
        return (v1/v0 == 0.10);
        }
        case 2: {
        return (listeBestioles.back()->getAge() != Config::getInstance()->ageMax);
        }
        case 3: {
        return (!(listeBestioles.front()->getX()==42));
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
  Config::filename = argv[1];
  Milieu* flotte = new Milieu(Config::getInstance()->width, Config::getInstance()->height);
  std::list<Bestiole*> bestioles;
  std::unique_ptr<FactoryBestiole> creator (new FactoryBestiole());
  int nbTestsReussis = 0;
  int nbTestsTotal = 4; 

  for (int i = 0; i < nbTestsTotal; i++) {
    cout << "Test n° " << i << " : ";
    bestioles = flotte->getBestiolesList();
    bestioles = make_test(i, bestioles, creator);
    if (check_test(i, bestioles)) {
      nbTestsReussis ++;
      cout << "OK" << endl;
    }
    else {
      cout << "Error" << endl;
      cout << "Erreur sur le test numéro " << i << endl;
    }
  }
  cout  << nbTestsReussis << " successful tests over " << nbTestsTotal << " tests in total ." << endl;
  delete flotte;
}