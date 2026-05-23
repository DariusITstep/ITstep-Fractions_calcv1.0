#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Fraction
{
private:

    int num;
    int den;

    int gcd(int a, int b);
    void reduce();

public:

    Fraction();
    Fraction(int n, int d);

    void print() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    void inverse();

    // SAVE / LOAD
    void save(ofstream& out) const;
    void load(ifstream& in);
};