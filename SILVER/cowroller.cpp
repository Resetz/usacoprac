/*
Cow Roller Coaster
==================

The cows are building a roller coaster! They want your help to
design as fun a roller coaster as possible, while keeping to the
budget.

The roller coaster will be built on a long linear stretch of land
of length L (1 <= L <= 1,000). The roller coaster comprises a
collection of some of the N (1 <= N <= 10,000) different interchangable
components. Each component i has a fixed length Wi (1 <= Wi <= L).
Due to varying terrain, each component i can be only built starting
at location Xi (0 <= Xi <= L-Wi). The cows want to string together
various roller coaster components starting at 0 and ending at L so
that the end of each component (except the last) is the start of
the next component.

Each component i has a "fun rating" Fi (1 <= Fi <= 1,000,000) and
a cost Ci (1 <= Ci <= 1000). The total fun of the roller coster is
the sum of the fun from each component used; the total cost is
likewise the sum of the costs of each component used. The cows'
total budget is B (1 <= B <= 1000). Help the cows determine the
most fun roller coaster that they can build with their budget.

PROBLEM NAME: coaster

INPUT FORMAT:

* Line 1: Three space-separated integers: L, N and B.

* Lines 2..N+1: Line i+1 contains four space-separated integers,
        respectively: Xi, Wi, Fi, and Ci.

SAMPLE INPUT:

5 6 10
0 2 20 6
2 3 5 6
0 1 2 1
1 1 1 3
1 2 5 4
3 2 10 2


OUTPUT FORMAT:

* Line 1: A single integer that is the maximum fun value that a
        roller-coaster can have while staying within the budget and
        meeting all the other constraints. If it is not possible to
        build a roller-coaster within budget, output -1.

SAMPLE OUTPUT:

17

OUTPUT DETAILS:

Taking the 3rd, 5th and 6th components gives a connected roller-coaster
with fun value 17 and cost 7. Taking the first two components would
give a more fun roller-coaster (25) but would be over budget.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    // x -> start
    // w -> len
    // f -> fun
    // c -> cost
    int w,x,f,c;
} s;

int main() {
    int l, n, b;
    cin >> l >> n >> b;

    vector<s> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].w >> v[i].f >> v[i].c;
    }

    sort(v.begin(), v.end(), [](s a, s b) -> int {
        return a.x+a.w < b.x+b.w;
    });
    vector<vector<int>> dp(l+1, vector<int>(b+1, -1));
    for (int i = 0 ; i <= b ; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j+v[i].c <= b; j++) {
            if (dp[v[i].x][j] >= 0) {
                dp[v[i].x+v[i].w][j+v[i].c] = max(dp[v[i].x+v[i].w][j+v[i].c], dp[v[i].x][j]+v[i].f);
            }
        }
    }

    int ans = -1;
    for (int i = 0 ; i <= l ; i++) {
        ans = max(ans, dp[i][b]);
    }
    cout << dp[l][b] << endl;

}