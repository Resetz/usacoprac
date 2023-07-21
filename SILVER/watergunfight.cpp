#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<unsigned long long,unsigned long long>> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    vector<unsigned long long> ans(n, 0);

    stack<pair<unsigned long long, unsigned long long>> heights;
    stack<unsigned long long> toadd;
    heights.push({0, v[0].first});
    for (int i = 1 ; i < n ; i++) {
        //cout << "what" << endl;
        while (heights.size() > 0 && heights.top().second < v[i].first) {
            heights.pop();
        }
        if (heights.size() > 0) {
            ans[heights.top().first] += v[i].second;
            //cout << heights.top().first << " " << v[i].second << " " << ans[heights.top().first] << endl;

        }
        heights.push({i,v[i].first});
    }

    reverse(v.begin(), v.end());

    while (heights.size() > 0) heights.pop();
    heights.push({0,v[0].first});

    for (int i = 1 ; i < n ; i++) {

        while (heights.size() > 0 && heights.top().second < v[i].first) {
            heights.pop();
        }
        if (heights.size() > 0) {
            ans[n-1-heights.top().first] += v[i].second;
            //cout << n-1-heights.top().first << " " << v[i].second << " " << ans[heights.top().first] << endl;
        }
        heights.push({i, v[i].first});
    }

    unsigned long long yes = 0;
    for (int i = 0 ; i < n ; i++) {
        yes = max(yes, ans[i]);
    }
    cout << yes << endl;
}