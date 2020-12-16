
#include <memory>
#include "Aquarium.h"
#include "Milieu.h"
#include "Configuration.h"
#include "FactoryBestiole.h"
#include "Oreille.h"
#include "Yeux.h"
#include <iostream>

std::list<Bestiole*> make_test(int test, std::list<Bestiole*> bestioles,std::unique_ptr<FactoryBestiole>& creator ){
    
    unsigned char col[3] = {255, 0, 255};
    ConcreteBestiole* newBestiole = creator->createBestiole(new Gregaire, col);
    switch(test) {  
        case 1: // Test la vision par l'oreille : trop loin
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole = new Oreille(newBestiole, 1, 15);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        if (newBestiole->jeTeVois(*bestioles.front())) {
            bestioles.front()->setX(42);
        }
        break;
        }
        case 2: // Test la vision par l'oreille : assez proche
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole = new Oreille(newBestiole, 1, 25);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        if (newBestiole->jeTeVois(*bestioles.front())) {
            bestioles.front()->setX(42);
        }
        break;
        }
        case 3: // Test la vision par l'Yeux : trop loin et mauvais angle
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole->setOrientation(0);
        newBestiole = new Yeux(newBestiole, 1, 15, 0);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        if (newBestiole->jeTeVois(*bestioles.front())) {
            bestioles.front()->setX(42);
        }
        break;
        }
        case 4: // Test la vision par l'oeuil : assez proche mais mauvais angle
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole->setOrientation(0);
        newBestiole = new Yeux(newBestiole, 1, 25, 0);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        if (newBestiole->jeTeVois(*bestioles.front())) {
            bestioles.front()->setX(42);
        }
        break;
        }
        case 5: // Test la vision par l'oeuil : trop loin mais bon angle
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole->setOrientation(0);
        newBestiole = new Yeux(newBestiole, 1, 15, 6);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        bool temp = newBestiole->jeTeVois(*bestioles.front());
        if (temp) {
            bestioles.front()->setX(42);
            cout << temp;
        }
        break;
        }
        case 6: // Test la vision par l'oeuil : assez proche et bon angle
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole->setOrientation(0);
        newBestiole = new Yeux(newBestiole, 1, 25, 6);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        if (newBestiole->jeTeVois(*bestioles.front())) {
            bestioles.front()->setX(42);
        }
        break;
        }
        case 7: // Test la vision par l'oreille mais pas par l'oeuil
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole->setOrientation(0);
        newBestiole = new Oreille(new Yeux(newBestiole, 1, 0, 0), 1, 25);
        bestioles.back() = newBestiole;
        // Puisque Bestiole n'a pas de jeTeVois on va faire le test ici exceptionnellement
        if (newBestiole->jeTeVois(*bestioles.front())) {
            bestioles.front()->setX(42);
        }
        break;
        }
        case 8: // Test la vision par l'oeuil mais pas par l'oreille
        {
        bestioles.front()->setX(10);
        bestioles.front()->setY(10);
        newBestiole->setX(30);
        newBestiole->setY(10); // La distance entre les deux bestioles vaut 20
        newBestiole->setOrientation(0);
        newBestiole = new Oreille(new Yeux(newBestiole, 1, 25, 6), 0, 0);
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
        case 1: {
        return (!(listeBestioles.front()->getX()==42));
        }
        case 2: {
        return (listeBestioles.front()->getX()==42);
        }
        case 3: {
        return (!(listeBestioles.front()->getX()==42));
        }
        case 4: {
        return (!(listeBestioles.front()->getX()==42));
        }
        case 5: {
        return (!(listeBestioles.front()->getX()==42));
        }
        case 6: {
        return (listeBestioles.front()->getX()==42);
        }
        case 7: {
        return (listeBestioles.front()->getX()==42);
        }
        case 8: {
        return (listeBestioles.front()->getX()==42);
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
  int nbTestsTotal = 8; 

  for (int i = 1; i < nbTestsTotal; i++) {
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
  cout  << nbTestsReussis << "successful tests over " << nbTestsTotal << " tests in total ." << endl;
  delete flotte;
}