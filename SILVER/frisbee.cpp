#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<pair<int,int>> s;

    vector<int> v(n);
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
    }
    unsigned long long ans = 0;
    for (int i = 0 ; i < n ; i++) {

        while (!s.empty()) {
            if (v[i] > s.top().first) {
                ans += i - s.top().second + 1;
                s.pop();
            } else {
                break;
            }
        }
        if (s.size() != 0) {
            ans += i - s.top().second + 1;
        }
        s.push({v[i],i});
    }
    cout << ans << endl;
    
}