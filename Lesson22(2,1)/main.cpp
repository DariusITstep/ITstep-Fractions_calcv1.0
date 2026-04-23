#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction f1, f2;

void reInputer();
int inputChoice();
void showCur();

int main() {

    reInputer();

    Fraction result;
    int choice;

    while (true) {

        cout << "\nSelect operation:\n"
            << "1. add fractions\n"
            << "2. sub fractions\n"
            << "3. mul fractions\n"
            << "4. div fractions\n"
            << "5. inverse first fraction\n"
            << "6. inverse second fraction\n"
            << "7. reinput fractions\n"
            << "0. exit\n"
            << "Choice: ";

        choice = inputChoice();

        switch (choice) {
        case 0:
            cout << "Exit program...";
            return 0;

        case 1:
            result = f1.add(f2);
            break;

        case 2:
            result = f1.sub(f2);
            break;

        case 3:
            result = f1.mul(f2);
            break;

        case 4:
            result = f1.div(f2);
            break;

        case 5:
            f1.inverse();
            break;

        case 6:
            f2.inverse();
            break;

        case 7:
            reInputer();
            continue;

        default:
            cout << "Wrong input!\n";
            continue;
        }

        if (choice == 5 || choice == 6) {
            showCur();
        }
        else {
            cout << "Result: ";
            result.print();
            cout << endl;
        }
        
    }

    return 0;
}

// ---------------- shower ----------------
void showCur() {

    cout << "Current fractions: ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << endl;
}

// ---------------- reinput ----------------

void reInputer() {
    cout << "First fraction:\n";
    f1.input();

    cout << "Second fraction:\n";
    f2.input();

    showCur();
}

// ---------------- safe menu input ----------------

int inputChoice() {
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
    }
}

