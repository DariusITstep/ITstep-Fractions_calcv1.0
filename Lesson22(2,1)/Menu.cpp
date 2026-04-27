#include "Menu.h"
#include <iostream>

using namespace std;

int Menu::getChoice() {
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