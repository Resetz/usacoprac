#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long n, m;
    cin >> n >> m;

    vector<unsigned long long> anse(2*m+1, 0);
    vector<unsigned long long> ansb(2*m+1, 0);

    vector<pair<unsigned long long,unsigned long long>> intervals(n);
    vector<unsigned long long> total_begin(m+1, 0);
    vector<unsigned long long> total_end(m+1, 0);
    for (int i = 0 ; i < n ; i++) {
        unsigned long long f, t;
        cin >> f >> t;
        intervals[i] = {f,t};
        total_begin[f]++;
        total_end[t]++;
    }

    for (int i = 0 ; i <= m ; i++) {
        for (int j = 0 ; j <= m ; j++) {
            ansb[i+j] += total_begin[i] * total_begin[j]; 
        }
    }
    for (int i = 0 ; i <= m ; i ++) {
        for (int j = 0 ; j <= m ; j++) {
            anse[i+j] += total_end[i] * total_end[j];
        }
    }
    unsigned long long cur = 0;
    for (int i = 0 ; i <= 2*m ; i++) {
        cur += ansb[i];
        cout << cur << endl;
        cur -= anse[i];
    }
}