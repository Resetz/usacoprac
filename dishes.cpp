#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    vector<pair<int,stack<int>>> s(1, {v[0], stack<int>()});
    s[s.size()-1].second.push(v[0]);
    int i = 1;
    int popped = 0;
    for (; i < n ; i++) {
        //bsearch over s;
        if (v[i] < popped) {
            break;
        }
        int high = s.size()-1;
        int low = 0;
        int cur = -1;

        while (high >= low) {
            int ind = low + (high - low) / 2;
            if (s[ind].first > v[i]) {
                if (ind-1 == 0 || s[ind-1].first < v[i]) {
                    while (!s[ind].second.empty() && s[ind].second.top() < v[i]) {
                        popped = s[ind].second.top();
                        s[ind].second.pop();
                    }
                    s[ind].second.push(v[i]);
                    cur = 0;
                    break;
                }
                high = ind-1;
            } else {
                low = ind+1;
            }
        }
        if (cur == -1) {
            s.push_back({v[i],stack<int>()});
            s[s.size()-1].second.push(v[i]);
        };
    }
    cout << i << endl;
}