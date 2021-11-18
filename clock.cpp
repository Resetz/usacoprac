/* 
1        1 2 4 5
2        1 2 3
3        2 3 5 6
4        1 4 7
5        2 4 5 6 8
6        3 6 9
7        4 5 7 8
8        7 8 9
9        5 6 8 9
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

vector<int> v[10] {
    {1,2,4,5},
    {1,2,3},
    {2,3,5,6},
    {1,4,7},
    {2,4,5,6,8},
    {3,6,9},
    {4,5,7,8},
    {7,8,9},
    {5,6,8,9}
};

set<vector<int>> sv;
vector<int> current;

typedef struct node {
    vector<int> s;
    vector<int> moves;
    int t;
} node_t;


int main() {
    vector<int> r;
    current.resize(9);
    for (int i = 0 ; i < 9; i++) {
        int x;
        cin >> x;
        x = (x/3) % 4;
        current[i] = x;
    }
    
    queue<node_t> q;
    node_t o;
    o.s = current;
    o.t = 0;
    q.push(o);
    while (!q.empty()) {
        o = q.front();
        q.pop();

        bool good = true;
        for (int i = 0 ; i < 9 ; i++) {
            if (o.s[i] != 0) {
                good = false;
            }
        }
        if (good) {
            for (int i = 0; i < o.t; i++) {
                cout << o.moves[i] << " ";
            }
            return 0;
        }

        o.t++;
        for (int i = 0 ; i < 9 ; i++) {
            for (int j = 0 ; j < v[i].size(); j++) {
                o.s[v[i][j]-1] = (o.s[v[i][j]-1] + 1) % 4;
            }
            if (sv.insert(o.s).second) {
                o.moves.push_back(i+1);
                q.push(o);
                o.moves.pop_back();
            }
            for (int j = 0 ; j < v[i].size(); j++) {
                
                o.s[v[i][j]-1] = (o.s[v[i][j]-1] - 1);
                if (o.s[v[i][j]-1] < 0) {
                    o.s[v[i][j]-1] = 3;
                } 
            }
        }
    }


}