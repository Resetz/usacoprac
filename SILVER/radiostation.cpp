#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
long n, k;

#define d(x,y) ((2019201913*(min(x,y)+1) + 2019201949*(max(x,y)+1)) % 2019201997)
class Compare
{
public:
    bool operator() (pair<long long,long> a, pair<long long,long> b)
    {
        return a.first > b.first;
    }
};
long prims() {
    vector<long> v;

    priority_queue<pair<long,long>, vector<pair<long,long>>, Compare> pq;
    pq.push({0,0});
    vector<long> visited(n, false);
    vector<long> current(n, LONG_MAX);
    current[0] = 0;
    while (!pq.empty()) {
        pair<long,long> p = pq.top();
        pq.pop();
        if (visited[p.second]) continue;
        visited[p.second] = true;
        v.push_back(p.first);
        for (long i = 0 ; i < n ; i++) {
            if (i == p.second || visited[i] || d(i,p.second) > current[i]) continue;
            pq.push({d(i,p.second), i});
            current[i] = d(i,p.second);
        }
    }

    sort(v.begin(), v.end());
    //for (long i = 0; i < v.size(); i++) cout << v[i] << " ";
   // cout << endl;
    return v[n-k+1];
}

int main() {
    cin >> n >> k;

    cout << prims() << endl;
}