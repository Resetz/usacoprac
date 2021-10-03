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


int tonum(char c) {
    int i = c;
    if (i >= 'A' && i <= 'Z') i -= 'A';
    if (i >= 'a' && i <= 'z') i -= 'a';
    return i;
}

void resolve(int i) {
    int a = 0; int alast = 0;
    int b = 0; int blast = 0;
    if (i == 0 && i == 25) return;
    for (int j = 0 ; j < 52; j++) {
        if (dist[i][j] > 0) {a++; alast = j;}
        if (dist[j][i] > 0) {b++; blast = j;}
    }
    if (a <= 1 || b <= 1) return;
    dist[blast][alast] += min(dist[i][alast], dist[blast][i]);
    dist[blast][i] = dist[i][alast] = 0;
    resolve(alast);
    resolve(blast);

}

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        char f, t;
        int num;
        cin >> f >> t >> num;
        int ft = tonum(f);
        int tt = tonum(t);
        adj[ft][tt] = true;
        adj[tt][ft] = true;
        dist[ft][tt] = dist[tt][ft]= num;
    }
    for (int i = 0 ; i < 52 ;i++) {
        for (int j = 0 ; j < 52 ; j++) {
            if (adj[i][j]) {
                for (int k = 0 ; k < 52; k++) {
                    if (adj[j][k]) {
                        dist[i][k] = min(dist[i][j], dist[j][k]);
                        adj[i][j] = false;
                        adj[j][k] = false;
                        dist[i][j] = dist[j][k] = 0;
                    }
                }
            }
        }
    }
    
    for (int i = 0 ; i < 52 ; i ++) {
        resolve(i);
    }
    cout << dist[0][25] << endl;
}