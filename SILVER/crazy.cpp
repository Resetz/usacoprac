#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

vector<pair<pair<int,int>,pair<int,int>>> points;
vector<pair<int,int>> cows;

vector<pair<int, pair<int,int>>> sorterx;
vector<pair<int, pair<int,int>>> sortery;
bool visited[2002][2002];
int grid[2002][2002];

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
int total;

void ff(int r, int c) {
    queue<pair<int,int>> q;
    q.push(make_pair(r,c));

    while (q.size() > 0) {
        pair<int,int> p = q.front();
        q.pop();

        if (p.first < 2002 && p.first >= 0 && p.second < 2002 && p.second >= 0) {
            if (grid[p.first][p.second] != 1 && !visited[p.first][p.second]) {
                visited[p.first][p.second] = true;
                if (grid[p.first][p.second] == 2) {
                    total++;
                }
                q.push(make_pair(p.first+di[0],p.second+dj[0]));
                q.push(make_pair(p.first+di[1],p.second+dj[1]));
                q.push(make_pair(p.first+di[2],p.second+dj[2]));
                q.push(make_pair(p.first+di[3],p.second+dj[3]));
            }    
        }
    }
}

int main() {
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            visited[i][j] = false;
        }
    }
    int n,c;
    cin >> n >> c;
    for (int i = 0 ; i < n; i ++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        points.push_back(make_pair(make_pair(x1,y1),make_pair(x2,y2)));
        sorterx.push_back(make_pair(x1, make_pair(i+1,0)));
        sortery.push_back(make_pair(y1, make_pair(i+1,0)));
        sorterx.push_back(make_pair(x2, make_pair(i+1,1)));
        sortery.push_back(make_pair(y2, make_pair(i+1,1)));
    }
    for (int i = 0 ; i < c; i++) {
        int x,y;
        cin >> x >> y;
        cows.push_back(make_pair(x,y));
        sorterx.push_back(make_pair(x, make_pair(-(i+1),2)));
        sortery.push_back(make_pair(y, make_pair(-(i+1),2)));
        
    }
    
    sort(sorterx.begin(), sorterx.end());
    sort(sortery.begin(), sortery.end());
    int current = 2;
    int prev = sorterx[0].first;
    int index;
    for (int i = 0; i < n*2+c; i++) {
        if (sorterx[i].first != prev) {
            current += 2;
        }
        //cout << sorterx[i].first << ", " << sorterx[i].second.first << ", " << sorterx[i].second.second << ", " << current <<endl;
        if (sorterx[i].second.first > 0) {
            index = sorterx[i].second.first-1;
            if (sorterx[i].second.second == 0) {
                points[index].first.first = current;
            } else {
                points[index].second.first = current;
            }
        } else {
            index = (-sorterx[i].second.first)-1;
            cows[index].first = current;
        }
        prev = sorterx[i].first;
    }
    
    //cout << "sortery:" << endl;
    current = 2;
    prev = sortery[0].first;
    for (int i = 0; i < n*2+c; i++) {
        if (sortery[i].first != prev) {
            current += 2;
        }
        //cout << sortery[i].first << ", " << sortery[i].second.first << ", " << sortery[i].second.second << ", " << current <<endl;
        if (sortery[i].second.first > 0) {
            index = sortery[i].second.first-1;
            if (sortery[i].second.second == 0) {
                points[index].first.second = current;
            } else {
                points[index].second.second = current;
            }
        } else {
            int index = (-sortery[i].second.first)-1;
            cows[index].second = current;
        }
        prev = sortery[i].first;
    }

    
    for (int i = 0; i < n; i++) {
        pair<pair<int,int>,pair<int,int>> line = points[i];

        if (line.first.first == line.second.first) {
            if (line.first.second > line.second.second) {
                for (int i = line.second.second; i <= line.first.second; i++) {
                    grid[line.first.first][i] = 1;
                }
            } else {
                for (int i = line.first.second; i <= line.second.second; i++) {
                    grid[line.first.first][i] = 1;
                }
            }
        } else {
            if (line.first.first > line.second.first) {
                for (int i = line.second.first; i <= line.first.first; i++) {
                    grid[i][line.second.second] = 1;
                }
            } else {
                for (int i = line.first.first; i <= line.second.first; i++) {
                    grid[i][line.second.second] = 1;
                }
            }
        }
    }
    for (int i = 0; i < c; i++) {
        pair<int,int> cow = cows[i];
        //cout << cow.first << " " << cow.second << endl;
        grid[cow.first][cow.second] = 2;
    }
    /*
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }*/
    
    
    //floodfill
    int ans = 0;
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            if (!visited[i][j] && grid[i][j] != 1) {
                //floodfill;
                total = 0;
                ff(i,j);
                if (total > ans) {
                    ans = total;
                }

            }
        }
    }
    cout << ans;
}