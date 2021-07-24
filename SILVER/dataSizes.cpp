#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef unsigned int u32_t;

typedef struct {
        u32_t field1:2;
        u32_t field2:5;
        u32_t field3:20;
        u32_t field4:5;
}my_type_t;

typedef union {
    my_type_t structure;
    u32_t dword;
}common_t;

common_t a;

int main() {
    cout << "Size of boolean: " << sizeof(bool) << " bytes." << endl;
    cout << "Size of int: " << sizeof(int) << " bytes." << endl;
    cout << "Size of char: " << sizeof(char) << " bytes." << endl;
    cout << "Size of long: " << sizeof(long) << " bytes." << endl;
    cout << "Size of float: " << sizeof(float) << " bytes." << endl;
    cout << "Size of double: " << sizeof(double) << " bytes." << endl; 

    a.structure.field1 = 2;
    a.structure.field2 = 532; 
    cout << a.dword << endl;

    for (int i = 0; i < 32; i++) {
        if ((a.dword & (1 << i)) == 0) {
            cout << "0";
        } else {
            cout << "1";
        }
    }

    printf("\nNumber = %08x\n",a.dword);
    cout << endl;
    

}