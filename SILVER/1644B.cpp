#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << "1 3 2" << endl;
        cout << "3 1 2" << endl;
        cout << "3 2 1" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = n-1 ; j >= 0 ; j--) {
            int l = (j+i)%n+1;
            cout << l << " ";
        }
        cout << endl;
    }
    
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}