#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct {
    unsigned long long f,t;
    unsigned long long id;
} edge;

//dsu data structure 
class dsu {
    public:
    vector<unsigned long long> parent;
    vector<unsigned long long> s;
    vector<unsigned long long> m;
    unsigned long long size = 0;
    dsu(unsigned long long n) {
        parent.resize(n);
        s.resize(n, 1);
        size = n;
        m.resize(n, 0);

        for (unsigned long long i = 0 ; i < n ; i++) parent[i] = i;

    }

    unsigned long long find_set(unsigned long long a) {
        if (a == parent[a])
            return a;
        return parent[a] = find_set(parent[a]);
    }

    bool union_set(unsigned long long a, unsigned long long b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (s[a] < s[b]) {
                unsigned long long temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            s[a] += s[b];
            m[a] += m[b];
            //cout << a << " " << b << endl;
            size--;
            return true;
        }
        return false;
    }

    inline unsigned long long get_size(unsigned long long p) {
        unsigned long long se = find_set(p);
        return s[se] + 1 - m[se];
    }
};

struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("triplesofcowsin.txt", "r", stdin);

    unsigned long long n;
    cin >> n;

    vector<vector<pair<unsigned long long,unsigned long long>>> adj(n);
    vector<pair<unsigned long long,unsigned long long>> edges(n-1);
    for (unsigned long long i = 0 ; i < n-1 ; i++) {
        unsigned long long f,t; cin >> f >> t; f--; t--;
        adj[f].push_back({t,i});
        adj[t].push_back({f,i});
        edges[i] = {f,t};
    }

    dsu d(n-1);

    int c = -2;
    auto beg = high_resolution_clock::now();
    vector<unsigned long long> v(n, 0);
    for (unsigned long long i = 0 ; i < n ; i++) {
        //count
        set<pair<unsigned long long,unsigned long long>> vis;
        //auto start = high_resolution_clock::now();
        if (c != -1) {
            vector<bool> good(n, false);
            for (int j = 0 ; j < n-1 ; j++) {
                if (d.find_set(j) == c || c == -2) {
                    good[edges[j].first] = edges[j].first >= i;
                    good[edges[j].second] = edges[j].second >= i;
                    v[edges[j].first] = v[edges[j].second] = 0;
                    //b++;
                }
            }
            for (unsigned long long j = 0 ; j < n-1 ; j++) {
                
                if (edges[j].first < i && edges[j].second < i) continue;
                unsigned long long k = d.find_set(j);
                //cout << edges[jv].first << " " << edges[j].second << " " << d.find_set(j) << " " << d.get_size(j) << " (" << d.s[d.find_set(j)] << " " << d.m[d.find_set(j)] << endl;
                if (edges[j].first >= i && good[edges[j].first] && vis.insert({edges[j].first, k}).second) {
                    v[edges[j].first] += d.get_size(j)-1;
                } 
                if (edges[j].second >= i && good[edges[j].second] && vis.insert({edges[j].second, k}).second) {
                    v[edges[j].second] += d.get_size(j)-1;
                }
                
            }
        }
        //c += vis.size();
        //auto end = high_resolution_clock::now();
        //afloat += duration_cast<milliseconds>(end - start).count();
        unsigned long long ans = 0;
        //start = high_resolution_clock::now();
        for (unsigned long long j = i ; j < n ; j++) {
            //cout << j << " " << v[j] << endl;
            ans += v[j]*(v[j]-1);
        }
        //end = high_resolution_clock::now();
        //bfloat += duration_cast<milliseconds>(end - start).count();

        cout << ans << "\n";
       // cout << "b " << b << endl;

        //mergers
        unsigned long long f = adj[i][0].second;
        bool go = false;
        for (pair<unsigned long long,unsigned long long> p : adj[i]) {
            go |= d.union_set(p.second, f);
        }
        c = d.find_set(adj[i][0].second);
        d.m[d.find_set(adj[i][0].second)]++;
    }
    //cout << afloat << endl;
    //cout << bfloat << endl;
    //cout << (unsigned long long)cfloat << endl;
   // cout << c << endl;
    //cout << duration_cast<milliseconds>(end - beg).count();
}