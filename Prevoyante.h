#ifndef PREVOYANTE
#define PREVOYANTE

#include "Comportement.h"


class Prevoyante: public Comportement {
public:
    void executeBehavior(Bestiole* bestiole, Milieu& milieu) override;
    virtual Prevoyante* dupliquer() const override;
    ~Prevoyante(){};
    virtual std::string getName() override;
};


#endif 