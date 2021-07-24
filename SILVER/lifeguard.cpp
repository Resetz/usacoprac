#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int a, b, c;
int n, m;
int i, j, k;

struct interval {
    int type;
    int id;
    int pos;
};
struct less_than_key
{
    inline bool operator() (const interval& struct1, const interval& struct2)
    {
        if (struct1.pos == struct2.pos) {
            return struct1.type < struct2.type;
        }
        return (struct1.pos < struct2.pos );
    }
};

vector<interval> intervals;
unordered_map<int, int> totals;
unordered_map<int, int> starts;

unordered_set<int> current;

vector<int> ans;
int heights[1000000];
int main() {
    cin >> n;

    for (i=0;i<n;i++) {
        int start, end;
        cin >> start >> end;
        heights[start]++;
        heights[end+1]--;
    }

    //int total = 0;
    int currentHeight = 0;
    /*int stacks[1000000];*/
    vector<int> stacks;
    for(int i = 0;i < 100000; i++) {
        /*
        if (heights[i] > 0) {
            currentHeight ++;
        }*/
        currentHeight += heights[i];
        //total += currentHeight;
        stacks.push_back(currentHeight);
    }
    sort(stacks.begin(), stacks.end());
    cout << stacks[n/2];

    
}