// problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// same idea as closest cow wins.
// sort the array based on best if you choose 1, then add an extra entry if you choose two.


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            if (prices.size() == 0) return 0;
            stack<pair<int,int>> intervals;
            vector<int> profits;

            int last = 0;
            while (true) {
                if (last == prices.size()-1) break;
                int valley = last;
                int peak;
                while (last+1 < prices.size() && prices[last] >= prices[last+1]) {
                    last++;
                }
                valley = last;
                while ((last+1 < prices.size() && prices[last] <= prices[last+1])) {
                    last++;
                }
                peak = last;
                
                if (prices[peak] <= prices[valley]) continue;
                
                while (intervals.size() > 0 && prices[intervals.top().first] >= prices[valley]) {
                    profits.push_back(prices[intervals.top().second] - prices[intervals.top().first]);
                    intervals.pop();
                }
                while (intervals.size() > 0 && prices[intervals.top().second] < prices[peak]) {
                    int profit = prices[intervals.top().second] - prices[valley];
                    if (profit > 0) profits.push_back(profit);
                    valley = intervals.top().first;
                    intervals.pop();
                }
                intervals.push({valley, peak});
            }

            long long ans = 0;
            cout << intervals.size() << endl;
            while (intervals.size() > 0) {
                profits.push_back(prices[intervals.top().second] - prices[intervals.top().first]);
                cout << prices[intervals.top().second] - prices[intervals.top().first] << endl;
                intervals.pop();
            }
            sort(profits.rbegin(), profits.rend());
            for (int i = 0 ; i < k && i < profits.size(); i++) {
                cout << "profit of " << profits[i] << endl;
                ans += profits[i];
            }
            return ans;
        }
};