// #ifndef _ACCESOIREDECORATEUR_H
// #define _ACCESOIREDECORATEUR_H

#include "Bestiole.h"
#include "Comportement.h"

class AccessoireDecorateur : public Bestiole {
protected :
    std::string name;
    Bestiole* base;
    std::list<AccessoireDecorateur> accessoiresDecorateurs;

public :
    virtual ~AccessoireDecorateur();
    virtual void draw(UImg& support);
    virtual bool jeTeVois( const Bestiole & b ) const;

    Bestiole* getBase() const;
    std::string getName() const;

    std::list<AccessoireDecorateur> getAccessoireDecorateurs() override;
};

#endif