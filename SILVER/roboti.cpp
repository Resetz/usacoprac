#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    map<pair<int,int>,int> cm;
    set<pair<int,int>> cs;
    map<pair<int,int>,int> nm;
    set<pair<int,int>> ns;
    for (int i = 0 ; i <n ; i ++) {
        cin >> v[i].first >> v[i].second;
        cm[v[i]] = 1;
        cs.insert(v[i]);
    }
    sort(v.begin(), v.end());


    for (int i = 0 ; i < n ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            for (int k = j+1 ; k < n ; k++) {
                for (int a = k+1 ; a < n ; a++) {

                }
            }
        }
    }


    

}