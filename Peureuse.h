#ifndef PEUREUSE_H
#define PEUREUSE_H

#include "Comportement.h"
class Peureuse:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole, Milieu& milieu) override;
    virtual Peureuse* dupliquer() const override;
     ~Peureuse(){};
    virtual std::string getName() override;
};

#endif