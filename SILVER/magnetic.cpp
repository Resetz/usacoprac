/*
Magnetic Marbles
Bessie received a new set of marbles, which come in two colors: black and white. In fact, there are so many marbles that Bessie will never run out of either color. She thinks that the marbles are pretty, so she arranges N of them (1≤N≤105) delicately in a line on her windowsill. Unfortunately, the black marbles are magnetic; if two black marbles are too close to each other in the line, they may attract or repel, disturbing the rest of the line. As a result, two black marbles must have at least K other marbles (0≤K<N) between them.

Determine the number of marble arrangements that Bessie can create. 

INPUT FORMAT
Line 1: Two space-separated integers N and K
OUTPUT FORMAT
A single integer: The total number of marble arrangements Bessie can create. Since this number can be quite large, output the result modulo 5000011.

SAMPLE INPUT
4 2
SAMPLE OUTPUT
6
OUTPUT DETAILS
Every pair of black marbles must have at least 2 other marbles in between.

Here are all 6 possible arrangements (B is black, W is white):

WWWW

BWWW
BWWB

WBWW

WWBW
WWWB

hmmm

WWWWW
WWWWB

BWWWB
BWWBW

WBWWB

WWBWW
WWWBW


WWW
 - WWW
 - BWW
 - WBW
 - WWB

BWW
 - WWW
 - BWW
 - WBW
 - WWB

WBW
 - WWW
 - WBW
 - WWB

WWB
 - WWW
 - WWB
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;


    

    vector<unsigned long long> dp(k+2, 1);

    vector<unsigned long long> precalc(k+2,0);
    int curlen;
    for (curlen = k+1; curlen < n ; curlen+=k+1) {
        unsigned long long m = 0;
        for (int i = 0 ; i <= k+1 ; i++) {
            m = (m + dp[i]) % 5000011;
            precalc[i] = m;
        }
        for (int i = 1 ; i <= min(k+1, n-curlen) ; i++) {
            dp[i] = precalc[i];
        }
        dp[0] = m;
    }

    unsigned long long ans = 0;
    if (curlen != n) {
        for (int i = 0 ; i <= n - (curlen-(k+1)) ; i++) { 
            ans = (ans + dp[i]) % 5000011; 
            }
    } else {
        for (int i = 0 ; i <= k+1 ; i++)  {
            ans = (ans + dp[i]) % 5000011;
        }
    }
    cout << ans << endl;
}