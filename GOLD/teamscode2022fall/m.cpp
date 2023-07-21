#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class dsu {
    public:
    vector<int> parent;
    vector<int> s;
    vector<int> m;
    int size = 0;
    dsu(int n) {
        parent.resize(n);
        s.resize(n, 1);
        m.resize(n, 1);
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
            m[a] = min(m[a], m[b]);
            size--;
        }
    }

    int find_size(int a) {
        return s[find_set(a)];
    }
};

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    priority_queue<pair<int,pair<int,int>>> p;
    for (int i = 0 ; i < m ; i++) {
        int f,t,l;
        cin >> f >> t >> l;
        l--;
    }
}