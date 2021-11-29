#include <iostream>
#include "intTests.h"
#include "longTests.h"
#include "floatTests.h"
#include "doubleTests.h"
#include "charTest.h"
#include "outputWriter.h"

int main() {
    unsigned long long intSpeed[4] = {0};
    intTests(intSpeed);

    unsigned long long longSpeed[4] = {0};
    longTests(longSpeed);

    unsigned long long floatSpeed[4] = {0};
    floatTests(floatSpeed);

    unsigned long long doubleSpeed[4] = {0};
    doubleTests(doubleSpeed);

    unsigned long long charSpeed[4] = {0};
    charTests(charSpeed);
    outputMaker(intSpeed, longSpeed, floatSpeed, doubleSpeed, charSpeed);

    return 0;
}
