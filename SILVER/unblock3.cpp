
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

int n[3];

int first[];

using namespace std;

int main() {
    cin >> n[0] >> n[1] >> n[2];

    for (int i = 0 ; i < 3; i++) {
        int maxx, maxy, minx, miny;
        maxx = 0;
        maxy = 0;
        minx = 10;
        miny = 10;
        for (int j = 0 ; j < n[i]; j++) {
            int x, y;
            cin >> x >> y;

        }
    }
}
