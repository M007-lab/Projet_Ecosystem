#ifndef PEUREUSE
#define PEUREUSE

#include "Comportement.h"
class Peureuse:public Comportement{
public:
    virtual void executeBehavior(Bestiole* bestiole) override;
    virtual Peureuse* dupliquer() const override;
     ~Peureuse(){};
    virtual std::string getName() override;
};

#endif