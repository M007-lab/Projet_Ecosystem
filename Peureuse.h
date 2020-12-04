#ifndef PEUREUSE
#define PEUREUSE

#include "Comportement.h"
class Peureuse:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole) override;
    Comportement* dupliquer() const override;
     ~Peureuse(){};
    std::string getName() override;
};

#endif