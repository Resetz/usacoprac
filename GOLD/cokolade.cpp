#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <chrono>
using namespace std::chrono;

using namespace std;

int n;
vector<int> v;



int main() {


    cin >> n;
    int maxn = 0;
    v.resize(n);
    set<int> s;
    vector<int> d;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
        maxn = max(maxn, v[i]);

        int p = 1;
        while(v[i] / p != 0){
            int cur = v[i] / p;
            int next = v[i] / cur + 1;
			if (s.insert(next).second) d.push_back(next);
			p = next;
		}
    }
    d.push_back(1);
    d.push_back(maxn+1);

    auto start = high_resolution_clock::now();
    sort(d.begin(), d.end());
    sort(v.begin(), v.end());
    cout << d.size() <<  " " << s.size() << endl;
    vector<int> ans(n, INT_MAX);
    for (int i = 0 ; i < d.size() ; i++) {
        //cout << d[i] << endl;
        int last = 0;
        int amt = 0;
        for (int j = 0 ; j < n ; j++) {
            if (v[j] / d[i] == last) {
                amt++;
            } else {
                ans[amt] = min(ans[amt], d[i]);
                amt = 1;
                last = v[j]/d[i];
            }
        }
        ans[amt] = min(ans[amt],d[i]);
    }
    auto end = high_resolution_clock::now();

    //cout << " " << endl;
    for (int i = 0 ; i < n ; i++) {
        cout << (ans[i] == INT_MAX ? -1 : ans[i]) << endl;
    }
    auto duration = duration_cast<milliseconds>(end - start);
    cout << duration.count() << " ms" << endl;
}