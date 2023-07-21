    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <climits>

    using namespace std;

    int main() {
        int n,l;
        cin >> n >> l;

        vector<int> v(n);
        int left, right;
        left = right = 0;

        for (int i = 0 ; i < n ; i++) {
            cin >> v[i];
            if (v[i] < l) left++;
            if (v[i] >= l) right++;
        }
        int mid = left;
        
        
        sort(v.begin(), v.end());
        vector<int> toleft(left+1);
        vector<int> toright(right+1);
        toleft[0] = l;
        toright[0] = l;
        for (int i = left-1 ; i >= 0 ; i--) {
            toleft[left-i] = v[i];
        }
        for (int i = 0 ; i < right ; i++) {
            toright[i+1] = v[mid+i];
        }


        vector<vector<int>> dp[2];
        for (int i = 0 ; i < 2; i++) {
            dp[i].resize(left+1, vector<int>(right+1,INT_MAX));
        }
        dp[0][0][0] = 0; // on left
        dp[1][0][0] = 0;
        for (int i = 0 ; i <= left ; i++) {
            for (int j = 0 ; j <= right ; j++) {
                for (int k = 0 ; k < 2 ; k++) {
                    if (dp[k][i][j] != INT_MAX) {
                        //cout << k << " " << i << " " << j << " " << dp[k][i][j] << endl;
                        if (k == 0) {
                            if (i+1 <= left)
                            dp[0][i+1][j] = min(dp[0][i+1][j], dp[k][i][j]+(n-i-j)*(toleft[i]-toleft[i+1]));
                            if (j+1 <= right)
                            dp[1][i][j+1] = min(dp[1][i][j+1], dp[k][i][j]+(n-i-j)*(toright[j+1]-toleft[i]));
                        } else {
                            if (i+1 <= left)
                            dp[0][i+1][j] = min(dp[0][i+1][j], dp[k][i][j]+(n-i-j)*(toright[j]-toleft[i+1]));
                            if (j+1 <= right)
                            dp[1][i][j+1] = min(dp[1][i][j+1], dp[k][i][j]+(n-i-j)*(toright[j+1]-toright[j]));
                        }
                    }
                }
            }
        }
        cout << min(dp[0][left][right], dp[1][left][right]) << endl;
    }