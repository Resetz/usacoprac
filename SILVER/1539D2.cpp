#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

bool visited[40];

int dp[40];
int arr[40];

int k;
int ans = -1;

void solve() {
    cin >> k;
    for (int i = 0 ; i < k; i++) {
        cin >> arr[i];
    }

    for (int i = 0 ; i < k ; i++) {
        int ans = arr[i];
        for (int j = 0 ; j < k ; i++) {
            
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}