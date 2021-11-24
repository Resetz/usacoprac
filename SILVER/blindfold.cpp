#include <iostream>
#include <vector>
#include <set>

using namespace std;

int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

int dpx[100000];
int dpy[100000];
int dpd[100000];

int pdy[100000];
int pdx[100000];
int main() {
    string s;
    cin >> s;


    int direction = 0;
    int x = 0, y = 0;
    for (int i = 0 ; i < s.size(); i++) {
        pdx[i] = x;
        pdy[i] = y;
        if (s[i] == 'F') {
            x += di[direction];
            y += dj[direction];
        } else if (s[i] == 'R') {
            direction = (direction+1) % 4;
        } else {
            direction = (direction+3) % 4;
        }
        dpd[i] = direction;

    }
    x = y = 0;
    
    for (int i = s.size()-1 ; i >= 0 ; i--) {
        if (s[i] == 'F') {
            x += di[direction];
            y += dj[direction];
        } else if (s[i] == 'R') {
            direction = (direction+3) % 4;
        } else {
            direction = (direction+1) % 4;
        }
        dpx[i] = x;
        dpy[i] = y;
    }
    /*
    for (int i = 0 ; i < s.size() ; i++) {
        cout << "(" << pdx[i] << ", " << pdy[i] << "), ";
    }
    cout << endl;
    for (int i = 0 ; i < s.size() ; i++) {
        cout << "(" << dpx[i] << ", " << dpy[i] << "), ";
    }
    cout << endl;*/

    set<pair<int,int>> ans;

    for (int i = 0 ; i < s.size(); i++) {
        if (s[i] == 'R') {
            ans.insert({-dpx[i]+pdx[i], -dpy[i]+pdy[i]});

            int newdir = (dpd[i]+3)%4;
            ans.insert({-dpy[i]+di[newdir]+pdx[i], dpx[i]+dj[newdir]+pdy[i]});
        }
        if (s[i] == 'L') {
            ans.insert({-dpx[i]+pdx[i], -dpy[i]+pdy[i]});

            int newdir = (dpd[i]+1)%4;
            ans.insert({dpy[i]+di[newdir]+pdx[i], -dpx[i]+dj[newdir]+pdy[i]});
        }
        if (s[i] == 'F') {
            int newx = dpx[i] - di[dpd[i]];
            int newy = dpy[i] - dj[dpd[i]];

            ans.insert({-newy+pdx[i], newx+pdy[i]});
            ans.insert({newy+pdx[i],-newx+pdy[i]});
        }
    }
    cout << ans.size() << endl; 

}