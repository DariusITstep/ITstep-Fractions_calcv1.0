#include "Fraction.h"
#include <iostream>

int inputer();

int main() {

    Fraction f1;
    Fraction f2(4, 7);
 
    while (true) {

        std::cout << "\n--- FRACTIONS ---\n";
        std::cout << "F1: "; f1.print();
        std::cout << "F2: "; f2.print();

        std::cout << "\n1. add\n2. sub\n3. mul\n4. div\n5. inverse f1\n6. inverse f2\n0. exit\nChoice: ";

        int choice = inputer();
        Fraction res;

        switch (choice) {
        case 0:
            return 0;

        case 1:
            res = f1 + f2;
            break;

        case 2:
            res = f1 - f2;
            break;

        case 3:
            res = f1 * f2;
            break;

        case 4:
            res = f1 / f2;
            break;

        case 5:
            f1.inverse();
            continue;

        case 6:
            f2.inverse();
            continue;

        default:
            std::cout << "Wrong input!\n";
            continue;
        }

        std::cout << "Result: ";
        res.print();
    }

    return 0;
}

// --------------------
// safe input
// --------------------
int inputer() {
    int x;

    while (true) {
        std::cin >> x;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Error: only integer!\n";
            continue;
        }

        return x;
    }
}