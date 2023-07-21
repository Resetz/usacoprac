#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    #define int long long
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>lights(n);
    vector<pair<int,int>> people(m);
    for (int i=0; i<n; i++) cin >> lights[i].first >> lights[i].second;
    for (int i=0; i<m; i++) {
        cin >> people[i].first;
        people[i].second = i;
    }
    lights.push_back({LLONG_MIN/2,0});

    vector<pair<int,int>> v;

    sort(lights.begin(),lights.end(), [](pair<int,int> p1, pair<int,int> p2) -> bool {
        return p1.first-p1.second < p2.first-p2.second;
    });
    
    vector<int> ans(m);
    sort(people.begin(), people.end());
    int ind = 0;
    int nxt = ind+1;
    for (int i = 0 ; i < m ;i++) {
        while (nxt <= n) {
            if (lights[ind].first-lights[ind].second < lights[nxt].first - lights[nxt].second && lights[ind].first+lights[ind].second > lights[nxt].first+lights[nxt].second) {
                nxt++;
                //cout << ind << " a " << endl;
            } else if (lights[ind].second-abs(lights[ind].first-people[i].first) < lights[nxt].second-abs(lights[nxt].first-people[i].first))
            {
                ind = nxt;
                nxt = ind+1;
               // cout << ind << " b " << endl;
            } else {
                break;
            }
        }
        //cout << ind << " " << lights[ind].second-abs(lights[ind].first-people[i].first) << " " << lights[ind].first << " " << lights[ind].second << endl;
        ans[people[i].second] = lights[ind].second-abs(lights[ind].first-people[i].first);
    }
    for (int i = 0 ; i < m ; i++) {
        if (ans[i] < 0) {
            ans[i] = 0;
        }
        cout << ans[i] << endl;
    }
}