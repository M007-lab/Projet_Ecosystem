#ifndef KAMIKAZE
#define KAMIKAZE

#include "Comportement.h"
class Kamikaze:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole) override;
    Comportement* dupliquer() const override;
     ~Kamikaze(){};
    std::string getName() override;
};

#endif