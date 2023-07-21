#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> dict;
    string s;
    cin >> s;
    while (s != ".") {
        dict.push_back(s);
        cin >> s;
    }

    s = "";
    string temp;
    while (cin >> temp) {
        s += temp;
    }


    vector<bool> dp(s.size()+1, false);
    dp[0] = true;

    for (int i = 0 ; i < dp.size() ; i++ ) {
        if (dp[i] == false) {
            continue;
        } else {
            for (int j = 0 ; j < dict.size() ; j++) {
                if (i + dict[j].size() > s.size()) break;
                bool good = true;
                for (int k = 0 ; k < dict[j].size() ; k++) {
                    if (s[i+k] != dict[j][k]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    dp[i + dict[j].size()] = good;
                    //cout << i + dict[j].size() << " is good " << " " << dp[i + dict[j].size()] << endl;
                }
            } 
        }
    }
    int ans = 0;
    for (int i = 0 ; i < dp.size() ; i++) {
        //cout << dp[i] << endl;
        if (dp[i]) {
            ans = i;
            //cout << ans << " " << i << endl;
        }
    }
    cout << ans << endl;
}