#ifndef CAPTEURDECORATEUR_H
#define CAPTEURDECORATEUR_H

#include "Bestiole.h"
#include "Comportement.h"

class CapteurDecorateur : public Bestiole {
  protected :
    std::string name;
    Bestiole* base;
    std::list<CapteurDecorateur> capteurDecorateurs;

  public :
    virtual ~CapteurDecorateur();
    virtual void draw(UImg& support);
    virtual bool jeTeVois( const Bestiole & b ) const;

    Bestiole* getBase() const;
    std::string getName() const;

    std::list<CapteurDecorateur> getCapteurDecorateurs() override;
};

#endif