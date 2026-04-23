#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int num;
    int den;
    
    int gcd(int a, int b);
    void reduce();     
    int inputInt();

public:
    void input();
    void print();
    Fraction add(Fraction other);
    Fraction sub(Fraction other);
    Fraction mul(Fraction other);
    Fraction div(Fraction other);
};