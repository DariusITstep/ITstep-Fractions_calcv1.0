#include <iostream>
#include "Fraction.h"
#include "Input.h"
#include "Menu.h"

using namespace std;

int main() {

    Fraction f1 = Input::readFraction();
    Fraction f2 = Input::readFraction();

    Fraction result;

    while (true) {

        cout << "\n--- FRACTIONS ---\n";
        cout << "F1: "; f1.print();
        cout << "\nF2: "; f2.print();

        cout << "\n\nSelect operation:\n"
            << "1. add\n"
            << "2. sub\n"
            << "3. mul\n"
            << "4. div\n"
            << "5. inverse f1\n"
            << "6. inverse f2\n"
            << "7. reinput\n"
            << "0. exit\n"
            << "Choice: ";

        int c = Menu::getChoice();

        switch (c) {
        case 0:
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
            continue;

        case 6:
            f2.inverse();
            continue;

        case 7:
            f1 = Input::readFraction();
            f2 = Input::readFraction();
            continue;

        default:
            cout << "Wrong input!\n";
            continue;
        }

        cout << "Result: ";
        result.print();
        cout << endl;
    }
}