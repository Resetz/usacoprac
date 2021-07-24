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
//x,y;
//pair<int,int> points[100000];
vector<pair<int,int>> points;

pair<vector<vector<int>>,long long> find_answers(vector<int> to_ignore) {
    pair<vector<vector<int>>,long long> ret;
    int maxX = -1000000000;
    int maxY = -1000000000;
    int minX = 1000000000;
    int minY = 1000000000;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < to_ignore.size(); j++) {
            if (i == to_ignore[j]) {
                found = true;
                break;
            }
        }
        if (found) continue;
        maxX = max(maxX, points[i].first);
        maxY = max(maxY, points[i].second);
        minX = min(minX, points[i].first);
        minY = min(minY, points[i].second);
    }
    //area
    ret.second = (maxX-minX)*(maxY-minY);

    //check for borders
    vector<int> top, bottom, left, right;
    for (int i  = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < to_ignore.size(); j++) {
            if (i == to_ignore[j]) {
                found = true;
                break;
            }
        }
        if (found) continue;
        if (points[i].first == maxX) right.push_back(i);
        if (points[i].first == minX) left.push_back(i);
        if (points[i].second == maxY) top.push_back(i);
        if (points[i].second == minY) bottom.push_back(i);
    }
    //if there is more than 3, it's not possible and doesn't make sense to use it as borders;
    if (right.size() <= 3) ret.first.push_back(right);
    if (left.size() <= 3) ret.first.push_back(left);
    if (top.size() <= 3) ret.first.push_back(top);
    if (bottom.size() <= 3) ret.first.push_back(bottom);
    return ret;    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        points.push_back(p);
    }

    /*
    for (int i = 0; i < n; i ++ ) {

    }
    for (int i = 0; i < 257; i++) {
        int /////
        
        
        
        
        
        
        'right = i & !3;
        int left = i >> 2 & !3;
        int up = i >> 4 & !3;
        int down = i >> 6 & !3;
        if (right + up + left + down == 0) {

        }
    } 
    */
    // check for borders 4 times;

    long long minArea = 40000*40000;
    pair<vector<vector<int>>,long long> a = find_answers(vector<int>());
    for (vector<int> to_remove1 : a.first) {
        pair<vector<vector<int>>,long long> b = find_answers(to_remove1);
        //cout << b.second << endl;
        if (minArea > b.second) {
            minArea = b.second;
        }
        
        for (vector<int> to_remove2 : b.first) {
            if (to_remove1.size() + to_remove2.size() <= 3) {
                for (int p : to_remove1) {
	                to_remove2.push_back(p);
	            }
                pair<vector<vector<int>>,long long> c = find_answers(to_remove2);
                //cout << c.second << endl;
                if (c.second < minArea) {
                    minArea = c.second;
                }
                for (vector<int> to_remove3 : c.first) {
                    if (to_remove2.size() + to_remove3.size() <= 3) {
                        for (int p : to_remove2) {
                            to_remove3.push_back(p);
                        }
                        pair<vector<vector<int>>,long long> d = find_answers(to_remove3);
                        //cout << d.second << endl;
                        if (d.second < minArea) {
                            minArea = d.second;
                        }
                    }
                }
            }
        }
    }
    cout << minArea;
}