#include "Fraction.h"
#include <iostream>
#include <cmath>

// --------------------
// constructors
// --------------------
Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (den == 0) {
        std::cout << "Warning: denominator = 0, set to 1\n";
        den = 1;
    }
    reduce();
}

// --------------------
// gcd + reduce
// --------------------
int Fraction::gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

void Fraction::reduce() {
    int g = gcd(num, den);
    num /= g;
    den /= g;

    if (den < 0) {
        num = -num;
        den = -den;
    }
}

// --------------------
// output
// --------------------
void Fraction::print() const {
    std::cout << "[" << num << " / " << den << "]\n";
}

// --------------------
// operators
// --------------------
Fraction Fraction::operator+(const Fraction& other) const {
    int newNum = num * other.den + other.num * den;
    int newDen = den * other.den;
    return Fraction(newNum, newDen);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int newNum = num * other.den - other.num * den;
    int newDen = den * other.den;
    return Fraction(newNum, newDen);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(num * other.num, den * other.den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.num == 0) {
        std::cout << "Error: division by zero fraction\n";
        return Fraction(0, 1);
    }

    return Fraction(num * other.den, den * other.num);
}

// --------------------
// inverse
// --------------------
void Fraction::inverse() {
    if (num == 0) {
        std::cout << "Error: cannot invert zero fraction\n";
        return;
    }

    std::swap(num, den);

    if (den < 0) {
        num = -num;
        den = -den;
    }
}