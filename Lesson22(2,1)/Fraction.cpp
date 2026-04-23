#include "Fraction.h"
#include <iostream>
#include <cmath>
using namespace std;

// ---------------- constructors ----------------

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (den == 0) {
        cout << "Error: denominator = 0! Set to 1\n";
        den = 1;
    }
    reduce();
}

// ---------------- destructor ----------------

Fraction::~Fraction() {
    // no dynamic memory
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

// ---------------- input validator ----------------

int Fraction::inputInt() {
    int x;
    while (true) {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: only integer!\n";
            continue;
        }

        if (x < -1000 || x > 1000) {
            cout << "Wrong range!\n";
            continue;
        }

        return x;
    }
}

// ---------------- input / print ----------------

void Fraction::input() {
    cout << "Enter numerator: ";
    num = inputInt();

    while (true) {
        cout << "Enter denominator: ";
        den = inputInt();

        if (den == 0) {
            cout << "Error: denominator cannot be 0!\n";
            continue;
        }
        break;
    }

    reduce();
}

void Fraction::print() const {
    cout << num << " / " << den;
}

// ---------------- operations ----------------

Fraction Fraction::add(const Fraction& other) const {
    return Fraction(
        num * other.den + other.num * den,
        den * other.den
    );
}

Fraction Fraction::sub(const Fraction& other) const {
    return Fraction(
        num * other.den - other.num * den,
        den * other.den
    );
}

Fraction Fraction::mul(const Fraction& other) const {
    return Fraction(
        num * other.num,
        den * other.den
    );
}

Fraction Fraction::div(const Fraction& other) const {
    if (other.num == 0) {
        cout << "Error: division by zero fraction!\n";
        return Fraction(0, 1);
    }

    return Fraction(
        num * other.den,
        den * other.num
    );
}

// ---------------- inverse ----------------

void Fraction::inverse() {
    if (num == 0) {
        cout << "Error: cannot invert zero!\n";
        return;
    }

    swap(num, den);

    if (den < 0) {
        num = -num;
        den = -den;
    }
}