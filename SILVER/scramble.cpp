//use lower_bound and upper_bound functions to find the location of a value
//lower_bound and upper_bound take (vector.begin(), vector.end(), value);
//lower_bound will find the first occurance of value and return the index before it.
//upper_bound will find the last occurance of value and return the index after it 


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

vector<string> s;
vector<string> s2;
vector<string> s2o;
vector<string> so;

int n;
int i, j;
vector<string>::iterator top, low;

int main() {
    cin >> n;
    
    for(i=0;i<n;i++) {
        string stringIn;
        cin >> stringIn;
        
        sort(stringIn.begin(), stringIn.end());

        s.push_back(stringIn);
        so.push_back(stringIn);
        reverse(stringIn.begin(), stringIn.end());
        s2.push_back(stringIn);
        s2o.push_back(stringIn);
    }
    
    

    sort(s.begin(), s.end());
    sort(s2.begin(), s2.end());
    //reverse(s2.begin(), s2.end());
    //cout << endl;
    /*
    for(i=0;i<n;i++) {
        cout << s[i] << ", ";
    }
    cout << endl;
    for(i=0;i<n;i++) {
        cout << s2[i] << ", ";
    }
    cout << endl;*/
    int j;
    int index = 0;
    for (i=0;i<n;i++) {
        top = upper_bound(s.begin(), s.end(), s2o.at(i));
        low = lower_bound(s2.begin(), s2.end(), so.at(i));
        cout << (low-s2.begin())+1 << " " << (top-s.begin()) << endl;
    }

    



}