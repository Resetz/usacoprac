#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n*2, vector<int>());
    vector<vector<int>> vgrid(n*2, vector<int>());
    for (int i = 0 ; i  < n ;i++) {
        string s; cin >> s;
        for (int j = 0 ; j < n ; j++) {
            if (s[j] == '*') {
                pair<int,int> p = {i-j+n,i+j};
                //cout << p.first << " " << p.second << endl;
                grid[p.first].push_back(p.second);
                vgrid[p.second].push_back(p.first);
            }
        }
    }
    for (int i = 0 ; i < 2*n ; i++) {
        sort(grid[i].begin(), grid[i].end());
        sort(grid[i].begin(), grid[i].end());
    }

    vector<vector<int>> pf(2*n, vector<int>(2*n));
    int ans = 0;
    for (int i = 0 ; i < 2*n ; i++) {
        // horizontal line
        int col = i;
        vector<int> v = grid[i];
        
        for (int i = 0 ; i < v.size() ; i++) {
            for (int j = i+1 ; j < v.size() ; j++) {
                if (v[j]-v[i]+col < 2*n) {
                    pf[v[j]-v[i]+col][v[i]]++;
                    pf[v[j]-v[i]+col][v[j]+1]--;
                }
                if (-(v[j]-v[i])+col >= 0) {
                    pf[-(v[j]-v[i])+col][v[i]]++;
                    pf[-(v[j]-v[i])+col][v[j]+1]--;
                }
            }
        }
    }
    for (int i = 0 ; i < 2*n ; i++) {
        int cur = 0;
        int pos = 0;
        for (int j = 0 ; j < 2*n ; j++) {
            cur += pf[i][j];
            //cout << pf[i][j] << " ";
            if (pos < grid[i].size() && grid[i][pos] == j) {
                ans+=cur;
                pos++;
                
            }
            pf[i][j] = 0;
        }
        //cout << endl;
    }
    //cout << "here" << endl;
    for (int i = 0 ; i < 2*n ; i++) {
        // vertical line
        vector<int> v = vgrid[i];
        int row = i;
        
        for (int i = 0 ; i < v.size() ; i++) {
            for (int j = i+1 ; j < v.size() ; j++) {
                if (v[j]-v[i]+row < 2*n) {
                    pf[v[j]-v[i]+row][v[i]+1]++;
                    pf[v[j]-v[i]+row][v[j]]--;
                }
                if (-(v[j]-v[i])+row >= 0) {
                    pf[-(v[j]-v[i])+row][v[i]+1]++;
                    pf[-(v[j]-v[i])+row][v[j]]--;
                }
            }
        }
    }

    for (int i = 0 ; i < 2*n ; i++) {
        int cur = 0;
        int pos = 0;
        for (int j = 0 ; j < 2*n ; j++) {
            cur += pf[i][j];
            //cout << pf[i][j] << " ";
            if (pos < vgrid[i].size() && vgrid[i][pos] == j) {
                ans+=cur;
                pos++;
            }
            pf[i][j] = 0;
        }
        //cout << endl;
    }
    cout << ans << endl;
}