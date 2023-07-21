#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

int n;
vector<pair<int,int>> v;
int go(int k) {
    dsu d = dsu(n);
    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            int x = v[i].first - v[j].first;
            int y = v[i].second - v[j].second;
            if (x*x+y*y <= k) {
                d.union_set(i,j);
            }
        }
    }
    //cout << k << " " << d.find_size(0) << endl;
    return d.find_size(0) == n;
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int low = 0;
    int high = INT_MAX;
    int ans = 0;
    while (high >= low) {
        int mid = low + (high - low) / 2;
        if (go(mid)) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}