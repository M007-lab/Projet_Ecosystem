#ifndef RANDDOUBLE_H
#define RANDDOUBLE_H
#include <cmath>

class Rand_double{
    private:
        double _low, _high;
    public:
    Rand_double(){};
    
    Rand_double(double low, double high);
    double operator()();

};



#endif