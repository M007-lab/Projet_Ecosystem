#ifndef RANDINT_H
#define RANDINT_H
#include <cmath>

class Rand_int{
    private:
        int _low, _high;
    public:
        Rand_int(){};
        
        Rand_int(int low, int high);
        int operator()();

};

#endif