#include <iostream>

using namespace std;

int main() {
    int a = 0;
    int b = 1;
    int c;
    int d;
    bool done = false;
    while (true){
        c = b*2+a;
        d = 0;
        while (true) {
            d++;
            if (d*d-c == 0) {
                done = true;
                break;
            } if (d*d - c < 0) {
                continue;
            } else {
                break;
            }
        }
        if (done) break;

        a = b;
        b = c;
    }
    cout << c << endl;
}