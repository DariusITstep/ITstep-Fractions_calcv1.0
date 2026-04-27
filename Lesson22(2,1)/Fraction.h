#pragma once
#include <iostream>

class Fraction {
private:
    int num;
    int den;

    int gcd(int a, int b);
    void reduce();

public:
    Fraction();
    Fraction(int n, int d);

    void print() const;

    Fraction add(const Fraction& other) const;
    Fraction sub(const Fraction& other) const;
    Fraction mul(const Fraction& other) const;
    Fraction div(const Fraction& other) const;

    void inverse();
};