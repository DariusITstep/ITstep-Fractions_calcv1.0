#include "Fraction.h"

int Fraction::gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void Fraction::reduce()
{
    int div = gcd(abs(num), abs(den));

    num /= div;
    den /= div;

    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) : num(n), den((d == 0) ? 1 : d) 
{
    reduce();
}

void Fraction::print() const
{
    cout << num << "/" << den << endl;
}

Fraction Fraction::operator+(const Fraction& other) const
{
    return Fraction(num * other.den + other.num * den, den * other.den);
}

Fraction Fraction::operator-(const Fraction& other) const
{
    return Fraction(num * other.den - other.num * den, den * other.den);
}

Fraction Fraction::operator*(const Fraction& other) const
{
    return Fraction(num * other.num, den * other.den);
}

Fraction Fraction::operator/(const Fraction& other) const
{
    return Fraction(num * other.den, den * other.num);
}

void Fraction::inverse()
{
    int temp = num;
    num = den;
    den = temp;

    reduce();
}

// SAVE
void Fraction::save(ofstream& out) const
{
    out.write((char*)&num, sizeof(num));
    out.write((char*)&den, sizeof(den));
}

// LOAD
void Fraction::load(ifstream& in)
{
    in.read((char*)&num, sizeof(num));
    in.read((char*)&den, sizeof(den));
}