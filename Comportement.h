#ifndef _COMPORTEMENT_H
#define _COMPORTEMENT_H

#include "Bestiole.h"
#include "Milieu.h"
#include "Configuration.h"

// An interface implementing startegy pattern
class Comportement{
public:
    virtual void executeBehavior(Bestiole* bestiole,Milieu& milieu)=0;
    virtual Comportement* dupliquer() const = 0;
    virtual ~Comportement(){};
    virtual std::string getName()=0;
};

#endif 
