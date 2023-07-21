#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int main() {

   // #ifndef DLOCAL

    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);

    //#endif


    int n;
    cin >> n;

    unordered_map<int,int> mp;
    map<set<int>,int> m;
    set<set<int>> sets;
    for (int i = 0 ; i < n ; i++) {
        vector<int> v(5);
        for (int j = 0 ; j < 5 ; j++) {
            cin >> v[j];
        }
        for (int j = 1 ; j < 32 ; j++) {
            set<int> s;
            int count = 0;
            //vector<int> cur;
            for (int k = 0 ; k < 5 ; k++) {
                if ((j >> k) & 1) {
                    s.insert(v[k]); 
                    //db += itoa(v[k]); 
                    //cur.push_back(v[k]);
                    //db += " ";
                    count++;
                }
            } 
            if (++m[s] == 2) {
                sets.insert(s);
            }
        }
    }
    long long ans = (n) * (n-1) / 2;
    for (set<int> set : sets) {
        ans -= ((set.size()%2) * 2 - 1) * ((m[set]) * (m[set]-1) / 2);
    }
    cout << ans << endl;
}