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
int n;

int points[100000];

int main() {
    cin>>n;
    
    int window = 0;
    for (int i = 0; i < n; i++) {
        cin >> points[i];
        if (points[i] < n) {
            window++;
        }
    }
    sort(points, points+n);

    int ansMin = 0;
    int ansMax = 0;

    int streak = 1;
    int last = points[0];
    int done = false;
    int front = false;
    for (int i = 1; i < n; i++) {
        if (points[i] - last == 1) {
            streak++;
        } else {
            if (streak == n-1) {
                done = true;
                if (i == n-1) {
                    front = true;
                } else {
                    front = false;
                }
            } else {
                if (i != 1) {
                    break;
                } else {
                    streak = 0;
                }
            }
        }
        last = points[i];
    }
    bool calc = false;
    if (points[n-1] - points[1] == n-2 && points[1] - points[0] > 2 )  {
        ansMin = n - (2);
        calc = true;
        cout << n-ansMin<<endl;
    } else if (points[n-2] - points[0] == n-2 && points[n-1] - points[n-2] > 2 ) {
        ansMin = n - (2);
        calc = true;
        cout << n-ansMin<<endl;
    }
    
    int maxi = 0;
    if (!calc) {
        int next = 0;
        
        for (int i = 0; i < n; i++) {
            while (points[next+1] - points[i] < n && next < n-1) {
                next++;  
            } 
            maxi = max(next-i+1, maxi);
        }cout << n - maxi << endl;
    } 
    

    //max
    cout << max(points[n-2] - points[0], points[n-1] - points[1]) - (n-2);
} 