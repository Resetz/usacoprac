// rectangle union problem

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct point {
    int x, y1, y2;
    bool left;
};

multiset<pair<int,int>> ms;

int find() {
    vector<pair<int,int>> p{ms.begin(), ms.end()};
    sort(p.begin(), p.end());
    int len = 0;
    int first = -INT_MAX;
    int last = -INT_MAX;
    int cur = 0;
    for (int i = 0 ; i < p.size(); i++) {
        if (p[i].first < last) {
            last = max(last, p[i].second);
            cur = last - first;
        } else {
            len += cur;
            first = p[i].first;
            last = p[i].second;
            cur = last - first; 
        }
    }
    len += cur;
    return len;
}

int n;

int main() {
    
    vector<point> v;

    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({x1, min(y2,y1), max(y2,y1), true});
        v.push_back({x2, min(y2,y1), max(y2,y1), false});
    }
    sort(v.begin(), v.end(), [](const point& a, const point& b) -> int {
        return a.x < b.x;
    });

    int area = 0;
    int lastx = 0;
    for (int i = 0 ; i < n * 2 ; i++) {
        point p = v[i];
        int findans = find();
        area += (p.x - lastx) * findans;
        //cout << findans << " " << p.x - lastx << endl;
        
        if (p.left) {
            ms.insert({p.y1, p.y2});
        } else {
            ms.erase({p.y1, p.y2});
        }

        lastx = p.x;
    }
    cout << area << endl;
}