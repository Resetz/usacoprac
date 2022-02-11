#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    set<string> before;
    set<string> after;
    set<string> all;

    for (int i = 0 ; i < n; i++) {
        cin >> v[i];
        after.insert(v[i]);
        all.insert(v[i]);
    }

    // ab cba
    // ab cdc ba

    for (int i = 0 ; i < n; i++) {
        //remove the first character;
        string temp = v[i];
        reverse(v[i].begin(), v[i].end());
        string newstring = v[i];
        //cout << "1 looking for " << newstring << endl; 
        if (all.find(newstring) != all.end()) {
            cout << "YES" << endl;
            return;
        } else {
            newstring = newstring.substr(1);
            //cout << "2 looking for " << newstring << endl; 
            if (after.find(newstring) != after.end()) {
                cout << "YES" << endl;
                return;
            } else if (v[i].size() >= 2) {
                newstring = v[i].substr(0, 2);
                //cout << "3 looking for " << newstring << endl; 
                if (before.find(newstring) != before.end()) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        after.erase(temp);
        before.insert(temp);
    }
    cout << "NO" << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}