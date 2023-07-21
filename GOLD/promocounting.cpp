#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void add(vector<long long> &b, int at, int val) {
    while ( at < b.size() ) {
        b[at] += val;
        //cout << at << " +" << val << endl;
        at += at & (-at);
    }
}

long long query(vector<long long> &b, int f) {
    long long total = 0;
    while (f > 0) {

        total += b[f];

        f -= f & (-f);
    }
    return total;
}


vector<long long> bi;
vector<int> val;
vector<vector<int>> adj;
int n;
vector<int> ans;
vector<int> ie;
vector<int> ip;
int last = 0;
int t = 0;
void euler(int k) {
    t++;
    //cout << k+1;
    ip[k] = t;
    for (int i = 0 ; i < adj[k].size() ; i++) {
        euler(adj[k][i]);
    }
    ie[k] = t;
}

//Codeforces post : https://codeforces.com/blog/entry/84164?#comment-716952
template<typename T>
void compress(vector<T> &a)
{
    vector<pair<T, int> > M;
    for (int i = 0; i < a.size(); ++i)
        M.emplace_back(a[i], i);
    sort(M.begin(), M.end());

    a[M[0].second] = 0; /// Assign first value with zero
    for(int i = 1; i < a.size(); ++i) /// Iterate the rest and increase when adj are different
        a[M[i].second] = a[M[i - 1].second] + (M[i - 1].first != M[i].first); 
}

int main() {
    cin >> n;
    bi.resize(n+1);
    vector<pair<int,int>> v(n);
    val.resize(n);
    adj.resize(n, vector<int>());
    ie.resize(n);
    ip.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        val[i] = v[i].first;
    }

    for (int i = 1; i < n ; i++) {
        int f;
        cin >> f;
        f--;
        adj[f].push_back(i);
    }

    compress(val);
    ans.resize(n);
    //cout << "compressed" << endl;
    euler(0);
    //cout << endl;

    sort(v.rbegin(), v.rend());

    for (int i =0  ; i < n ; i++) {
        //cout << v[i].second << " -> " << ip[v[i].second] << " " << ie[v[i].second] << endl;
        ans[v[i].second] = query(bi, ie[v[i].second]) - query(bi, ip[v[i].second]);
        add(bi, ip[v[i].second], 1);
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << endl;
    }

    

}