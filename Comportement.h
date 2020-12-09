#ifndef _COMPORTEMENT_H
#define _COMPORTEMENT_H

#include "Bestiole.h"


// An interface implementing startegy pattern
class Comportement{
public:
    virtual void executeBehavior(Bestiole* bestiole)=0;
    virtual Comportement* dupliquer() const = 0;
    virtual ~Comportement(){};
    virtual std::string getName()=0;
};

#endif 
