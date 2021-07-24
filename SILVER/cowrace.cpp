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
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


using namespace std;

int n,m;

int bessieSpeed[1000000];
vector<int> elsieSpeed;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    int current = 0;
    for (int i = 0; i < n; i++) {
        int time, speed;
        cin >> speed >> time;
        for (int j = 0; j < time; j++) {
            bessieSpeed[current + j] = speed;
        }
        current += time;
    }

    int currentm = 0;
    for (int i = 0; i < m; i++) {
        int time, speed;
        cin >> speed >> time;
        for (int j = 0; j < time; j++) {
            elsieSpeed.push_back(speed);
        }
        currentm += time;
    }

    int countingUntil = max(currentm, current);
    long long bessiePos = 0;
    long long elsiePos = 0;
    int prev = 0;
    int ans = 0;
    for (int i = 0 ; i < countingUntil; i++) {
        
        if (i < current) {
            bessiePos+=bessieSpeed[i];
        }
        if (i < currentm) {
            elsiePos+=elsieSpeed[i];
        }
        //cout << bessiePos << " " << elsiePos;

        int first = 0;
        if (bessiePos > elsiePos) {
            first = 1;
        } else if (elsiePos > bessiePos) {
            first = -1;
        } else {
            first = 0;
        }
        if (first != 0 && first != prev) {
            //cout << " <";
            ans++;
        }
        //cout << " " << first;

        if (bessiePos > elsiePos) {
            prev = 1;
        } else if (elsiePos > bessiePos) {
            prev = -1;
        } else {
            prev = 0;
        }
        //cout << endl;
    }
    if (ans > 0) {
        cout << ans-1;
    } else {
        cout << ans;
    }

}