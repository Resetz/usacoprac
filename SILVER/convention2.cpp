#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;
struct cow {
    int start;
    int end;
    int id;
};
vector<cow> cows;



struct less_than_key
{
    inline bool operator() (const cow& struct1, const cow& struct2)
    {
        if (struct1.start == struct2.start) {
            return struct1.id < struct2.id;
        }
        return struct1.start  < struct2.start;
    }
};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int start;
        int end;
        cin >> start >> end;
        cow c;
        c.start = start;
        c.end = c.end;
        c.id = i;
        cows.push_back(c);
    } 

    sort(cows.begin(), cows.end(), less_than_key());
    cow eatingCow;
    eatingCow.start = -1;
    eatingCow.end = -1;
    int current = 0;
    int longest = 0;
    for (int i = 0; i < n; i++) {
        if (eatingCow.start + eatingCow.end > cows[i].start) {
            if (i == 0) {
                eatingCow = cows[i];
            } else {
                longest = max(longest, (eatingCow.start + eatingCow.end) - cows[i].start);
            }
        } 
        eatingCow = cows[i];
    }
    cout << longest;
}