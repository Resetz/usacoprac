#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool a[100][100][100];
bool v[100][100][100];
int di[6] = {1, -1, 0, 0, 0, 0};
int dj[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int n;

bool check(int x, int y, int z) {
    return x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n;
}
void ff(int x, int y, int z) {
    
    if (!check(x,y,z) || v[x][y][z] || !a[x][y][z]) {
        return;
    }
    v[x][y][z] = true;
    for (int i = 0; i < 6; i++) {
        ff(x+di[i], y+dj[i], z+dz[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            for (int k = 0; k < n ; k++) {
                char c;
                cin >> c;
                a[i][j][k] = c == '*';
            }
        }
    }

    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            for (int k = 0; k < n ; k++) {
                if (a[i][j][k] && !v[i][j][k]) {
                    ans++;
                    ff(i,j,k);
                }
            }
        }
    }
    cout << ans << endl;
}