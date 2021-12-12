#include <iostream>
#include <vector>

using namespace std;

int grid[1000][1000];
int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n ; i++) {
        
        int a = 0;
        int b = 0;
        for (int j = 0 ; j < n ; j++) {
            if (j % 2 == 0) {
                a += grid[i][j];
            } else {
                b += grid[i][j];
            }
        }
        cur += max(a,b);
    }
    ans =  max(ans, cur);

    cur = 0;
    for (int i = 0; i < n ; i++) {
        int a = 0;
        int b = 0;
        for (int j = 0 ; j < n ; j++) {
            if (j % 2 == 0) {
                a += grid[j][i];
            } else {
                b += grid[j][i];
            }
        }
        cur += max(a,b);
    }
    ans =  max(ans, cur);
    cout << ans << endl;
}