#ifndef PEUREUSE
#define PEUREUSE

#include "Comportement.h"
class Peureuse:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole, Milieu& milieu) override;
    virtual Peureuse* dupliquer() const override;
     ~Peureuse(){};
    virtual std::string getName() override;
};

#endif