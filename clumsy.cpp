#include <iostream>
#include <algorithm>

using namespace std;

int main() { 
    string s;
    cin >> s;
    int n = s.size();


    int totalleft = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        bool left = s[i] == '(';

        if (left) {
            totalleft++;
        } else {
            totalleft--;
            if (totalleft == -1) {
                totalleft = 1;
                ans++;
            }
        }
    }
    ans += totalleft / 2;
    cout << ans << endl;
}