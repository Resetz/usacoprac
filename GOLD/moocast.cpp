#include <iostream>
#include <vector>
#include <algorithm>
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

    int find_size(int a) {
        return s[find_set(a)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    dsu d(n);

    vector<pair<int, pair<int,int>>> edges(n-1);
    for (int i = 0 ; i < n-1 ; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        edges[i].second.first--;
        edges[i].second.second--;
        edges[i].first = -edges[i].first;
    }
    sort(edges.begin(), edges.end());

    vector<pair<pair<int,int>,int>> queries(q);
    for (int i = 0 ; i < q ; i++) {
        cin >> queries[i].first.first >> queries[i].first.second;
        queries[i].first.second--;
        queries[i].first.first = -queries[i].first.first;
        queries[i].second = i;
    }

    sort(queries.begin(), queries.end());
    vector<int> v(q);
    int cur = 0;
    for (int i = 0 ; i < q ; i++) {
        pair<pair<int,int>,int> p = queries[i];
        while (cur < n-1 && -edges[cur].first >= -p.first.first) {

            d.union_set(edges[cur].second.first, edges[cur].second.second);

            cur++;
        }

        v[p.second] = d.find_size(p.first.second);

    }

    for (int i = 0 ; i < q ; i++) {
        cout << v[i]-1 << endl;
    }
}