/*
Bessie is stranded on a deserted arctic island and wants to determine
all the paths she might take to return to her pasture. She has
tested her boat and knows she can travel from one island to another
island in 1 unit of time if a route with proper currents connects
the pair.

She has experimented to create a map of the ocean with valid
single-hop routes between each pair of the N (1 <= N <= 100) islands,
conveniently numbered 1..N. The routes are one-way (unidirectional),
owing to the way the currents push her boat in the ocean. It's
possible that a pair of islands is connected by two routes that use
different currents and thus provide a bidirectional connection. The
map takes care to avoid specifying that a route exists between an
island and itself.

Given her starting location M (1 <= M <= N) and a representation
of the map, help Bessie determine which islands are one 'hop' away,
two 'hops' away, and paths to an island, consider only the path with the shortest distance.
so on. If Bessie can take multiple different

By way of example, below are N=4 islands with connectivity as shown
(for this example, M=1):

       start--> 1-------->2
                |         |
                |         |
                V         V
                4<--------3

Bessie can visit island 1 in time 0 (since M=1), islands 2 and 4
at time 1, and island 3 at time 2.

The input for this task is a matrix C where a nonzero entry C_rc
(0 <= C_rc <= 1) in row r and column c means "Currents enable Bessie
to travel directly from island r to island c in one time unit". Row
C_r has N elements, respectively C_r1..C_rN, each one of which is
0 or 1.

PROBLEM NAME: pathfind

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 contains N space-separated integers: C_r

SAMPLE INPUT:

4 1
0 1 0 1
0 0 1 0
0 0 0 1
0 0 0 0

OUTPUT FORMAT:

* Lines 1..???: Line i+1 contains the list of islands (in ascending
        numerical order) that Bessie can visit at time i.  Do not
        include any lines of output after all reachable islands have
        been listed.

SAMPLE OUTPUT:

1
2 4
3
*/


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

using namespace std;

int n, start;
bool grid[100][100];

vector<pair<int, int>> q; 
//           1.   2.
// 1 (first). row / island #
// 2 (second). time taken
map<int, vector<int>> total;
bool visited[100];
int main()  {
    cin >> n >> start;

    for (int i = 0 ; i < n; i ++ ) { 
        for (int j = 0 ; j < n; j ++ ) { 
            cin >> grid[i][j];
        }
    }
    start--;
    total[0].push_back(start);
    visited[start] = true;
    for (int i = 0 ; i < n; i ++) {
        if (grid[start][i]) {
            q.push_back(make_pair(i, 1));
        }
    }
    while (q.size() != 0) {
        pair<int, int> next = q[0];
        q.erase(q.begin());
        if (visited[next.first]) {
            continue;
        } else { 
            total[next.second].push_back(next.first);
            visited[next.first] = true;
            for (int i = 0 ; i < n; i ++) {
                if (grid[next.first][i]) {
                    q.push_back(make_pair(i, next.second + 1));
                }
            }
        }
    }
    for (pair<int, vector<int>> p : total) {
        sort(p.second.begin(), p.second.end());
        for (int i = 0; i < p.second.size(); i++) {
            cout << p.second[i] + 1 << " ";
        }
        cout << endl;
    }
}
