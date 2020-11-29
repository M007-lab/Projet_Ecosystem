#include "AccesoireDecorator.h"

class Accesoire: public AccesoireDecorator
{
private:

public:
    virtual double getVitesse() const override;
    virtual double getCamouflage() const override;
    virtual void toString() override;


}