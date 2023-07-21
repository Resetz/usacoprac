#include <iostream>
#include <vector>
//#include <iomanip>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

class Compare
{
public:
    bool operator() (pair<double,int> a, pair<double,int> b)
    {
        return a.first > b.first;
    }
};

int main() {
    long long n, m;
    cin >> n >> m;

    vector<vector<long long>> v(n, vector<long long>(n, 0));

    vector<pair<long long,long long>> p(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            long long k = (p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second);
            //cout << "k = " << k << endl;
            if ( k < m ) k = -1;
            v[i][j] = v[j][i] = k;
        }
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, Compare> pq;

    vector<bool> done(n, false);
    int finished = 0;
    pq.push(pair<long long,int>{0, 0});
    
    vector<long long> current(n, LLONG_MAX);
    long long ans = 0;

    while (!pq.empty()) {
        pair<long long,int> t = pq.top();
        pq.pop();

        if (done[t.second]) {
            continue;
        }
        done[t.second] = true;
        finished++;
        ans += t.first;
        //cout << t.second << " " << t.first << endl;
        if (finished == n) break;
        for (int i = 0 ; i < n ; i++) {
            if (v[t.second][i] == -1) continue;
            if (!done[i]) {
                if (v[t.second][i] < current[i]) {
                    pq.push(pair<long long,int>{v[t.second][i], i});
                    current[i] = v[t.second][i];
                }
            }
        }
    }
// cout << finished << " " << endl;
    if (finished != n) ans = -1;
    cout << ans << endl;
}