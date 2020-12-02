#include "Comportement.h"
class Gregaire:public Comportement{
public:
    void executeBehavior(Bestiole* bestiole) override;
    Comportement* dupliquer() const override;
     ~Gregaire(){};
    std::string getName() override;
};
