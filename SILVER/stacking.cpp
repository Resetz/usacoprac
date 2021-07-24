#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <set>

using namespace std;


vector<pair<int, int>> d;

vector<pair<int,int>> d2;
unordered_map<int, int> c;
int main() {
    int n;
    int m;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int end, start;
        cin >> start >> end;

        pair<int,int> p(start,1);
        d2.push_back(p);
        pair<int,int> p2(end,-1);
        d2.push_back(p2);
    }
    
    sort(d2.begin(), d2.end());

    int prev = 1;
    int prevamt;
    int prevprevamt;
    int last = 0;
    vector<int> left;
    for(int i = 0; i < n*2; i++) {
        prevamt = left.size();
        if (d2[i].second == 1) {
            left.push_back(d2[i].first);
        } else {
            remove(left.begin(), left.end(), d2[i].first);
        }
        if (prevamt < left.size()) {
            c[prevamt] += d2[i].first - prev + 1;
        } else {
            c[prevamt] += d2[i].first - prev;
        }
        prev = d2[i].first;
    }
    c[left.size()] += d2[n*2-1].first - prev+1;
    int sum =1;
    cout << endl;
    for (int i = 0; i < m; i++) {
        cout << c[i] << ", ";
        sum += c[i];
    }
    prev = 0;
    sum /= 2;
    int i = 0;
    for (i = 0; i < n; i++) {
        if (prev > sum) {
            break;
        }
        prev += c[i];
    }
    cout << i;
}