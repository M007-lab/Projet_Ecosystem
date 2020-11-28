#include "BestioleSimple.h"

class Decorator: public BestioleSimple
{
public:
    BestioleSimple* getBase() = 0;
    void toString() = 0;

};