#include <iostream>
#include <vector>
#include <set>

using namespace std;

//dsu data structure 
class dsu {
    public:
    vector<int> parent;
    vector<int> s;
    int size = 0;
    dsu(int n) {
        parent.resize(n);
        s.resize(n, 1);
        size = n;
        for (int i = 0 ; i < n ; i++) parent[i] = i;
    }

    int find_set(int a) {
        if (a == parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (s[a] < s[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            s[a] += s[b];
            //cout << a << " " << b << endl;
            size--;
        }
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    dsu d(n);

    vector<vector<int>> v(n);
    vector<pair<int,int>> p(m);
    for (int i = 0 ; i < m ; i++) {
        /*
        int f,t;
        cin >> f >> t;
        f--;t--;
        v[f].push_back(t);
        v[t].push_back(f);
        */
        cin >> p[i].first >> p[i].second;
        p[i].first--; p[i].second--;
    }

    vector<int> o(n);
    vector<int> t(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> o[i];
        o[i]--;
        t[o[i]] = i;
    }

    for (int i = 0 ; i < m ; i++) {
        if (t[p[i].first] > t[p[i].second]) {
            v[p[i].second].push_back(p[i].first);
        } else {
            v[p[i].first].push_back(p[i].second);
        }
    }

    vector<bool> ans(n);
    int k = 0;
    for (int i = n-1; i >= 0 ; i--) {
        k++;
        for (int j = 0 ; j < v[o[i]].size() ; j++) {
            if (d.find_set(o[i]) != d.find_set(v[o[i]][j])) {
                d.union_set(o[i], v[o[i]][j]);
                k--;    
            }
        }
        ans[i] = k <= 1;
    }
    for (int i = 0 ; i < n ; i++) {
        if (ans[i]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}