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
#include <fstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> v(100000, 0);
vector<pair<int,int>> v2;

#define foutt ofstream
#define fint ifstream


struct less_than_key
{
    inline bool operator() (const pair<int,int>& struct1, const pair<int,int>& struct2)
    {
        return (struct1.first < struct2.first) || (struct1.first == struct2.first && struct1.second < struct2.second);
    }
};


int main() {
    foutt fout;
    fint fin;
    fout.open("sort.out");
    fin.open("sort.in");

    
    int n;
    fin >> n;
    
    //pair<int,int> reverse[100000];
    
    for (int i = 0 ; i < n; i++) {
        fin >> v[i];
        v2.push_back(make_pair(v[i],i));
    }
    sort(v2.begin(), v2.end(), less_than_key());
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi,v2[i].second-i);
    }
    fout <<maxi+1<< endl;

    
}