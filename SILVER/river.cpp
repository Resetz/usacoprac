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

int n;
bool adj[52][52] = {{false}};
int dist[52][52];
bool visited[52] = {false};
int find(int from) {
    if (visited[from]) {
        return 0;
    }
    visited[from] = true;
    char c = from;
    if (from >= 0 && from < 26) c += 'A';
    else {c += 'a'; c -= 26;}
    //cout << "searching " << c << " " << from << endl;
    int total = 0;
    int resolve = -1;
    int reduce = 0;
    if (c == 'Z') {
        return -1;
    }
    for(int i = 0 ; i < 52 ; i ++) {
        if (adj[from][i]) {
            int res = find(i);
            if (res != 0 && resolve == -1) {
               //found Z
                resolve = i;
                reduce = res;
            } 
            if (res != 0) {
                total += dist[from][i];
            }
            total += min(0, res); 
        }
    }
    if (resolve == -1) {
        return 0;
    }

    dist[from][25] = min(total, dist[resolve][25]);
    for (int i = 0 ; i < n ; i++) {
        if (i != resolve) {
            dist[from][i] = 0;
        }
    }
    return dist[from][25];
}

int ans(int cur) {
    cout << cur << " > ";
    if (cur == 25) return 0;
    for (int i = 0 ; i < n ;i++) {
        if (dist[cur][i] != 0) return dist[cur][i] + ans(i);
    }
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
    cin >> n;
    //cout << "here";

    for (int i = 0; i < n; i++) {
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
        dist[(int) c][(int) d] = other;
    }

    find(0);
    cout << dist[0][25] << endl;
}