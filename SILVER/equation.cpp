#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int cur = 0;
    vector<bool> sign(a);
    for (int i = a ; i > 0 ; i--) {
        if (cur + i <= b) {
            cur += i;
            sign[i-1] = true;
        } else {
            cur -= i;
            sign[i-1] = false;
        }
    }
    if (cur == b) {
        cout << 0;
        for (int i = 0 ; i < sign.size() ; i++) {
            if (sign[i]) {
                cout << "+" << i+1;
            } else {
                cout << "-" << i+1;
            }
        }
    } else{ 
        cout << "IMPOSSIBLE" << endl;
    }
}