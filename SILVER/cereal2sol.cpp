#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> curorder;
vector<pair<int,int>> cows;
vector<bool> found;
vector<bool> extra;
set<int> placed;
vector<int> arr;
vector<vector<pair<int,int>>> dir;
int n,m;
void go(int seg, int cow) {
    cout << seg << " " << cow << endl;
    if (cow != -1) {
        if (found[seg]) {
            extra.push_back(cow);
            return;
        } else {
            arr.push_back(cow);
        }
    }

    found[seg] = true;

    for (int i = 0 ; i < dir[seg].size(); i++) {
        cout << seg << " -> " << dir[seg][i].second << endl;
        if (placed.insert(dir[seg][i].second).second) go(dir[seg][i].first, dir[seg][i].second);
    }
}

int main() {
    cin >> n >> m;

    cows.resize(n);
    found.resize(m, false);
    dir.resize(m, vector<pair<int,int>>());
    for (int i = 0 ; i < n ; i++) {
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--;
        cows[i].second--;
        dir[cows[i].first].push_back({cows[i].second, cows[i].first});
        dir[cows[i].second].push_back({cows[i].first, cows[i].first});
    }
    
    int hungry = 0;
    for (int i = 0 ; i < m ; i++) {
        if (!found[i]) {
            go(i, -1);
            for (int j = 0 ; j < arr.size() ; j++) {
                curorder.push_back(arr[j]);
            }
            for (int j = 0 ; j < extra.size() ; j++) {
                curorder.push_back(extra[j]);
            }
            hungry += extra.size();
            arr.clear();
            extra.clear();
        }
    }
    cout << hungry << endl;
    for (int i = 0 ; i < curorder.size() ; i++) {
        cout << curorder[i] << endl;
    }
}