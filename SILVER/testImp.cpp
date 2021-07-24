#include <iostream>
#include "test.h"

using namespace std;

testClass::testClass(int ti, int tj) {
    testClass::j = tj;
    testClass::i = ti;
}
bool testClass::testFunc(int i, int j) const {
    return i == testClass::i && j == testClass::j;
}
