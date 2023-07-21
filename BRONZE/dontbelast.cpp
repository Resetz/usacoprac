#include <algorithm>
#include <iostream>
#include <vector> //a vector is also a list
#include <set>
#include <map> //also known as dictionary in other languages

using namespace std;
int main() {
    int n;
    cin >> n;

    set<string> cows;
    map<string, int> milkAmounts;
    for (int i = 0 ; i < n ; i++) {
        string cowName;
        int amount;
        cin >> cowName >> amount;

        //if we have not found the current cow
        if (cows.find(cowName) != cows.end()) {
            milkAmounts[cowName] = amount;
        } else {
            //otherwise
            milkAmounts[cowName] += amount;
        }
        cows.insert(cowName);
    }

    vector<pair<int, string>> v;
    //iterate through the set
    //the implentation of this is different for each language
    for (auto it = cows.begin(); it != cows.end() ; it++) {
        v.push_back(pair<int,string>{milkAmounts[*it], *it});
    }
    //sorts greatest to least by the amount of milk
    sort(v.begin(), v.end());
    cout << v[1].second << endl;
}