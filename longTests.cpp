#include "longTests.h"
#include "myMath.h"
#include <ctime>
#include <iostream>

using namespace std;

void longTests(unsigned long long *speed) {
    speed[0] = longHandler('+');
    speed[1] = longHandler('-');
    speed[2] = longHandler('*');
    speed[3] = longHandler('/');
}

unsigned long long longHandler(char o) {
    unsigned long long iter[3] = {0};
    double time[3] = {0};

    iter[0] = 2000000000;
    iter[1] = 10000;

    longSwitch(o, iter[0], &time[0]);
    longSwitch(o, iter[1], &time[1]);

    while (time[0] > 1.02 && time[1] < 0.98) {
        hDivMethod(iter);

        longSwitch(o, iter[2], &time[2]);

        if (time[2] >= 1) {
            iter[0] = iter[2];
            time[0] = time[2];
        } else {
            iter[1] = iter[2];
            time[1] = time[2];
        }
    }

    return iter[2];
}

void longSwitch(char o, unsigned long long longIter, double *time) {
    switch (o) {
        case '+':
            longPlus(longIter, time);
            break;
        case '-':
            longMinus(longIter, time);
            break;
        case '*':
            longProd(longIter, time);
            break;
        case '/':
            longDiv(longIter, time);
            break;
        default:
            cout << "unknown operand" << endl;
    }
}

void longPlus(unsigned long long longIter, double *tookTime) {
    long a1 = 342;
    long b1 = 403;
    long c1 = 432;
    long a2 = 465;
    long c2 = 46;
    long c3 = 47;
    long c4 = 48;
    long a20 = 942;

    clock_t start = clock();
    for(unsigned long long i = 0; i < longIter; i+=5) {
        a1 = b1 + c1;
        a2 = b1 + c2;
        b1 = a1 + c3;
        a1 = c3 + a20;
        a20 = b1 + c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void longMinus(unsigned long long longIter, double *tookTime) {
    long a1 = 65;
    long b1 = 66;
    long c1 = 67;
    long a2 = 68;
    long c2 = 69;
    long c3 = 70;
    long c4 = 71;
    long a20 = 272;

    clock_t start = clock();
    for(unsigned long long i = 0; i < longIter; i+=5) {
        a1 = b1 - c1;
        a2 = b1 - c2;
        b1 = a1 - c3;
        c4 = a20 - a2;
        a20 = b1 - c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void longProd(unsigned long long longIter, double *tookTime) {
    long a1 = 15;
    long b1 = 234;
    long c1 = 33;
    long a2 = 51;
    long c2 = 18;
    long c3 = 29;
    long c4 = 22;
    long a20 = 13;

    clock_t start = clock();
    for(unsigned long long i = 0; i < longIter; i+=5) {
        a1 = b1 * c1;
        a2 = b1 * c2;
        b1 = a1 * c3;
        c4 = a20 * a2;
        a20 = b1 * c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void longDiv(unsigned long long longIter, double *tookTime) {
    long a1 = 1073741824;
    long b1 = 1073741824;
    long c1 = 2;
    long a2 = 1073741824;
    long c2 = 1;
    long c3 = 2;
    long c4 = 1073741824;
    long a20 = 1073741824;

    clock_t start = clock();
    for(unsigned long long i = 0; i < longIter; i+=5) {
        a1 = b1 / c2;
        a2 = a1 / c2;
        b1 = a20 / c3;
        c4 = a2 / c2;
        a20 = b1 / c3;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}