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
    int tot = 0;

    int useda = 0;
    int usedb = 0;
    while (u.size() > 0 && a > 0) {
        tot += u[useda];
        ans++;
        a--;
        useda++;
    }

    while (p.size() > 0 && b > 0) {
        tot += p[usedb];
        ans++;
        b--;
        usedb++;
    }

    int counter = 0;
    while (bo.size() > 0 && c > 0) {
        pair<int, int> f = bo[counter];
        if (f.second == 1 && useda > 0) {
            useda--;
            continue;
        } else if (f.second == 0 && usedb > 0) {
            usedb--;
            continue;
        } else {
            ans++;
            tot += f.first;
        }
        counter++;
    }

}