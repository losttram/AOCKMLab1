#include "floatTests.h"
#include "myMath.h"
#include <ctime>
#include <iostream>

using namespace std;

void floatTests(unsigned long long *speed) {
    speed[0] = floatHandler('+');
    speed[1] = floatHandler('-');
    speed[2] = floatHandler('*');
    speed[3] = floatHandler('/');
}

unsigned long long floatHandler(char o) {
    unsigned long long iter[3] = {0};
    double time[3] = {0};

    iter[0] = 2000000000;
    iter[1] = 10000;

    floatSwitch(o, iter[0], &time[0]);
    floatSwitch(o, iter[1], &time[1]);

    while (time[0] > 1.02 && time[1] < 0.98) {
        hDivMethod(iter);

        floatSwitch(o, iter[2], &time[2]);

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

void floatSwitch(char o, unsigned long long floatIter, double *time) {
    switch (o) {
        case '+':
            floatPlus(floatIter, time);
            break;
        case '-':
            floatMinus(floatIter, time);
            break;
        case '*':
            floatProd(floatIter, time);
            break;
        case '/':
            floatDiv(floatIter, time);
            break;
        default:
            cout << "unknown operand" << endl;
    }
}

void floatPlus(unsigned long long floatIter, double *tookTime) {
    float a1 = 342.3478;
    float b1 = 403.9876;
    float c1 = 432.35;
    float a2 = 465.6757;
    float c2 = 46.9712;
    float c3 = 47.369;
    float c4 = 48.975;
    float a20 = 942.4556;

    clock_t start = clock();
    for(unsigned long long i = 0; i < floatIter; i+=5) {
        a1 = b1 + c1;
        a2 = b1 + c2;
        b1 = a1 + c3;
        a1 = c3 + a20;
        a20 = b1 + c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void floatMinus(unsigned long long floatIter, double *tookTime) {
    float a1 = 65.44;
    float b1 = 66.876;
    float c1 = 67.4577;
    float a2 = 68.982;
    float c2 = 69.335;
    float c3 = 70.987;
    float c4 = 71.24;
    float a20 = 272.4564;

    clock_t start = clock();
    for(unsigned long long i = 0; i < floatIter; i+=5) {
        a1 = b1 - c1;
        a2 = b1 - c2;
        b1 = a1 - c3;
        c4 = a20 - a2;
        a20 = b1 - c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void floatProd(unsigned long long floatIter, double *tookTime) {
    float a1 = 15.648;
    float b1 = 234.242;
    float c1 = 33.968;
    float a2 = 51.9876;
    float c2 = 18.2695;
    float c3 = 29.333;
    float c4 = 22.1091;
    float a20 = 13.986;

    clock_t start = clock();
    for(unsigned long long i = 0; i < floatIter; i+=5) {
        a1 = b1 * c1;
        a2 = b1 * c2;
        b1 = a1 * c3;
        c4 = a20 * a2;
        a20 = b1 * c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void floatDiv(unsigned long long floatIter, double *tookTime) {
    float a1 = 107.3741824;
    float b1 = 1073741.824;
    float c1 = 2.234;
    float a2 = 10737.41824;
    float c2 = 1.445;
    float c3 = 2.56;
    float c4 = 10737418.24;
    float a20 = 107374.1824;

    clock_t start = clock();
    for(unsigned long long i = 0; i < floatIter; i+=5) {
        a1 = b1 / c2;
        a2 = a1 / c2;
        b1 = a20 / c3;
        c4 = a2 / c2;
        a20 = b1 / c3;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}