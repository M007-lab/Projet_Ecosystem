#ifndef MULTIPLE
#define MULTIPLE

#include "Comportement.h"


class Multiple: public Comportement {
    Comportement* comportement;
public:
    ~Multiple();
    void executeBehavior(Bestiole* bestiole,Milieu& milieu) override;
    virtual Multiple* dupliquer() const override;
    virtual std::string getName() override;
};


#endif 