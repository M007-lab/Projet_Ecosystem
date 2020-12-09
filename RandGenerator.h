#ifndef RANDGEN_H
#define RANDGEN_H
#include <cmath>

class Rand_double{
    private:
        double _low, _high;
    public:
    Rand_double();
    
    Rand_double(double low, double high);
    double operator()();

};
class Rand_int{
    private:
        int _low, _high;
    public:
        Rand_int();
        
        Rand_int(int low, int high);
        int operator()();

};
Rand_double::Rand_double(double low, double high): _low(low),_high(high){}
Rand_int::Rand_int(int low, int high): _low(low),_high(high){}

double Rand_double::operator()()
{
    double f = (double)rand() / RAND_MAX;
    return _low + f * (_high - _low);
}

int Rand_int::operator()()
{
    int f = rand() / RAND_MAX;
    return _low + f * (_high - _low);
}
#endif