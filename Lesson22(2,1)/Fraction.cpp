#include "Fraction.h"
#include <iostream>
using namespace std;


// НСД
int Fraction::gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Скорочення
void Fraction::reduce() {
    int g = gcd(abs(num), abs(den));
    num /= g;
    den /= g;

    if (den < 0) {
        num = -num;
        den = -den;
    }
}

// Валидатор int
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
        return x;

        if (x < -1000 || x > 1000) {
            cout << "Wrong range!";
            continue;
        }
    }
}

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

void Fraction::print() {
    cout << num << " / " << den;
}

Fraction Fraction::add(Fraction other) {
    Fraction r;

    r.num = num * other.den + other.num * den;
    r.den = den * other.den;

    r.reduce();
    return r;
}

Fraction Fraction::sub(Fraction other) {
    Fraction r;

    r.num = num * other.den - other.num * den;
    r.den = den * other.den;

    r.reduce();
    return r;
}

Fraction Fraction::mul(Fraction other) {
    Fraction r;

    r.num = num * other.num;
    r.den = den * other.den;

    r.reduce();
    return r;
}

Fraction Fraction::div(Fraction other) {
    Fraction r;

    if (other.num == 0) {
        cout << "Error: division by zero fraction!\n";
        r.num = 0;
        r.den = 1;
        return r;
    }

    r.num = num * other.den;
    r.den = den * other.num;

    r.reduce();
    return r;
}
