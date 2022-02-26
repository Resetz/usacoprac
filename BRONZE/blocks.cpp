#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<set<char>> dice(4);
    char num;
    for (int i = 0 ; i < 4 ; i++) {
        for (int j = 0 ; j < 6; j++) {
            cin >> num;
            dice[i].insert(num);
        }
    }

    for (int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;

        int good = false;
        vector<int> perm;
        for (int j = 0 ; j < 4 ; j++) {
            perm.push_back(j);
        }
        do {
            bool found = true;
            for (int j = 0 ; j < s.length() ; j++) {
                //cout << perm[j] << " ";
                if (dice[perm[j]].find(s[j]) == dice[perm[j]].end()) {
                    found = false;
                }
            }
            //cout << endl;
            if (found) {
                good = true;
                break;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        
        if (good) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}