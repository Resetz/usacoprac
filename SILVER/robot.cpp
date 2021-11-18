#include <iostream>
#include <vector>

using namespace std;

pair<int,int> pos[4] = {{0,0},{1,0},{0,1},{1,1}}; //RL RR FL FR



int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int direction = 0;

int main() {
    int n;
    cin >> n;
    int maxx = 1;
    int minx = 0;
    int maxy = 1;
    int miny = 0;
    for (int i = 0 ; i < n ; i++) {
        string s;
        int target = 0;
        cin >> s; 
        if (s[0] == 'F') {
            target+=2;
        }
        if (s[1] == 'R') {
            target++;
        }

        if (s[2] == 'P') {
            for (int i = 0 ; i < 4; i++) {
                if (i != target) {
                    int dx = pos[i].first - pos[target].first;
                    int dy = pos[i].second - pos[target].second;

                    int newx = dy + pos[target].first;
                    int newy = -dx + pos[target].second;
                    pos[i] = {newx, newy};
                }
            }
            direction = (direction+1)%4;
        } else {
            int go = direction;
            if (s[2] == 'F') {
                go += 0;
            } else if (s[2] == 'R') {
                go += 1;
            } else if (s[2] == 'B') {
                go += 2;
            } else if (s[2] == 'L') {
                go += 3;
            }
            go = go % 4;
            pos[target].first += dj[go];
            pos[target].second += di[go];
        }
        for (int i = 0 ; i < 4 ; i++) {
            maxx = max(pos[i].first, maxx);
            maxy = max(pos[i].second, maxy);
            minx = min(pos[i].first, minx);
            miny = min(pos[i].second, miny);
        }
        //cout << direction << " | " << maxx << ", " << maxy << " | " << minx << ", " << miny << endl;;
    }
    cout << (maxx-minx+1) * (maxy-miny+1) << endl;
}