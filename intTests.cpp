#include "intTests.h"
#include "myMath.h"
#include <ctime>
#include <iostream>

using namespace std;

void intTests(unsigned long long *speed) {
    speed[0] = intHandler('+');
    speed[1] = intHandler('-');
    speed[2] = intHandler('*');
    speed[3] = intHandler('/');
}

unsigned long long intHandler(char o) {
    unsigned long long iter[3] = {0};
    double time[3] = {0};

    iter[0] = 2000000000;
    iter[1] = 10000;

    intSwitch(o, iter[0], &time[0]);
    intSwitch(o, iter[1], &time[1]);

    while (time[0] > 1.02 && time[1] < 0.98) {
        hDivMethod(iter);

        intSwitch(o, iter[2], &time[2]);

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

void intSwitch(char o, unsigned long long intIter, double *time) {
    switch (o) {
        case '+':
            intPlus(intIter, time);
            break;
        case '-':
            intMinus(intIter, time);
            break;
        case '*':
            intProd(intIter, time);
            break;
        case '/':
            intDiv(intIter, time);
            break;
        default:
            cout << "unknown operand" << endl;
    }
}

void intPlus(unsigned long long intIter, double *tookTime) {
    int a1 = 342;
    int b1 = 403;
    int c1 = 432;
    int a2 = 465;
    int c2 = 46;
    int c3 = 47;
    int c4 = 48;
    int a20 = 942;

    clock_t start = clock();
    for(unsigned long long i = 0; i < intIter; i+=5) {
        a1 = b1 + c1;
        a2 = b1 + c2;
        b1 = a1 + c3;
        a1 = c3 + a20;
        a20 = b1 + c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void intMinus(unsigned long long intIter, double *tookTime) {
    int a1 = 65;
    int b1 = 66;
    int c1 = 67;
    int a2 = 68;
    int c2 = 69;
    int c3 = 70;
    int c4 = 71;
    int a20 = 272;

    clock_t start = clock();
    for(unsigned long long i = 0; i < intIter; i+=5) {
        a1 = b1 - c1;
        a2 = b1 - c2;
        b1 = a1 - c3;
        c4 = a20 - a2;
        a20 = b1 - c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void intProd(unsigned long long intIter, double *tookTime) {
    int a1 = 15;
    int b1 = 234;
    int c1 = 33;
    int a2 = 51;
    int c2 = 18;
    int c3 = 29;
    int c4 = 22;
    int a20 = 13;

    clock_t start = clock();
    for(unsigned long long i = 0; i < intIter; i+=5) {
        a1 = b1 * c1;
        a2 = b1 * c2;
        b1 = a1 * c3;
        c4 = a20 * a2;
        a20 = b1 * c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void intDiv(unsigned long long intIter, double *tookTime) {
    int a1 = 1073741824;
    int b1 = 1073741824;
    int c1 = 2;
    int a2 = 1073741824;
    int c2 = 1;
    int c3 = 2;
    int c4 = 1073741824;
    int a20 = 1073741824;

    clock_t start = clock();
    for(unsigned long long i = 0; i < intIter; i+=5) {
        a1 = b1 / c2;
        a2 = a1 / c2;
        b1 = a20 / c3;
        c4 = a2 / c2;
        a20 = b1 / c3;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}