#include <iostream>

int func(int a, double b) {
    return a-b;
}
int func(double a, int b) {
    return a+b;
}

using namespace std;

int main() {
    cout << func(1,2) << endl;
}