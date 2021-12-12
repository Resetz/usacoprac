#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

void solve() {
    int n;
    vector<int> ans;
    vector<pair<int,int>> c;
    for (int i = 0 ; i < n ; i++) {
        int k;
        cin >> k;
        c.push_back({k,i});
    }
    sort(c.begin(),c.end(), [](pair<int,int> a, pair<int,int> b) -> {
        return a.first < b.second;
    });
}

int main () {
    int n;
    cin >> n;
    while (n--) {solve();}
}