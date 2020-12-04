#ifndef KAMIKAZE
#define KAMIKAZE

#include "Comportement.h"
class Kamikaze:public Comportement{
public:
    virtual void executeBehavior(Bestiole* bestiole) override;
    virtual Kamikaze* dupliquer() const override;
     ~Kamikaze(){};
    virtual std::string getName() override;
};

#endif