#ifndef _CAPTEURDECORATEUR_H
#define _CAPTEURDECORATEUR_H

#include "BestioleSimple.h"

class CapteurDecorateur : public BestioleSimple {
  protected :
    std::string name;
    BestioleSimple* base;

  public :
    virtual ~CapteurDecorateur();

    BestioleSimple* getBase() const;
    std::string getName() const;

    virtual bool jeTeVois( const Bestiole & b ) const override = 0;

    virtual void toString(std::ostringstream stream) = 0;
    virtual void draw(UImg& support) = 0;

};
#endif