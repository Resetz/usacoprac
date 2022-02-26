/*
Cow Resizing
Farmer John’s N cows (1≤N≤30000) are currently standing in a line. The cows are numbered 1…N from left to right in this line. Each cow has an integer height hi (1≤hi≤3). Cows with heights 1, 2, and 3 are considered short, medium, and tall respectively.

Farmer John thinks his line of cows will only be beautiful if they are sorted in increasing or decreasing order of height. This means that lines of cows with heights like 112233 or 332211 are beautiful.

FJ really wants his line of cows to be beautiful, but the cows refuse to change their order in the line. So, to make his line of cows beautiful, FJ decides to change the height of several cows to a different value. He has artificial legs for cows that need to be taller, and he has a mechanical squeezer for cows that need to be shortened. (Don’t worry, it doesn’t hurt.) However, both of these take quite a lot of effort to do, so he’d like to change as few of the cows’ heights as possible.

Please help FJ determine the minimum number of cows that he needs to change the height of so that the heights are sorted in either increasing or decreasing order.

INPUT FORMAT
The first line of input contains a single integer N. The next N lines of input contain the heights of the cows. Line i+1 contains hi.

OUTPUT FORMAT
Output a single integer: The minimum number of cow heights Farmer John needs to change for the line to be sorted by either increasing or decreasing order of heights.

SAMPLE INPUT
5
1
3
2
1
1
SAMPLE OUTPUT
1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0 ; i < n ; i++ ) {cin >> v[i]; v[i]--;}

    vector<vector<int>> pre(n+1, vector<int>(3,0));

    for (int i = 0 ; i < n ;i++) {
        for (int j = 0 ; j < 3; j++) {
            pre[i+1][j] = pre[i][j] + (v[i] == j);
        }
    }

    cout << "here" << endl;
    int ans = INT_MAX;

    for (int i = 0 ; i <= n ; i++) {
        for (int j = i; j <= n ; j++) {
            //cout << i << "  " << j << endl;
            int cur = 0;
            cur +=  pre[i][1] - pre[0][1];
            cur += (pre[i][2] - pre[0][2]);

            cur +=  pre[j][0] - pre[i][0];
            cur += (pre[j][2] - pre[i][2]);

            cur +=  pre[n][1] - pre[j][1];
            cur += (pre[n][0] - pre[j][0]);

            ans = min(cur, ans);
            //cout << " - " << cur << endl;

            cur = 0;

            cur +=  pre[i][1] - pre[0][1];
            cur += (pre[i][0] - pre[0][0]);

            cur +=  pre[j][0] - pre[i][0];
            cur += (pre[j][2] - pre[i][2]);

            cur +=  pre[n][1] - pre[j][1];
            cur += (pre[n][2] - pre[j][2]);

            ans = min(cur, ans);
            //cout << " - " << cur << endl;
        }
    }
    cout << ans << endl;
}