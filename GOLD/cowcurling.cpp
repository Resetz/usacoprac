#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <stack>
#include <math.h>
#include <cassert>
#define _USE_MATH_DEFINES

using namespace std;

long long turn(pair<int,int> a, pair<int,int> b,  pair<int,int> c) {
    pair<int,int> A = {b.first - a.first, b.second - a.second};
    pair<int,int> B = {c.first - b.first, c.second - b.second};
    return (A.first * B.second) - (A.second * B.first);
}

ostream& operator<<(ostream& o, pair<int,int> a) {
    return o << "(" << a.first << ", " << a.second << ")";
}

vector<pair<int,int>> convex(vector<pair<int,int>> V) {
    int n = V.size();
    vector<pair<int,int>> v(V.size());

    int ind = 0;
    pair<int,int> lowest = V[0];
    for (int i = 0; i < n; i++) {
        v[i] = V[i];
        if ((v[i].first < lowest.first && v[i].second == lowest.second) || (v[i].second < v[ind].second)) {
            ind = i;
            lowest = v[i];
        }
    }

    function<int(pair<int,int>, pair<int,int>)> comp = 
    [&lowest, &v](pair<int,int> a, pair<int,int> b) -> int {
        double va = atan2(a.second - lowest.second, a.first - lowest.first);
        if (a == lowest) va = -1;
        double vb = atan2(b.second - lowest.second, b.first - lowest.first);
        if (b == lowest) vb = -1;
        if (va == vb) {
            //cout << a << " " << b << endl;
            if (abs(a.first - lowest.first) < abs(b.first - lowest.first)) {
                //cout << a << " wins" << endl;
                return true;
            } else {
                //cout << b << " wins" << endl;
                return false;
            }
        }
        return va < vb;
    };

    sort(v.begin(), v.end(), comp);

    stack<pair<int,int>> q;
    q.push(lowest);
    for (int i = 1 ; i < n ; i++) {
        // cout << "cur = " << v[i].first << " " << v[i].second << endl;
        while (q.size() > 1) {
            pair<int,int> b = q.top();
            q.pop();
            pair<int,int> c = q.top();
            //cout << c << " " << b << " " << v[i] << endl;
            if (turn(c,b,v[i]) >= 0) {
                //cout << "BREAK" << endl;
                q.push(b);
                break;
            } else {
                continue;
            }
        }
        q.push(v[i]);
    }
    
    int rets = q.size();
    vector<pair<int,int>> ret(q.size());
    for (int i = 0 ; i < rets ; i++) {
        ret[rets-1-i] = q.top();
        q.pop();
    }
    return ret;
}

int main() {
    int n; cin >> n;
    vector<vector<pair<int,int>>> v(2, vector<pair<int,int>>(n));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j].first >> v[i][j].second;
        }
    }
    
    // hull
    vector<vector<pair<int,int>>> hull(2);
    for (int i = 0 ; i < 2 ; i++) {
        hull[i] = convex(v[i]);
        
    }
    for (int j = 0 ; j < 2 ; j++) {
        int o = (j+1)%2;
        
        vector<pair<int,int>> curh = hull[j];
        vector<pair<int,int>> points = v[o];
        sort(v.begin(), v.end());
        int left = curh.size() - 1;
        int right = 0;

        int ans = 0;
        
        for (int i = 0 ; i < n ; i++) {
            if (points[i].second < curh[0].second) continue;
            //check left
            while (curh[left].second == curh[(left+1+curh.size())%curh.size()].second || points[i].second >= curh[left-1].second) {
                //cout << points[i] << " " << curh[left] << " "  << curh[left-1] << endl;
                left--;
                if (left == 0) break;
            }
            if (left == 0) break;

            while (curh[right].second == curh[right+1].second || points[i].second >= curh[right+1].second) {
                right++;
                if (right == curh.size()-1) break;
            }
            if (right == curh.size()-1) break;

            //cout << points[i] << " " << curh[right] << " " << curh[right+1] << " " << curh[left] << " " << curh[(left+1+curh.size())%curh.size()] << endl;
            assert(points[i].second >= curh[right].second && 
                   points[i].second <= curh[right+1].second && 
                   points[i].second <= curh[left].second && 
                   points[i].second >= curh[(left+1+curh.size())%curh.size()].second);
            if ((turn(curh[left], curh[(left+1+curh.size())%curh.size()], points[i]) > 0) &&
                (turn(curh[right+1], curh[right], points[i]) < 0)) {
                    ans++;
            }
        }
        cout << ans << " ";
    }
}