#pragma once
#include "Fraction.h"

class Input {
public:
    static int readInt(int min, int max);
    static Fraction readFraction();
};