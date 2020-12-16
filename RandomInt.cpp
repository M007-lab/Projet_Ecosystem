

#include "RandomInt.h"
#include <iostream>
using namespace std;
Rand_int::Rand_int(int low, int high): _low(low),_high(high){}

int Rand_int::operator()()
{   
    
   
    return rand()%(_high - _low + 1) + _low ;
}