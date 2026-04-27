#include "Fraction.h"
#include <iostream>
#include <cmath>

using namespace std;

// ---------------- constructors ----------------

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (den == 0) den = 1;
    reduce();
}

// ---------------- gcd + reduce ----------------

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

// ---------------- print ----------------

void Fraction::print() const {
    cout << num << " / " << den;
}

// ---------------- operations ----------------

Fraction Fraction::add(const Fraction& o) const {
    return Fraction(num * o.den + o.num * den, den * o.den);
}

Fraction Fraction::sub(const Fraction& o) const {
    return Fraction(num * o.den - o.num * den, den * o.den);
}

Fraction Fraction::mul(const Fraction& o) const {
    return Fraction(num * o.num, den * o.den);
}

Fraction Fraction::div(const Fraction& o) const {
    if (o.num == 0) return Fraction(0, 1);
    return Fraction(num * o.den, den * o.num);
}

// ---------------- inverse ----------------

void Fraction::inverse() {
    if (num == 0) return;

    swap(num, den);

    if (den < 0) {
        num = -num;
        den = -den;
    }
}