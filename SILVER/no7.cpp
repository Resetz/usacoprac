#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool downone = false;
    bool need = false;
    int ind = -1;
    for (int i = 0 ; i < s.size() ; i++) {
        if (s[i] == '7') {
            ind = i;
            break;
        }
    }
    if (ind != -1) {
        s[ind] = '6';
        for (int i = ind+1 ; i < s.size() ; i++) {
            s[i] = '9';
        }
    } else {
        for (int i = s.size()-1 ; i >= 0 ; i--) {
            if (s[i] == '0') {
                s[i] = '9';
            } else {
                s[i]--;
                if (s[i] == '7') s[i]--;
            }
        }
    }
    cout << s << endl;

}