#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

#define all(n) n.begin(), n.end()
using namespace std;

int n = 52;
int N;
bool adj[52][52] = {{false}};
int dist[52][52];
bool visited[52] = {false};

int resolve(int root, int cur, int cur_dist) {
    //check the ones that connect to cur
    //if there is one (assumes the one that it came from is now deleted)
    //resolve the current string of rivers (connect root to cur).
    for (int i = 0 ; i < n ; i++) {
        if (adj[i][cur]) {
            //cout << root << " and " << cur << " resolved to " << cur_dist << endl;
            adj[root][cur] = true;
            dist[root][cur] += cur_dist;
            return -1;
        }
    } 

    //check for the ones that cur connects to.
    //if there are more than two that connect to cur
    //resolve the current string of rivers (connect root to cur)
    int count = 0;
    int go = 0;
    for (int i = 0; i < n ; i++) {
        if (adj[cur][i]) {count++; go = i;}
        if (count >= 2) {
            //connect root to cur.
            adj[root][cur] = true;
            dist[root][cur] += cur_dist;
            //cout << root << " and " << cur << " resolved to " << cur_dist << endl;
            return -1;
        }
    }
    if (count == 0) {
        if (cur == 25) {
            adj[root][cur] = true;
            dist[root][cur] += cur_dist;
            //cout << root << " and " << cur << " resolved to " << cur_dist << endl;
        }
        return -1;
    }
    //if the flow is smaller than the current flow, set the current flow to the flow.
    cur_dist = min(cur_dist, dist[cur][go]);

    //remove the link from cur to go, this is the only time to remove it.
    dist[cur][go] = 0;
    adj[cur][go] = false;
    resolve(root, go, cur_dist);
    return 0;
}

int main() {

    for (int i = 0 ; i < 52 ; i++) {
        for (int j = 0 ; j < 52 ; j++) {
            dist[i][j] = 0;
        }
    }

    char c, d;
    int other;
    cin >> N;
    //cout << "here";

    for (int i = 0; i < N; i++) {
        cin >> c;
        cin >> d;
        cin >> other;
        if (c >= 'A' && c <= 'Z') c -= 'A';
        if (c >= 'a' && c <= 'z') {c -= 'a'; c += 26;}
        if (d >= 'A' && d <= 'Z') d -= 'A';
        if (d >= 'a' && d <= 'z') {d -= 'a'; d += 26;}
        //cout << (int) c << " " << (int) d <<endl;
        adj[(int) c][(int) d] = true;
        //adj[d][c] = true;
        dist[(int) c][(int) d] += other;
    }

    bool keep_going = true;
    while (keep_going) {
        keep_going = false;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
            
                if (adj[i][j]) {
                    int prev = dist[i][j];
                    dist[i][j] = 0;
                    adj[i][j] = false;
                    if (resolve(i, j, prev) == 0) keep_going = true;
                }
            }
        }
    }
    
    for (int i = 0 ; i < n ; i ++) {
        if (adj[0][i]) {
            int prev = dist[0][i];
            dist[0][i] = 0;
            adj[0][i] = false;
            resolve(0, i, prev);
            break;
        }
    }
    cout << dist[0][25] << endl;
}