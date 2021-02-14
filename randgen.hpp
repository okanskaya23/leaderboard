#ifndef _RANDGEN_H
#define _RANDGEN_H

#include <limits.h>
class RandGen
{
  public:
    RandGen();                          // set seed for all instances
    int RandInt(int max = INT_MAX);     // returns int in [0..max)
    int RandInt(int low, int max);      // returns int in [low..max]
    double RandReal();                  // returns double in [0..1)
    double RandReal(double low, double max); // range [low..max]
    static void SetSeed(int seed);      // static (per class) seed set
private:
    static int ourInitialized;          // for 'per-class' initialization
};

#endif
