#ifndef CAPTEURDECORATEUR_H
#define CAPTEURDECORATEUR_H

#include "Bestiole.h"

class CapteurDecorateur : public Bestiole {
  protected :
    std::string name;
    Bestiole* base;

  public :
    virtual ~CapteurDecorateur();

    Bestiole* getBase() const;
    std::string getName() const;

    virtual bool jeTeVois( const Bestiole & b ) const override;

    virtual void toString() = 0;
    virtual void draw(UImg& support) = 0;

};
#endif