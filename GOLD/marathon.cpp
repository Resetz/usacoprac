#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t;
    vector<int> d;

    for (int i = 0 ; i < n ; i++) {
        char c;
        int num;
        cin >> c >> num;
        if (c == 'T') {
            t.push_back(num);
        } else {
            d.push_back(num);
        }
    }

    sort(t.begin(), t.end());
    sort(d.begin(), d.end());

    t.push_back(INT_MAX);
    d.push_back(INT_MAX);

    int curt;
    int curd;
    curt = curd = 0;
    int left = 1000;
    int walked = 0;
    int time = 0;

    while (curt < t.size() || curd < d.size()) {
        int s = curt + curd + 1;
        if (curd < d.size() && (d[curd] - walked) <= t[curt]) {
            time += (d[curd] - walked);
            walked += 
        } else {

        }
    }
}