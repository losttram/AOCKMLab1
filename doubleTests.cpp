#include "doubleTests.h"
#include "myMath.h"
#include <ctime>
#include <iostream>

using namespace std;

void doubleTests(unsigned long long *speed) {
    speed[0] = doubleHandler('+');
    speed[1] = doubleHandler('-');
    speed[2] = doubleHandler('*');
    speed[3] = doubleHandler('/');
}

unsigned long long doubleHandler(char o) {
    unsigned long long iter[3] = {0};
    double time[3] = {0};

    iter[0] = 2000000000;
    iter[1] = 10000;

    doubleSwitch(o, iter[0], &time[0]);
    doubleSwitch(o, iter[1], &time[1]);

    while (time[0] > 1.02 && time[1] < 0.98) {
        hDivMethod(iter);

        doubleSwitch(o, iter[2], &time[2]);

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

void doubleSwitch(char o, unsigned long long doubleIter, double *time) {
    switch (o) {
        case '+':
            doublePlus(doubleIter, time);
            break;
        case '-':
            doubleMinus(doubleIter, time);
            break;
        case '*':
            doubleProd(doubleIter, time);
            break;
        case '/':
            doubleDiv(doubleIter, time);
            break;
        default:
            cout << "unknown operand" << endl;
    }
}

void doublePlus(unsigned long long doubleIter, double *tookTime) {
    double a1 = 342.65;
    double b1 = 403.34;
    double c1 = 432.07;
    double a2 = 465.38;
    double c2 = 46.98;
    double c3 = 47.42;
    double c4 = 48.49;
    double a20 = 942.34;

    clock_t start = clock();
    for(unsigned long long i = 0; i < doubleIter; i+=5) {
        a1 = b1 + c1;
        a2 = b1 + c2;
        b1 = a1 + c3;
        a1 = c3 + a20;
        a20 = b1 + c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void doubleMinus(unsigned long long doubleIter, double *tookTime) {
    double a1 = 65.87;
    double b1 = 66.82;
    double c1 = 67.97;
    double a2 = 68.37;
    double c2 = 69.94;
    double c3 = 70.63;
    double c4 = 71.27;
    double a20 = 272.76;

    clock_t start = clock();
    for(unsigned long long i = 0; i < doubleIter; i+=5) {
        a1 = b1 - c1;
        a2 = b1 - c2;
        b1 = a1 - c3;
        c4 = a20 - a2;
        a20 = b1 - c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void doubleProd(unsigned long long doubleIter, double *tookTime) {
    double a1 = 15.48;
    double b1 = 234.04;
    double c1 = 33.51;
    double a2 = 51.87;
    double c2 = 18.24;
    double c3 = 29.95;
    double c4 = 22.77;
    double a20 = 13.22;

    clock_t start = clock();
    for(unsigned long long i = 0; i < doubleIter; i+=5) {
        a1 = b1 * c1;
        a2 = b1 * c2;
        b1 = a1 * c3;
        c4 = a20 * a2;
        a20 = b1 * c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void doubleDiv(unsigned long long doubleIter, double *tookTime) {
    double a1 = 10737418.24;
    double b1 = 10737418.24;
    double c1 = 2.97;
    double a2 = 10737418.24;
    double c2 = 1.87;
    double c3 = 2.36;
    double c4 = 10737418.24;
    double a20 = 10737418.24;

    clock_t start = clock();
    for(unsigned long long i = 0; i < doubleIter; i+=5) {
        a1 = b1 / c2;
        a2 = a1 / c2;
        b1 = a20 / c3;
        c4 = a2 / c2;
        a20 = b1 / c3;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}