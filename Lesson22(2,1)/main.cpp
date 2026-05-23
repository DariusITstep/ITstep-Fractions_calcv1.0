#include "Fraction.h"

int main()
{
    Fraction f1(2, 3);
    Fraction f2(5, 7);

    cout << "Original fractions:" << endl;

    f1.print();
    f2.print();

    // SAVE
    ofstream out("fractions.bin", ios::binary);

    if (!out)
    {
        cout << "File open error!" << endl;
        return 1;
    }

    f1.save(out);
    f2.save(out);

    out.close();

    // OBJECT FOR LOAD
    Fraction a;
    Fraction b;

    // LOAD
    ifstream in("fractions.bin", ios::binary);

    if (!in)
    {
        cout << "File open error!" << endl;
        return 1;
    }

    a.load(in);
    b.load(in);

    in.close();

    cout << endl;

    cout << "Loaded fractions:" << endl;

    a.print();
    b.print();

    cout << endl;

    // OPTIONS
    Fraction sum = a + b;

    cout << "Sum:" << endl;

    sum.print();

    return 0;
}