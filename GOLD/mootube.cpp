#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

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

    int find_size(int a) {
        return s[find_set(a)];
    }
};

int main() {

    #ifndef DLOCAL

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    #endif


    int n, q;
    cin >> n >> q;
    vector<pair<long long,pair<int,int>>> edges(n-1);
    for (int i = 0 ; i < n-1 ; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        edges[i].second.first--;
        edges[i].second.second--;
        edges[i].first *= -1;
    }

    sort(edges.begin(), edges.end());

    vector<pair<long long,pair<int,int>>> qs(q);
    for (int i = 0 ; i < q ; i++) {
        cin >> qs[i].first >> qs[i].second.first;
        qs[i].second.first--;
        qs[i].second.second = i;
        qs[i].first *= -1;
    }
    
    sort(qs.begin(), qs.end());

    dsu d(n);
    int cur = 0;
    vector<int> ans(q);
    for (int i = 0 ; i < q; i++) {
        while (cur < n && edges[cur].first <= qs[i].first) {
            d.union_set(edges[cur].second.first, edges[cur].second.second);
            cur++;
        }
        //out << qs[i].first << qs[i].second.first << qs[i].second.second << endl;
        ans[qs[i].second.second] = d.find_size(qs[i].second.first)-1;
    }
    for (int i = 0 ; i < q ; i++) {
        cout << ans[i] << endl;
    }
}