#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction f1, f2;
void reInputer();

int main() {    

    reInputer();
    int choice; 
    Fraction result;

    while (true) {

        cout << "\nSelect operation:\n"
            << "1. add fractions\n"
            << "2. sub fractions\n"
            << "3. mul fractions\n"
            << "4. div fractions\n"
            << "5. Reinput fractions\n"
            << "0. Exit...\n"
            << "Choice: ";

        cin >> choice;
        
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
            reInputer();
            continue;
        default:
            cout << "Wrong input!";
            continue;
        }

        cout << "Result: ";
        result.print();
        cout << endl;
        continue;
    }
    return 0;
}

void reInputer() {

    cout << "First fraction(max 1000):\n";
    f1.input();
    cout << "Second fraction(max 1000):\n";
    f2.input();

    cout << "Current fractions: ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << endl;
}