#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


typedef struct {
    int x1,y1,x2,y2;
} rect;

int main() {
    int x,y,n;
    cin >> n;
    vector<rect> v(n);
    vector<pair<long long,long long>> points;
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].x1 >> v[i].y2 >> v[i].x2 >> v[i].y1;
        //v[i].x2++;
        //v[i].y2++;
        points.push_back({v[i].x1, (i+1)}); points.push_back({v[i].x2, -(i+1)});
    }

    /*
    sort(v.begin(), v.end(), [](rect a, rect b) -> auto {
        return a.x1 < b.x1;
    });*/
    sort(points.begin(), points.end());

    vector<bool> cur(n, false);
    long long pos = 0;
    long long prev_pos = LLONG_MIN;
    long long prev_val = 0;
    long long ans = 0;
    
    for (int i = 0 ; i < 2*n ;) {
        pos = points[i].first;
        ans += (pos - prev_pos) * prev_val;
        
        //cout << pos << "-" << prev_pos << " " << prev_val << " " << i << endl;
        //cout << "cur[" << abs(points[i].second)-1 << "] = " << (points[i].second > 0) << endl;
        cur[abs(points[i].second)-1] = points[i].second > 0;

        i++;
        while (i < 2*n && points[i].first == pos) {
            //cout << "cur[" << abs(points[i].second)-1 << "] = " << (points[i].second > 0) << endl;
            cur[abs(points[i].second)-1] = points[i].second > 0;
            i++;
        }
        vector<pair<int,int>> yvals;
        for (int j = 0 ; j < n ; j++) {
            if (cur[j]) {
                yvals.push_back({v[j].y1, 1});
                yvals.push_back({v[j].y2, -1});
            }
        }
        sort(yvals.begin(), yvals.end());
        long long prevy = LLONG_MIN;
        long long cury = 0;
        int posy = 0;
        prev_val = 0;
        for (int j = 0 ; j < yvals.size();) {
            posy = yvals[j].first;
            prev_val += (posy - prevy) * (cury > 0);
            //cout << "y = " << posy << "-" << prevy  << " " << cury << endl;
            cury += yvals[j].second;
            j++;
            while ( j < yvals.size() && yvals[j].first == posy) {
                cury += yvals[j].second;
                j++;
            }
            prevy = posy;
        }
        prev_pos = pos;
    }
    cout << ans << endl;
}