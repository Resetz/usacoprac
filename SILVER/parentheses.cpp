#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

string s;
int n;
int find() {
    vector<int> depth(n);
    vector<int> closed(n);
    for (int i = 0 ; i < n ; i++) {
        depth[i] = depth[i-1];
        closed[i] = closed[i-1];
        if (s[i] == '(') {
            depth[i]++;
        } else {
            closed[i]++;
            depth[i]--;
        }
        if (depth[i] == -1) {
            return closed[i];
        }
    }
    return 0;
    //return closed[n-1];
}

int main() {
    cin >> s;
    n = s.size();

    int wow = find();
    if (wow == 0) {
        reverse(s.begin(), s.end());
        for (int i = 0; i < n ;  i++) {
            if (s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
        wow = find();
        if (wow == 0) {
            cout << 0 << endl;
        } else {
            cout << wow << endl;
        }
    } else {
        cout << wow << endl;
    }
}