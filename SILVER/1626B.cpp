#include <iostream>
#include <vector>


using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> finished;
    bool d = false;
    int lastd = 0;
    int firstc = s.size()+1;
    for (int i = 1; i < s.size(); i++) {
        if ((s[i]-'0')+(s[i-1]-'0') >= 10) {
            finished.push_back((s[i]-'0')+(s[i-1]-'0'));
            d = true;
            lastd = i-1;
        } else {
            finished.push_back((s[i]-'0')+(s[i-1]-'0'));
            firstc = min(i-1, firstc);
        }
    }

    if (d) {
        for (int i = 0; i < s.size() ; i++) {
            if (i == lastd) {
                cout << finished[lastd];
                i++;
            } else {
                cout << s[i];
            }
        } 
    } else {
        for (int i = 0; i < s.size() ; i++) {
            if (i == firstc) {
                cout << finished[firstc];
                i++;
            } else {
                cout << s[i];
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) solve();
}