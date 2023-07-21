#include <iostream>

#include <vector>

using namespace std;

int main() {
    double cur = 1;
    double step = 1000000;
    for (int i = 0 ; i < step ; i++) {
        cur = cur * (1 + 0.3/step);
    }
    cout << cur << endl;
}