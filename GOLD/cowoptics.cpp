#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <queue>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cassert>

// key point: determining whether or not a line INTERSECTS with a circle
// is very similar to how you would determine whether or not a line 
// intersects another line. by finding if two points on the line 
// are on opposite sides of a tangent line, we can determine if the two
// points can "see" eachother. 

using namespace std;

class comp {
    public:
    bool operator() (pair<double,double> p1, pair<double,double> p2) {
        return p1.second > p2.second;
    }
};

int main() {
    int n, R;
    cin >> n >> R;
    vector<pair<double,double>> points;
    priority_queue<pair<double,double>, vector<pair<double,double>>, comp> sweep; //sort by exit (earliest exit first).
    for (int i = 0 ; i < n ; i++) {
        double x,y;
        cin >> x >> y;
        double a = acos(R/(sqrt(x*x+y*y)));
        double b = atan2(y,x);
        //entrance / exit angles (from the perspective of the origin);
        pair<double,double> p = {b-a, b+a};

        //edger case
        if (p.second > M_PI) {
            p.second -= 2*M_PI;
            p.first -= 2*M_PI;
        }
        if (p.first < -M_PI) {
            p.second += 2*M_PI;
            p.first += 2*M_PI;
        } 
        points.push_back(p);
        //cout << i << " " << x << " " << y << endl;
        //cout << i << " " << points[i].first << " " << points[i].second << endl;
        //cout << endl;
    }
    
    sort(points.begin(), points.end());

    long long ans = 0;
    for (int i = 0 ; i < 2; i++) {
        int nxt = 0;
        int good = true;
        double curline = 0;
        while (nxt < n) {
            //which is closer?
            //our current line is at the nxt-1

            curline = points[nxt].first;
            while (!sweep.empty() && sweep.top().second < curline) {
                sweep.pop();
            }
            
            if (i == 1) ans += sweep.size();

            pair<double, double> p = points[nxt];
            if (p.first >= 0 && p.second <= 0) {
                p.second += 2*M_PI;
            }
            sweep.push(p);
            points[nxt].first+=2*M_PI;
            points[nxt].second+=2*M_PI;
            nxt++;
        }
    }
    cout << ans << endl;

    
}