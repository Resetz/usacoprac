
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <numeric>

using namespace std;

int main() {
    vector<double> t;
    vector<double> d;

    int n; cin >> n;

    for (int i = 0 ; i < n ; i++) {
        char c;
        double v;
        cin >> c >> v;
        if (c == 'D') {
            if (v >= 1000) continue;
            d.push_back(v);
        } else {
            t.push_back(v);
        }
    }

    d.push_back(numeric_limits<double>::max());
    sort(d.begin(), d.end());
    t.push_back(numeric_limits<double>::max());
    sort(t.begin(), t.end());
    int curd;
    int curt;
    curd = curt = 0;
    double curtime = 0;
    double curdist = 0;
    double sp = 0;
    


   // cout << "here" << endl;
    while (curd < d.size()-1 || curt < t.size()-1) {
        //determine which comes first
        sp = curd+curt+1;
        if ((curd < d.size()-1 && (d[curd] - curdist) * sp + curtime < t[curt])) {
            //cout << "curtime += " << (d[curd] - curdist) * sp << endl;
            curtime += (d[curd] - curdist) * sp;
            curdist = d[curd];
            curd++;
        } else {
            if ((1000.0f - curdist) * sp + curtime < t[curt]) {
                cout << (long long)((1000.0f - curdist) * sp + curtime + 0.5f) << endl;
                return 0;
            }
            curdist += (t[curt] - curtime)/sp;
            curtime = t[curt];
            curt++; 
        }
        //cout << curd << " " << curt << ": " << curtime << " " << curdist << " " << sp << endl;
    }
    sp = curd+curt+1;
    //cout << curdist << endl;
    cout << (long long)((1000.0f - curdist) * sp + curtime + 0.5f) << endl;
}