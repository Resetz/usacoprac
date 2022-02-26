/*
Heavy Spender
Farmer John is a wealthy farmer, but his prized cow Bessie is a very heavy spender. If she has any extra money, it will disappear before Farmer John even knows it. In order to keep Bessie from driving Farmer John bankrupt, he has purchased a brand new wallet for Bessie which can only hold at most K coins (1≤K≤200). Coins come in N possible values (1≤N≤50), each value in the range 1…10000. Farmer John has an infinite supply of coins of each value.

Now, when Bessie wants to go out shopping, Farmer John will only let her carry as much money as she needs and no more. However, Farmer John has realized that he may not be able to give Bessie all possible amounts of money. Determine for Farmer John the maximum number M such that all the values 1…M can be given to Bessie in her new wallet (if the number 1 cannot be created, print 0).

INPUT FORMAT
Line 1: Two space-separated integers K and N
Lines 2..??: N integers, 15 per line, listing all of the N values that coins can be of

OUTPUT FORMAT
A single integer M, indicating that Farmer John can give Bessie exactly all values in the range 1…M in her wallet.

SAMPLE INPUT
5 2
1 3
SAMPLE OUTPUT
13
OUTPUT DETAILS
For example, consider coins whose values are limited to 1 and 3; Bessie can hold at most 5 coins. Here's how one may construct the numbers 6…13 (the numbers 1…5 can be constructed with that many coins of value 1):

$6 = 3 + 3$
$7 = 3 + 3 + 1$
$8 = 3 + 3 + 1 + 1$
$9 = 3 + 3 + 3$
$10 = 3 + 3 + 3 + 1$
$11 = 3 + 3 + 3 + 1 + 1$
$12 = 3 + 3 + 3 + 3$
$13 = 3 + 3 + 3 + 3 + 1$
However, there is no way to give Bessie exactly 14 total coin value.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> c(k);
    int highest = 0;
    for (int i = 0 ; i < k ; i++) {
        cin >> c[i];
        highest = max(highest, c[i]);
    }
    sort(c.begin(), c.end());

    vector<bool> found((n*highest)+1, false);
    vector<bool> ne((n*highest)+1, false);
    found[0] = true;
    ne[0] = true;
    int high = 0;
    for (int i = 0 ; i < n ; i++) {
       // cout << "high " << high << endl;
        for (int j = 0 ; j < k ; j++) {
            for (int o = found.size()-c[j]-1 ; o >= 0 ; o--) {
                //cout << o+c[j] << endl;
                if (o+c[j] < high) break;
                ne[o+c[j]] = found[o] | ne[o+c[j]];
            }
        }
        high = 0;
        while (high < found.size() && found[high]) high++;
        high--;
        found = ne;
    }
    int ans = 0;
    while (ans < found.size() && found[ans]) ans++;
    cout << ans-1 << endl;

}