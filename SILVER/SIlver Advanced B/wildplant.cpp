#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
int n;

vector<pair<int,bool>> fruits;
int dp[100000];
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int l;
        char t;
        cin >> l >> t;
        fruits.push_back({l, t == 'A'});
    }

    map<int,vector<int>> pref;

    sort(fruits.begin(),fruits.end());
    vector<pair<int,int>> intervals;
    int current = 0;
    pref[0].push_back(0);
    for (int i = 0 ; i < n ; i++) {
        current += fruits[i].second ? 1 : -1;
        //cout << current << " " << fruits[i].second << endl;
        if (pref.find(current) == pref.end()) {
            pref[current].push_back(i+1);
        } else {
            for (int j = 0 ; j < pref[current].size() ; j++) {
                intervals.push_back({pref[current][j], i});
            }
            //cout << pref[current]-1 << " " << i << endl;
        }
    }

    char letter = fruits[0].second;
    int first = 0;
    int last = 0;
    for (int i = 1 ; i < n ; i++) {

        if (fruits[i].second != letter) {
            intervals.push_back({first, last});
            first= i;
            letter = fruits[i].second;
        } 
        last = i;
    }
    intervals.push_back({first, n-1});




    sort(intervals.begin(), intervals.end(), [](pair<int,int> a, pair<int,int> b) -> int {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;

    });

    current = intervals.size()-1;
    int prev = -1;
    pair<int,int> best = intervals[intervals.size()-1];

    for (int i = n-1; i >= 0 ; i--) {
        if (current != -1) {
            while (current > 0 && intervals[current].first >= i) {
                /*if (current == 3) {
                    cout << fruits[best.second].first - fruits[best.first].first << " " << fruits[intervals[current].second].first - fruits[intervals[current].first].first << endl;
                }*/
                if (fruits[intervals[current].second].first - fruits[intervals[current].first].first >=\
                    fruits[best.second].first - fruits[best.first].first) {
                    prev = current;
                    best = intervals[current];
                }
                current--;
            }
        }
        dp[i] = prev;

        //cout << dp[i] << " ";
    }
    
    //cout << endl;
    int ans = 0;
    for (int i = 0 ; i < intervals.size() ; i ++ ) {
        //cout << intervals[i].first << " " << intervals[i].second << endl;
        int endpoint = intervals[i].second ;
        if (dp[endpoint] != -1) {
            ans = max(fruits[intervals[dp[endpoint]].second].first - fruits[intervals[dp[endpoint]].first].first
                + fruits[intervals[i].second].first - fruits[intervals[i].first].first, ans);

        }
    }
    if (intervals.size() == 1) {
        cout << intervals[0].second - intervals[0].first << endl;
        return 0;
    }
    cout << ans << endl;

}