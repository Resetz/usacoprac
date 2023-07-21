#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int n;
int d;
vector<vector<pair<int,int>>> pies;
vector<int> ind;
struct comp {
    bool operator()(int a, int b) {
        return pies[0][a] < pies[0][b];
    }
    bool operator()(int a, int b) {
        return pies[1][a] < pies[1][b];
    }
};

int main() {
    cin >> n >> d;
    pies.resize(n);

    for (int i = 0; i < n * 2 ; i++) {
        if ( i < n ) {
            cin >> pies[i].first >> pies[i].second;
        } else {
            cin >> pies[i].second >> pies[i].first;
        }
    }
    vector<int, > ms(2);
    for (int i = 0 ; i < n ; i++) {
        ms[0].insert({pies[i], i});
        ms[1].insert({pies[i+n], i});
    }

    queue<pair<int,int>> q;
    for (int i = 0 ; i < n ; i++) {
        if (pies[i].first == 0) {
            q.push(pair<int,int>{i, 0});
            ms.erase(pair<pair<int,int>,int>{pies[i], i});
        }
    }
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        mu
    }
    /*
    vector<vector<pair<int,int>>> pies(2, vector<pair<int,int>>(n));
    for (int i = 0; i < n ; i++) {
        cin >> pies[0][i].first >> pies[0][i].second;
    }
    for (int i = 0; i < n ; i++) {
        cin >>pies[1][i].second >> pies[1][i].first;
    }


    vector<multiset<pair<pair<int,int>,int>>> ms(2);
    for (int i = 0 ; i < n ; i++) {
        ms[0].insert({pies[0][i], i});
    }
    for (int i = 0 ; i < n ; i++) {
        ms[1].insert({pies[1][i], i});
    }   

    queue<pair<pair<int,int>,pair<int,int>>> q;
    while (!q.empty()) {
        pair<pair<int,int>,pair<int,int>> p = q.front();
        q.pop();
        pair<int,int> c = pies[(p.second.second+1)%2][p.first]
        multiset<pair<pair<int,int>,int>> s = ms[(p.second.second+1)%2];
        while (lower_bound(s.begin(), s.end(), pair<pair<int,int>,int>{pair<int,int>{p.first.first,0}, 0}) != s.end()) {
            pair<pair<int,int>,int> go = *lower_bound(s.begin(), s.end(), p.first.first);
            if (go.first.first > p.second.first) {
                break;
            }
            s.erase(lower_bound(s.begin(), s.end(), p.first.first));
            q.push({{go.second, }, pair<int,int>{p.first.second, (p.second.second+1)%2}});
        }
    }*/
}