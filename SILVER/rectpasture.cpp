#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> rows[2500];
vector<int> cols[2500];

set<set<int>> ans;

vector<pair<int,int>> cows;

set<int> current;


int grid[2501][2501];

int n;

int getpf(int x1, int y1, int x2, int y2) {
    //x2--; y2--;
    x1++, y1++, x2++, y2++;
    //cout << x1 << " " << y1 << ", " << x2 << " " << y2 << " " << grid[x1-1][y1-1] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x2][y2] << endl;
    return grid[x1-1][y1-1] - grid[x1-1][y2] - grid[x2][y1-1] + grid[x2][y2];
}

void dopf(int x, int y, int cur) {
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= n ; j++) {
            if (i == 0 && j == 0) {
                grid[i][j] = grid[i][j];
            } else if (i > 0 && j == 0) {
                grid[i][j] = grid[i][j] + grid[i-1][j];
            } else if (i == 0 && j > 0) {
                grid[i][j] = grid[i][j] + grid[i][j-1];
            } else {
                grid[i][j] = grid[i-1][j] + grid[i][j-1] - 
                             grid[i-1][j-1] + grid[i][j];
            }
        }
    }
}

int main() {
    cin >> n;
    cows.resize(n);
    vector<int> a,b;
    for (int i = 0; i < n ; i++) {
        cin >> cows[i].first >> cows[i].second;
        a.push_back(cows[i].first); // x coordinates
        b.push_back(cows[i].second);
    }

    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        cows[i].first = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    }

    d = b;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for (int i = 0; i < n; ++i) {
        cows[i].second = lower_bound(d.begin(), d.end(), b[i]) - d.begin();
    }

    for (int i = 0 ; i < n ; i++) {
        grid[cows[i].first+1][cows[i].second+1] = true;
    }

    dopf(0, 0, 0);

    unsigned long long ans = 0;
    sort(cows.begin(), cows.end());
    for (int i = 0; i < n ; i++) {
        for (int j = i ; j < n ; j++) {

            int y1 = max(cows[i].second, cows[j].second);
            int y2 = min(cows[i].second, cows[j].second);
            // i < j
            ans += getpf(i, 0, j, y2) * getpf(i, y1, j, n-1);
            
        }
    }
    cout << ans + 1 << endl; // count empty subset.

}