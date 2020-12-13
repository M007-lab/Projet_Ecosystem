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

#endif