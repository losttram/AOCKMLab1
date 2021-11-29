#include "charTest.h"

#include "myMath.h"
#include <ctime>
#include <iostream>

using namespace std;

void charTests(unsigned long long *speed) {
    speed[0] = charHandler('+');
    speed[1] = charHandler('-');
    speed[2] = charHandler('*');
    speed[3] = charHandler('/');
}

unsigned long long charHandler(char o) {
    unsigned long long iter[3] = {0};
    double time[3] = {0};

    iter[0] = 2000000000;
    iter[1] = 10000;

    charSwitch(o, iter[0], &time[0]);
    charSwitch(o, iter[1], &time[1]);

    while (time[0] > 1.02 && time[1] < 0.98) {
        hDivMethod(iter);

        charSwitch(o, iter[2], &time[2]);

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

void charSwitch(char o, unsigned long long charIter, double *time) {
    switch (o) {
        case '+':
            charPlus(charIter, time);
            break;
        case '-':
            charMinus(charIter, time);
            break;
        case '*':
            charProd(charIter, time);
            break;
        case '/':
            charDiv(charIter, time);
            break;
        default:
            cout << "unknown operand" << endl;
    }
}

void charPlus(unsigned long long charIter, double *tookTime) {
    char a1 = 42;
    char b1 = 43;
    char c1 = 32;
    char a2 = 65;
    char c2 = 46;
    char c3 = 47;
    char c4 = 48;
    char a20 = 94;

    clock_t start = clock();
    for(unsigned long long i = 0; i < charIter; i+=5) {
        a1 = b1 + c1;
        a2 = b1 + c2;
        b1 = a1 + c3;
        a1 = c3 + a20;
        a20 = b1 + c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void charMinus(unsigned long long charIter, double *tookTime) {
    char a1 = 65;
    char b1 = 66;
    char c1 = 67;
    char a2 = 68;
    char c2 = 69;
    char c3 = 70;
    char c4 = 71;
    char a20 = 22;

    clock_t start = clock();
    for(unsigned long long i = 0; i < charIter; i+=5) {
        a1 = b1 - c1;
        a2 = b1 - c2;
        b1 = a1 - c3;
        c4 = a20 - a2;
        a20 = b1 - c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void charProd(unsigned long long charIter, double *tookTime) {
    char a1 = 15;
    char b1 = 24;
    char c1 = 33;
    char a2 = 51;
    char c2 = 18;
    char c3 = 29;
    char c4 = 22;
    char a20 = 13;

    clock_t start = clock();
    for(unsigned long long i = 0; i < charIter; i+=5) {
        a1 = b1 * c1;
        a2 = b1 * c2;
        b1 = a1 * c3;
        c4 = a20 * a2;
        a20 = b1 * c4;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}

void charDiv(unsigned long long charIter, double *tookTime) {
    char a1 = 48;
    char b1 = 73;
    char c1 = 2;
    char a2 = 18;
    char c2 = 1;
    char c3 = 2;
    char c4 = 24;
    char a20 = 74;

    clock_t start = clock();
    for(unsigned long long i = 0; i < charIter; i+=5) {
        a1 = b1 / c2;
        a2 = a1 / c2;
        b1 = a20 / c3;
        c4 = a2 / c2;
        a20 = b1 / c3;
    }
    clock_t stop = clock();

    *tookTime = (double)(stop - start) / CLK_TCK;
}