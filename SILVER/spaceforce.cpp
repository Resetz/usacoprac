#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int di[4] = {0,0,-1,1};
int dj[4] = {1,-1,0,0};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(301, vector<int>(301, 0));
    vector<vector<int>> next(301, vector<int>(301, 0));

    vector<pair<int,pair<int,int>>> asteroids(n);
    for (int i = 0 ; i < n ; i++) {
        int x,y,t;
        cin >> x >> y >> t;
        asteroids[i] = {t, {x,y}};
    }
    sort(asteroids.begin(), asteroids.end());

    vector<vector<int>> safe(301, vector<int>(301, 1));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < 4 ; j++) {
            int newx = asteroids[i].second.first + di[j];
            int newy = asteroids[i].second.second + dj[j];
            if (newx >= 0 && newy >= 0 && newx < 301 && newy < 301) {
                safe[newx][newy] = -1;
            }
        }
        safe[asteroids[i].second.first][asteroids[i].second.second] = -1;
    }

    grid[0][0] = 1;
    next[0][0] = 1;
    int cur = 0;
    int time = 0;
    while (true) {
        while (asteroids[cur].first == time) {
            for (int i = 0 ; i < 4 ; i++) {
                int newx = asteroids[cur].second.first + di[i];
                int newy = asteroids[cur].second.second + dj[i];
                if (newx >= 0 && newy >= 0 && newx < 301 && newy < 301) {
                    grid[newx][newy] = -1;
                    next[newx][newy] = -1;
                }
            }
            grid[asteroids[cur].second.first][asteroids[cur].second.second] = -1;
            next[asteroids[cur].second.first][asteroids[cur].second.second] = -1;
            cur++;
        }
        //cout << "here" << endl;
        int foundone = 0;
        for (int i = 0 ; i < 301 ; i++) {
            for (int j = 0 ; j < 301 ; j++) {
                if (grid[i][j] == 1) {
                    foundone++;
                    if (safe[i][j] == 1) {
                        //cout << i << " " << j << endl;
                        cout << time << endl;
                        return 0;
                    }
                    for (int k = 0 ; k < 4; k++) {
                        int newx = i+di[k];
                        int newy = j+dj[k];
                        if (newx >= 0 && newy >= 0 && newx < 301 && newy < 301) {
                            if (grid[newx][newy] == 0) {
                                next[newx][newy] = 1;
                            }
                        }
                    }
                   // next[i][j] = 1;
                }
            }
        }
        if (foundone == 0) {
            cout << -1 << endl;
            return 0;
        }
        grid = next;
        time++;
    }
}