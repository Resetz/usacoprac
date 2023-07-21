// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=134
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <set>


int width[3];
int height[3];

int ix[3];
int iy[3];

bool blocks[3][10][10];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
using namespace std;

struct state {
  state(int d) : d(d) {
    for(int i = 2; i >= 0; i--) {
      ix[i] -= ix[0];
      iy[i] -= iy[0];
    }
    memcpy(six, ix, sizeof(six));
    memcpy(siy, iy, sizeof(siy));
  }

  state(const state& st) {
    d = st.d;
    memcpy(six, st.six, sizeof(six));
    memcpy(siy, st.siy, sizeof(siy));
  }

  state& operator=(const state& st) {
    d = st.d;
    memcpy(six, st.six, sizeof(six));
    memcpy(siy, st.siy, sizeof(siy));
    return *this;
  }

  void make_local() {
    memcpy(ix, six, sizeof(six));
    memcpy(iy, siy, sizeof(siy));
  }

  bool operator<(const state& st) const {
    int r = memcmp(six, st.six, sizeof(six));
    if(!r) r = memcmp(siy, st.siy, sizeof(siy));
    return r < 0;
  }

  int d;
  int six[3];
  int siy[3];
};


bool overlap(int i, int j) {
  return ix[i] < ix[j] + width[j] && ix[j] < ix[i] + width[i] &&
         iy[i] < iy[j] + height[j] && iy[j] < iy[i] + height[i];
}

bool check() {
  for(int i = 0; i < 3; i++) {
    if(ix[i] < -20 || ix[i] > 20 || iy[i] < -20 || iy[i] > 20) return false;
    for(int j = i + 1; j < 3; j++) {
      for(int x = 0; x < width[i]; x++) {
        for(int y = 0; y < height[i]; y++) {
          if(!blocks[i][x][y]) continue;
          int nx = ix[i] + x - ix[j], ny = iy[i] + y - iy[j];
          if(nx < 0 || nx >= width[j] || ny < 0 || ny >= height[j] ||
             !blocks[j][nx][ny]) continue;
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];

    for(int i = 0; i < 3; i++) {
        int ax = 10, ay = 10;
        int bx = 0, by = 0;
        for(int j = 0; j < n[i]; j++) {
            int x, y; cin >> x >> y;
            blocks[i][x][y] = true;
            ax = min(ax, x); ay = min(ay, y);
            bx = max(bx, x + 1); by = max(by, y + 1);
        }
        //borders
        width[i] = bx-ax;
        height[i] = by-ay;

        //shift
        for(int x = ax; x < 10; x++) {
            for(int y = ay; y < 10; y++) {
                blocks[i][x - ax][y - ay] = blocks[i][x][y];
                if(ax || ay) blocks[i][x][y] = false;
            }
        }
        ix[i] = ax;
        iy[i] = ay;
    }

    //bfs
    queue<state> q;
    set<state> v; //visited;
    q.push(state(0));
    while (!q.empty()) {
        state s = q.front();
        q.pop();
        s.make_local();
        if(!overlap(0, 1) && !overlap(0, 2) && !overlap(1, 2)) {
            cout << s.d << endl;
            return 0;
        }   
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 4; j++) {
                s.make_local();
                ix[i] += di[j];
                iy[i] += dj[j];
                state nst = state(s.d + 1);
                if(v.insert(nst).second && check()) q.push(nst);
            }
        }
    }
    cout << -1 << endl;
}
