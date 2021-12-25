#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define ull unsigned long long

using namespace std;
vector<vector<ull>> adj;

bool visited[100000];
vector<int> tagged;
ull from, to;
ull n, m;
void dfs(ull num, ull field) {
    if (visited[num]) return;
    visited[num] = true;
    tagged[num] = field;
    if (num == 0) {
        from = field;
    } else if (num == n-1) {
        to = field;
    }
    for (ull i = 0 ; i < adj[num].size() ; i++) {
        dfs(adj[num][i], field);
    }   
}

ull check(vector<ull> &a, vector<ull> &b) {
    ull i, r;
    ull ret = 0xffffffffffffffff;
    r = 0;
    for (i = 0 ; i < a.size(); i++) {
        //cout << "check " << i << " " << r << " " << a.size() << endl;
        int temp = b[r];
        while(r < b.size() && b[r] < a[i]) {
            r++;
        }
        ret = min(ret,(b[r] - a[i])*(b[r] - a[i]));
        ret = min(ret,(temp - a[i])*(temp-a[i]));
    }
    //cout << "return " << ret << endl << endl;
    return ret;
}

void solve() {
    cin >> n >> m;
    adj.clear();
    tagged.clear();
    tagged.resize(n);

    for (ull i = 0; i < n ; i++) {
        visited[i] = false;
    }

    adj.resize(n);
    for (ull i = 0; i < m; i++) {
        ull f, t;
        cin >> f >> t;
        f--;
        t--;
        //cout << "road: " << f << " " << t << endl;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    ull blobnum = 0;
    for (ull i = 0 ; i < n ; i++) {
        if (!visited[i]) {
            dfs(i, blobnum);
            blobnum++;
        }
    }
    //cout << from << " " << to << endl;

    //cout << "- " << endl;
    unsigned long long lasta = -1;
    unsigned long long lastb = -1;

    unsigned long long ansa = INT_MAX;
    unsigned long long ansb = INT_MAX;
    for (int i = 0 ; i < n ; i++) {
        if (tagged[i] == from) {
            lasta = i;
        } else if (tagged[i] == to) {
            lastb = i;
        } else {
            if (lasta != -1) {
                ansa = min(ansa, i - lasta);
            } 
            if (lastb != -1) {
                ansb = min(ansb, i - lastb);
            }
        }
    }

    lasta = -1;
    lastb = -1;
    for (int i = n-1 ; i >= 0 ; i--) {
        if (tagged[i] == from) {
            lasta = i;
        } else if (tagged[i] == to) {
            lastb = i;
        } else {
            if (lasta != -1) {
                ansa = min(ansa, lasta - i);
            } 
            if (lastb != -1) {
                ansb = min(ansb, lastb - i);
            }
        }
    }
    int last = -1;
    ull lastpos;
    ull ansdir = INT_MAX;
    for (int i = 0 ; i < n ; i++) {
        if (tagged[i] == from || tagged[i] == to) {
            if (last != -1 && ((last == from && tagged[i] == to) || (last == to && tagged[i] == from))) {
                ansdir = min(i - lastpos, ansdir);
            }
            last = tagged[i];
            lastpos = i;
        }
    }
    unsigned long long ans = ansa * ansa + ansb * ansb;
    cout << min(ans, ansdir*ansdir) << endl;
    
}

int main() {
    ull n;

    cin >> n;
    while (n--) solve();

}