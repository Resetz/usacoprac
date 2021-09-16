#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<unordered_set<string>> palin(18);
unordered_set<string> ans;
int k;
int N;
char grid[18][18];

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
string s;
void fromTop(int r, int c) {
    if (r >= N || c >= N || c < 0 || r < 0) {
        return;
    }
    s += grid[r][c];
    if (s.size() == N) {
        palin[c].insert(s);
        s.erase(s.end()-1);
        //cout << "inserting " << s << endl;
        return;
    }
    for (int i = 0 ; i < 2 ; i++ ) {
        fromTop(r+di[i], c+dj[i]);
    }
    s.erase(s.end()-1);
}

void fromBot(int r, int c) {
    if (r >= N || c >= N || c < 0 || r < 0) {
        return;
    }
    s += grid[r][c];
    if (s.size() == N) {
        if (palin[c].find(s) != palin[c].end()) {
            ans.insert(s);
            //cout << "checking " << s << endl;
        }
        s.erase(s.end()-1);
        return;
    }
    for (int i = 2 ; i < 4 ; i++ ) {
        fromBot(r+di[i], c+dj[i]);
    }
    s.erase(s.end()-1);
}

int main () {
    cin >> N;
    k = 0;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            cin >> grid[i][j];
        }
    }
    fromTop(0, 0);
    s = "";
    fromBot(N-1,N-1);
    cout << ans.size() << endl;
}
