/*
ID: vincent97
TASK: combo
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {

    #ifndef LOCAL
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    #endif

    int n, m, c;
    vector<int> first(3);
    vector<int> second(3);
    cin >> n;
    cin >> first[0] >> first[1] >> first[2];
    cin >> second[0] >> second[1] >> second[2];

    set<pair<pair<int,int>,int>> s;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                s.insert({{(first[0]+i+n)%n,(first[1]+j+n)%n},(first[2]+k+n)%n});
            }
        } 
    }
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                s.insert({{(second[0]+i+n)%n,(second[1]+j+n)%n},(second[2]+k+n)%n});
            }
        }
    }
    cout << s.size() << endl;
}