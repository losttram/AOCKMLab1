#include "outputWriter.h"
#include <iostream>
#include <string>

using namespace std;

void outputMaker(unsigned long long *intPerSec, unsigned long long *longPerSec, unsigned long long *floatPerSec, unsigned long long *doublePerSec, unsigned long long *charPerSec) {
    unsigned long long f = findFastest(intPerSec, longPerSec, floatPerSec, doublePerSec, charPerSec);

    cout << "+\tint\t"<< intPerSec[0] << "\t";
    build(intPerSec[0], f);
    cout << "-\tint\t"<< intPerSec[1] << "\t";
    build(intPerSec[1], f);
    cout << "*\tint\t"<< intPerSec[2] << "\t";
    build(intPerSec[2], f);
    cout << "/\tint\t"<< intPerSec[3] << "\t";
    build(intPerSec[3], f);

    cout << "+\tlong\t"<< longPerSec[0] << "\t";
    build(longPerSec[0], f);
    cout << "-\tlong\t"<< longPerSec[1] << "\t";
    build(longPerSec[1], f);
    cout << "*\tlong\t"<< longPerSec[2] << "\t";
    build(longPerSec[2], f);
    cout << "/\tlong\t"<< longPerSec[3] << "\t";
    build(longPerSec[3], f);

    cout << "+\tfloat\t"<< floatPerSec[0] << "\t";
    build(floatPerSec[0], f);
    cout << "-\tfloat\t"<< floatPerSec[1] << "\t";
    build(floatPerSec[1], f);
    cout << "*\tfloat\t"<< floatPerSec[2] << "\t";
    build(floatPerSec[2], f);
    cout << "/\tfloat\t"<< floatPerSec[3] << "\t";
    build(floatPerSec[3], f);

    cout << "+\tdouble\t"<< doublePerSec[0] << "\t";
    build(doublePerSec[0], f);
    cout << "-\tdouble\t"<< doublePerSec[1] << "\t";
    build(doublePerSec[1], f);
    cout << "*\tdouble\t"<< doublePerSec[2] << "\t";
    build(doublePerSec[2], f);
    cout << "/\tdouble\t"<< doublePerSec[3] << "\t";
    build(doublePerSec[3], f);

    cout << "+\tchar\t"<< charPerSec[0] << "\t";
    build(charPerSec[0], f);
    cout << "-\tchar\t"<< charPerSec[1] << "\t";
    build(charPerSec[1], f);
    cout << "*\tchar\t"<< charPerSec[2] << "\t";
    build(charPerSec[2], f);
    cout << "/\tchar\t"<< charPerSec[3] << "\t";
    build(charPerSec[3], f);
}

unsigned long long findFastest(unsigned long long *intPerSec, unsigned long long *longPerSec, unsigned long long *floatPerSec, unsigned long long *doublePerSec, unsigned long long *charPerSec) {
    unsigned long long max = 0;

    for (int i = 0; i < 4; i++) {
        if (intPerSec[i] > max) {
            max = intPerSec[i];
        }
        if (longPerSec[i] > max) {
            max = longPerSec[i];
        }
        if (floatPerSec[i] > max) {
            max = floatPerSec[i];
        }
        if (doublePerSec[i] > max) {
            max = doublePerSec[i];
        }
        if (charPerSec[i] > max) {
            max = charPerSec[i];
        }
    }

    return max;
}

void build(unsigned long long val, unsigned long long max) {
    int p = (int)(100 * val / max);

    for (int i = 0; i < p; i+=2) {
        cout << "X";
    }

    for (int i = p; i < 100; i+=2) {
        cout << " ";
    }

    cout << "\t" << p << "%" << endl;
}