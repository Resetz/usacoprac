#include <iostream>
#include <vector>

using namespace std;

int main () {
    vector<int> prev(5,0);
    vector<int> next(5,0);

    prev[0] = 1; // him

    for (int i = 0 ; i < 8; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            for (int k = 0 ; k < 5 ; k++) {
                if (k == j) continue;
                next[k] += prev[j]; 
            }
        }

        prev = next;
        for (int j = 0 ; j < 5 ; j++) {
            cout << next[j] << " ";
            next[j] = 0;
        }
        cout << endl;
    }

    cout << prev[0] << endl;
}