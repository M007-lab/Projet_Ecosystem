#include "RandomDouble.h"

Rand_double::Rand_double(double low, double high): _low(low),_high(high){}


double Rand_double::operator()()
{
    double f = (double) rand() / RAND_MAX;
    return _low + f * (_high - _low);
}
