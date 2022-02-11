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
    if (from == to) {
        cout << 0 << endl;
        return;
    }
    //cout << from << " " << to << endl;

    //cout << "- " << endl;

    vector<int> adist(n, INT32_MAX);
    vector<int> bdist(n, INT32_MAX);

    int l, r;

    int firsta, firstb;
    firsta = firstb = 0;

    vector<ull> a;
    vector<ull> b;
    for (int i = 0 ; i < n ; i++) {
        if (tagged[i] == from) a.push_back(i);
        else if (tagged[i] == to) b.push_back(i);
    }
    a.push_back(-1);
    b.push_back(-1);

    l = -1;
    r = a[0];
    int next = 1;
    for (int i = 0 ; i < n ; i++) {
        if (i == r) {
            l = r;
            r = a[next];
            next++;
            continue;
        }
        if (tagged[i] != from && tagged[i] != to) {
            int d1, d2;
            d1 = abs(r - i);
            d2 = abs(i - l);
            if (r == -1) {
                d1 = INT32_MAX;
            }
            if (l == -1) {
                d2 = INT32_MAX;
            }
            adist[tagged[i]] = min(adist[tagged[i]], min(d1, d2));
        }
    }
    
    l = -1;
    r = b[0];
    next = 1;
    for (int i = 0 ; i < n ; i ++) {
        if (i == r) {
            l = r;
            r = b[next];
            next++;
            continue;
        }
        if (tagged[i] != from && tagged[i] != to) {
            int d1, d2;
            d1 = abs(r - i);
            d2 = abs(i - l);
            if (r == -1) {
                d1 = INT32_MAX;
            }
            if (l == -1) {
                d2 = INT32_MAX;
            }
            bdist[tagged[i]] = min(bdist[tagged[i]], min(d1, d2));
        }
    }

    ull bestinter = INT64_MAX;
    for (int i = 0 ; i < blobnum ; i++) {
        if (i != from && i != to) {
            bestinter = min(bestinter, (ull)adist[i]*adist[i] + (ull)bdist[i]*bdist[i]);
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
    cout << min(bestinter, ansdir*ansdir) << endl;
}

int main() {



    ull n;

    cin >> n;
    while (n--) solve();

}
