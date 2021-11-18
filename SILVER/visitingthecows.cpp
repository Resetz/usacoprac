#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> rev;

unsigned long long  n, m, k, p;

vector<int> cows;

int visited[100000];
int found[100][100000];

int fj[100000];
int dist[100000] = {-1};

bool good = true;

void dfs(int t) {
    bool v[100000] = {false};

    bool reachedfj = false;
    queue<pair<int,int>> s;
    s.push({cows[t],0});

    while (!s.empty()) {
        pair<int,int> num = s.front();
        //cout << num.first << endl;
        s.pop();
        if (v[num.first]) continue;
        v[num.first] = true;

        if (num.first == 0) reachedfj = true;
        found[t][num.first] = num.second;
        visited[num.first]++;
        for (int i = 0 ; i < adj[num.first].size() ; i++) {
            s.push({adj[num.first][i], num.second+1});
            
        }
    }
    good = reachedfj;
}
void dfj() { //depth farmer john
    bool v[100000] = {false};
    
    queue<pair<int,int>> s;
    s.push({0,0});

    while (!s.empty()) {
        pair<int,int> num = s.front();
        s.pop();
        if (v[num.first]) continue;
        v[num.first] = true;
        
        fj[num.first] = num.second;
        for (int i = 0 ; i < adj[num.first].size() ; i++) {
            s.push({adj[num.first][i], num.second+1});
        }
    }
}

void reverse() {
    bool v[100000] = {false};
    
    queue<pair<int,int>> s;
    s.push({0,0});

    while (!s.empty()) {
        pair<int,int> num = s.front();

        s.pop();
        if (v[num.first]) continue;
        v[num.first] = true;
        dist[num.first] = num.second;
        for (int i = 0 ; i < rev[num.first].size() ; i++) {
            s.push({rev[num.first][i], num.second+1});
        }
    }
}

int main() {
    cin >> n >> m >> k >> p;

    cows.resize(k);
    for (int i = 0 ; i < k ; i++) {
        cin >> cows[i];
        cows[i]--;
    }

    adj.resize(n);
    rev.resize(n);
    for (int i = 0 ; i < m ; i++) {
        int f, t;
        cin >> f >> t;
        f--;
        t--;
        adj[f].push_back(t);
        rev[t].push_back(f);
    }

    for (int i = 0 ; i < k ; i++) {
        dfs(i);
        //cout << endl;
        if (!good) {
            cout << "Impossible";
            return 0;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        dist[i] = -1;
    }
    reverse();
    dfj();

    unsigned long long ans = 0xffffffffffffffff;
    bool wow = false;

    for (int i = 1 ; i < n ; i++) {
        //cout << visited[i] << " ";
        if (visited[i] == k && dist[i] != -1) {
            wow = true;
            unsigned long long sum = 0;
            for (int j = 0 ; j < k ; j++) {
                sum += found[j][i];
            }
            //cout << fj[i] + y << endl;
            sum += p * (fj[i] + dist[i]);
            //if (sum < ans) cout << i+1 << endl;
            ans = min(sum, ans);
        }
    }
    //cout << endl;
    if (!wow) {
        cout << "Impossible" << endl;
    }
    cout << ans << endl;
    


}