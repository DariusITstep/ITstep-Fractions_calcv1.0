#include "Input.h"
#include <iostream>

using namespace std;

// ---------------- safe int ----------------

int Input::readInt(int min, int max) {
    int x;

    while (true) {
        cin >> x;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: only integer!\n";
            continue;
        }

        if (x < min || x > max) {
            cout << "Error range!\n";
            continue;
        }

        cin.ignore(10000, '\n');
        return x;
    }
}

// ---------------- fraction input ----------------

Fraction Input::readFraction() {
    int n, d;

    cout << "Enter numerator: ";
    n = readInt(-1000, 1000);

    while (true) {
        cout << "Enter denominator: ";
        d = readInt(-1000, 1000);

        if (d == 0) {
            cout << "Denominator cannot be 0!\n";
            continue;
        }
        break;
    }

    return Fraction(n, d);
}