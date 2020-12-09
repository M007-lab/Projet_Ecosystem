#ifndef KAMIKAZE
#define KAMIKAZE

#include "Comportement.h"

class Kamikaze:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole, Milieu& milieu) override;
    virtual Kamikaze* dupliquer() const override;
     ~Kamikaze(){};
    virtual std::string getName() override;
};

#endif