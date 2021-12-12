#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int go[52];
    for (int i = 0; i < n ; i++) {
        if (islower(s[i])) {
            go[s[i]-'a']++;
        } else {
            go[s[i]-'A']++;
        }
    }


    //go right
    int low = 0;
    for ( ; low < n ; low++) {
        int ind = 0;
        if (islower(s[low])) {
            ind = s[low] - 'a';
        } else {
            ind = s[low] - 'A';
        }

        if (go[ind] == 1) {
            break;
        } else {
            ind--;
        }
    }

    //go left;
    int high = n-1;
    for (; high >= 0 ; high++) {
       int ind = 0;
        if (islower(s[high])) {
            ind = s[high] - 'a';
        } else {
            ind = s[high] - 'A';
        }

        if (go[ind] == 1) {
            break;
        } else {
            ind--;
        }
    }
    cout << high - low + 1 << endl;
}