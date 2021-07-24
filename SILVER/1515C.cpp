#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

int ncases;
int n, m, x;
int i, j;

vector<pair<int, int>> towers;
vector<int> blocks;
int main() {
    cin >> ncases;
    while (ncases--) {

        
        cin >> n >> m >> x;

        

        for(i=0;i<n;i++) {
            int temp = 0;
            cin>>temp;
            blocks.push_back(temp);
        }

        sort(blocks.begin(), blocks.end());
        cout << "YES\n";
        for(i=0;i<m;i++) {
            pair<int, int> temp = {0, i};
            towers.push_back(temp);
        }
        for(i=0;i<n;i++) {
            int index = 0;
            int mini = towers[0].first;
            for(j=0;j<m;j++) {
                if (mini > towers[j].first) {
                    index = j;
                }
            }
            towers.erase(towers.begin()+index);
            pair<int, int> temp = {index, towers[index].second+blocks[i]};
            cout << index+1 << " ";
    
            towers[j] = temp;
        }
        
        cout << "\n";
    }

}