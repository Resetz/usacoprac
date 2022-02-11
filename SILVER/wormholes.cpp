/*
ID: vincent97
TASK: wormhole
LANG: C++                 
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int to[12];
int from[12];

int connect[12];
int placed = 0;
int n;
bool check() {
    bool visited[12];
    
    for (int i = 0; i < n ; i++) {
        int pos = i;
        for (int j = 0 ; j < n ; j++) {
            if (pos == -1) {
                break;
            }
            pos = to[connect[pos]];
        }
        if (pos != -1) return true;
    }
    return false;
}

int ans = 0;
void solve(int placed) {
    int start = -1;
    for (int i = 0 ; i < n ; i++) {
        if (connect[i] == -1) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        if (check()) { 
            ans++;
        }
        //cout << endl;
        return;
    }

    placed++;
    for (int i = start+1 ; i < n ; i++) {
        if (connect[i] == -1) {
            connect[start] = i;
            connect[i] = start;
            solve(placed);
            connect[start] = -1;
            connect[i] = -1;
        } 
    
    }
}

int main() {

    #ifndef LOCAL
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    #endif


    cin >> n;
    vector<pair<int,int>> v(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
        connect[i] = to[i] = from[i] = -1;
    }

    
    for (int i = 0; i < n ; i++) {
        to[i] = -1;
        for (int j = 0 ; j < n ; j++) {
            if (v[i].second == v[j].second) {
                if (v[j].first > v[i].first) {
                    if (to[i] == -1 || v[j].first < v[to[i]].first) {
                        to[i] = j;
                    }
                }
            }
        }
        if (to[i] != -1) {
            from[to[i]] = i;
        }
    }

    solve(0);
    cout << ans << endl;
}