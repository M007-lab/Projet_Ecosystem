#include "Multiple.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyante.h"

void Multiple::executeBehavior(Bestiole* bestiole,Milieu& milieu){

}

Multiple::~Multiple(){

}

Multiple* Multiple::dupliquer() const{
    return new Multiple(*this);
}

std::string Multiple::getName(){
    return "Multiple";
}
