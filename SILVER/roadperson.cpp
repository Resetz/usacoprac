#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,pair<int,int>> tri;

class Compare
{
public:
    bool operator() (tri a, tri b)
    {
        return a.first > b.first;
    }
};



int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> v[i][j];
        }
    }

    priority_queue<tri, vector<tri>, Compare> pq;

    for (int i = 1 ; i < n ; i++) {
        pq.push(tri{v[0][i], {0,i}});
    }

    vector<bool> done(n, false);
    done[0] = true;
    int finished = 0;
    int ans = 0;
    while (!pq.empty()) {
        tri t = pq.top();
        pq.pop();

        if (done[t.second.second]) {
            continue;
        }
        done[t.second.second] = true;
        finished++;
        ans += t.first;
        //cout << t.second.first << " " << t.second.second << " " << t.first << endl;
        if (finished == n-1) break;
        for (int i = 0 ; i < n ; i++) {
            if (i == t.second.second) continue;
            pq.push(tri{v[t.second.second][i],{t.second.second,i}});
        }
    }
    cout << ans << endl;

}