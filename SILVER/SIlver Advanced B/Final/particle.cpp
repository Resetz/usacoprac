#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;


int n;
int visited[12] = {-1};
map<int,int> m; // for cc
vector<int> ccx; // also for cc
vector<int> ccy; // also for cc

int grid[20][20];

int ans = 0;

vector<int> group_size;
vector<int> nright;

int paired[12] = {-1};
bool check() {
    for (int i = 0; i < n ; i++) {
        //cout << i << ":" << paired[i] << " ";
    }
    //cout << endl;
    for (int i = 0 ; i < n ; i++) {
        int cur = i;
        for (int j = 0 ; j < n ; j++) {
            cur = nright[paired[cur]];
        }
        if (cur != -1) return true;
    }
    return false;
}

int find() {
    int total = 0;

    bool found = false;
    int go = 0;
    for (int i = 0; i < n ; i++) {
        if (paired[i] == -1) {
            found = true;
            go = i;
            break;
        }
    }
    //cout << endl;

    if (!found) {
        if (check()) {
            return 1;
        } else {
            return 0;
        }
    }
    for (int t = go+1 ; t < n ; t++) {
        if (paired[t] == -1) {
            paired[go] = t;
            paired[t] = go;
            total += find();
            paired[go] = paired[t] = -1;
        }
    }
    return total;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
        ccx.push_back(x);
        ccy.push_back(y);
    }
    sort(ccx.begin(), ccx.end());
    sort(ccy.begin(), ccy.end());

    // cc / coordinate compression
    int next = 0;
    for (int i = 0 ; i < ccx.size() ; i++) {
        if (m.find(ccx[i]) == m.end()) {
            m[ccx[i]] = next;
            next++;
        }
    }

    for (int i = 0 ; i < n ; i++) {
        v[i].first = m[v[i].first];
    }

    m.clear();

    next = 0;
    for (int i = 0 ; i < ccy.size() ; i++) {
        if (m.find(ccy[i]) == m.end()) {
            m[ccy[i]] = next;
            next++;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        v[i].second = m[v[i].second];
    }

    for (int i = 0 ; i < 12; i++) {
        for (int j = 0 ; j < 12 ; j++) {
            grid[i][j] = -1;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        grid[v[i].first][v[i].second] = i;
        //cout << v[i].first << " " << v[i].second << endl;
    }
    for (int i = 0 ; i < 12; i++) {
        for (int j = 0 ; j < 12 ; j++) {
            //cout << grid[i][j] << " ";
        }
        //cout << endl;
    }
    
    nright.resize(n, -1);
    //cout << grid[0][1] << endl;
    for (int i = 0 ; i < n ; i++) {
        int go = 1;
        //cout << v[i].first << " " << v[i].second << endl;
        while (v[i].first - go >= 0) {
            if (grid[v[i].first - go][v[i].second] != -1){
                nright[i] = grid[v[i].first - go][v[i].second];
            }
            go++;
        }
        //cout << nright[i] << endl;
    }

    for (int i = 0 ; i < n ; i++) {
        paired[i] = -1;
    }

    cout << find() << endl;
}