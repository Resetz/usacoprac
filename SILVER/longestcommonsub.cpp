//given string a and string b
//find the longest common subsequence 
//alg : let f(i,j) be the result of the problem if you are looking at the first i and j letters of a and b
//then, the answer to f(i,j) is max(f(i-1, j), f(i,j-1)) + 1 if they are the same and no +1 if they are diff

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n, m;
    n = a.size();
    m = b.size();

    vector<int> dp(n+1, 0);
    vector<int> ne/*xt*/(n+1, 0); 
    for (int i = 1 ; i <= m ; i++) {
        for (int j = 1 ; j <= n; j++) {
            if (a[i-1] == b[i-1]) {
                ne[j] = dp[j-1]+1;
            }
            else {
                ne[j] = max(ne[j-1], dp[j]);
            }
        }
        dp = ne;
    }
    cout << max(dp[n], ne[n]);

}