#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

typedef pair<double,double> pdd;
int k;
pdd don;


typedef struct {
    double a,b,c,d;
} isect;

typedef struct {
    bool begin;
    pdd pos;
    int a;
} e;

isect intersect(pdd a, pdd b) {
    double m = (a.second - b.second) / (a.first - b.first);
    
    return isect{a.second - m*a.first, -(a.second - m*a.first)/m, m*k + (a.second - m*a.first), (k-a.second)/m + a.first};
}

double cross(pdd a, pdd b) {
    return (b.first - don.first) * (a.second - don.second) - (a.first - don.first) * (b.second - don.second);
}

double side(pdd a) {
    if (a.first == don.first) {
        return a.second > don.second;
    } else {
        return a.first > don.first;
    }
}

double radial(e a, e b) {
    bool sa = side(a.pos);
    bool sb = side(b.pos);
    if (sa == sb) {
        double c = cross(a.pos, b.pos);
        if (c == 0) return a.a > b.a;
        return c > 0;
    }
    return sa < sb;
}

int main() {
    int n; cin >> k >> n;
    cin >> don.first >> don.second;



    vector<e> events;
    for (int i = 0 ; i < n ; i++) {
        int s = 0;
        cin >> s; 
        
        vector<pdd> rock(s);
        for (int j = 0 ; j < s ; j++) {
            cin >> rock[j].first >> rock[j].second;
        }
        sort(rock.begin(), rock.end(), [](pdd a, pdd b) -> int {
            return cross(a,b) > 0;
        });
        events.push_back(e{true, rock[0], i});
        events.push_back(e{false, rock[s-1], i});
    }

    sort(events.begin(), events.end(), radial);
    
    int pf = 0;

    vector<bool> vis(n, false);
    for (int i = 0 ; i < events.size() ; i++) {
        if (events[i].begin) vis[events[i].a] = true;
        else if (!vis[events[i].a]) {
            pf++;
        }
    }

    int ans = 0;
    int curfence = 0;
    e cur = {false, pdd{don.first, k}, 0};
    for (int i = 0 ; i < events.size() ; i++) {
        while (curfence < 4*k && radial(cur, events[i])) {
            if (pf == 0) ans++;
            curfence++;
            if (cur.pos.first == 0) {
                cur.pos.second++;
            } 
            else if (cur.pos.second == 0) {
                cur.pos.first--;
            }
            else if (cur.pos.first == k) {
                cur.pos.second--;
            }
            else if (cur.pos.second == k) {
                cur.pos.first++;
            }
        }
        if (events[i].begin) pf++;
        else {
            pf--;
        }
    }
    if (pf == 0) ans += 4*k-curfence;
    cout << ans << endl;
}