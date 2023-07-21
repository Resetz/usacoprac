#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
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
     int n, m;
    cin >> n >> m;

    vector<vector<double>> v(n, vector<double>(n, 0));

    vector<pair<double,double>> p(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            v[i][j] = v[j][i] = sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first) + (p[i].second-p[j].second)*(p[i].second-p[j].second));
        }
    }

    priority_queue<pair<double,int>, vector<pair<double,int>>, Compare> pq;

    vector<bool> done(n, false);
    int finished = 0;

    for (int i = 0 ; i < m ; i++) {
        int f,t;
        cin >> f >> t;
        f--;t--;
        v[f][t] = 0;
        v[t][f] = 0;
    }

    pq.push(pair<double,int>{0, 0});
    double ans = 0;
    while (!pq.empty()) {
        pair<double,int> t = pq.top();
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
            if (i == t.second) continue;
            pq.push(pair<double,int>{v[t.second][i], i});
        }
    }
   // cout << finished << " " << endl;
    cout << fixed << setprecision(2) << ans << endl;
}