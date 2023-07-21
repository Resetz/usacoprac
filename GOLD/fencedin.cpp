#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};
int r,c,ver,hor;
int main() {
    cin >> r >> c >> ver >> hor;
    vector<int> v;
    vector<int> h; // horizontal

    v.push_back(0);
    h.push_back(0);
    v.push_back(c);
    h.push_back(r);

    for (int i = 0 ; i < ver ; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0 ; i < hor ; i++) {
        int a;
        cin >> a;
        h.push_back(a);
    }
    ver=v.size();
    hor=h.size();

    sort(v.begin(), v.end());
    sort(h.begin(), h.end());
    //cout << "size " << ver << " " << hor << endl;

    priority_queue<pair<int, pair<int,int>>> pq;
    // pq sorts from high to low;
    // if you want to sort low to high, you should turn your values negative so you don't have to make custom comparator

    vector<vector<int>> best(ver, vector<int>(hor, INT_MAX));
    pq.push(pair<int,pair<int,int>>{0, pair<int,int>{0,0}});

    long long total = 0; 
    while (!pq.empty()) {
        pair<int, pair<int,int>> p = pq.top();
        pq.pop();
        p.first *= -1;

        if (best[p.second.first][p.second.second] < 0) {
            continue;
        }

        best[p.second.first][p.second.second] *= -1;
        total += p.first;
        //cout << p.first << endl;
        for (int i = 0 ; i < 4 ; i++) {
            int newx, newy;
            newx = p.second.first + di[i];
            newy = p.second.second + dj[i];

            if (newx >= 0 && newx < ver-1 && newy >= 0 && newy < hor-1 && best[newx][newy] > 0) {
                int dist = 0;
                //cout << p.second.first+1 << " " << p.second.second+1 << endl;
                if (newy == p.second.second) {
                    dist = h[p.second.second+1] - h[p.second.second];
                } else {
                    dist = v[p.second.first+1] - v[p.second.first];
                }
                if (dist < best[newx][newy]) {
                    best[newx][newy] = dist;
                    pq.push({-dist, {newx,newy}});
                }
            }
        }
    }
    cout << total << endl;
}