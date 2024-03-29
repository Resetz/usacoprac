/*
Cow Digit Game
==============

Bessie is playing a number game against Farmer John, and she wants
you to help her achieve victory.

Game i starts with an integer N_i (1 <= N_i <= 1,000,000). Bessie
goes first, and then the two players alternate turns. On each turn,
a player can subtract either the largest digit or the smallest
non-zero digit from the current number to obtain a new number. For
example, from 3014 we may subtract either 1 or 4 to obtain either
3013 or 3010, respectively. The game continues until the number
becomes 0, at which point the last player to have taken a turn is
the winner.

Bessie and FJ play G (1 <= G <= 100) games. Determine, for each
game, whether Bessie or FJ will win, assuming that both play perfectly
(that is, on each turn, if the current player has a move that will
guarantee his or her win, he or she will take it).

Consider a sample game where N_i = 13. Bessie goes first and takes
3, leaving 10. FJ is forced to take 1, leaving 9. Bessie takes the
remainder and wins the game.

PROBLEM NAME: cdgame

INPUT FORMAT:

* Line 1: A single integer: G

* Lines 2..G+1: Line i+1 contains the single integer: N_i

SAMPLE INPUT:

2
9
10

OUTPUT FORMAT:

* Lines 1..G: Line i contains "YES" if Bessie can win game i, and "NO"
        otherwise.

SAMPLE OUTPUT:

YES
NO

OUTPUT DETAILS:

For the first game, Bessie simply takes the number 9 and wins.
For the second game, Bessie must take 1 (since she cannot take 0), and then
FJ can win by taking 9.
*/

#include <iostream>
#include <vector>

using namespace std;

pair<int,int> go(int n) {
    int highest = 0;
    int lowest = 9;
    while (n > 0) {

        if (n % 10 != 0) {
            highest = max(highest, n%10);
            lowest = min(lowest, n%10);
        }

        n /= 10;
    }
    return pair<int,int>{lowest, highest};
}

void solve() {
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = 0;

    for (int i = 1 ; i <= n ; i++) {
        pair<int,int> p = go(i);
        int low = p.first;
        int high = p.second;

        dp[i] = !dp[i-high] || !dp[i-low];
    }
    cout << (dp[n] ? "YES" : "NO") << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}