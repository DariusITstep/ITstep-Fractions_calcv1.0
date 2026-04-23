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
    // constructors
    Fraction();
    Fraction(int n, int d);

    // destructor
    ~Fraction();

    void input();
    void print() const;
   
    Fraction add(const Fraction& other) const;
    Fraction sub(const Fraction& other) const;
    Fraction mul(const Fraction& other) const;
    Fraction div(const Fraction& other) const;

    void inverse();
};