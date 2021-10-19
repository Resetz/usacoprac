#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int main() {
    int a, b, c;
 
    cin >> a >> b >> c;
    vector<int> u, p;
    vector< pair<int,int> > bo;
    int n;
    cin >> n;
 
    for (int i = 0; i < n ; i++) {
        int cost = 0; cin >> cost;
        string type;
        cin >> type;
        if (type == "USB") {
            u.push_back(cost);
        } else {
            p.push_back(cost);
        } 
        bo.push_back(make_pair(cost, type == "USB" ? 1 : 0));
    }
 
    sort(u.begin(), u.end());
    sort(p.begin(), p.end());
    sort(bo.begin(), bo.end());
 
    int ans = 0;
    long long tot = 0;
 
    int useda = 0;
    int usedb = 0;
    while (useda != u.size() && a > 0) {
        tot += u[useda];
        ans++;
        a--;
        useda++;
    }
 
    while (usedb != p.size() && b > 0) {
        tot += p[usedb];
        ans++;
        b--;
        usedb++;
    }
 
    int counter = 0;
    while (counter != bo.size() && (c > 0 || b > 0 || a > 0)) {
        pair<int, int> f = bo[counter];
        counter++;
        if (f.second == 1 && useda > 0) {
            useda--;
            continue;
        } else if (f.second == 0 && usedb > 0) {
            usedb--;
            continue;
        } else {
            if (c > 0) {
                ans++;
                tot += f.first;
                c--;
            } else if ((f.second == 1 && a > 0) || (f.second == 0 && b > 0)) {
                f.second == 1 ? a-- : b--;
                ans++;
                tot += f.first;
            }
            
        }
    }
    cout << ans << " " << tot;
 
}