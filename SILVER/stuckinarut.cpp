#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct {
    int x,y;
    bool goingUp = false;
    int ind;
} cow_t;

int ans[1000] = {0};

int main() {
    int n;
    cin >> n;
    
    vector<cow_t> cows;
    vector<cow_t> cown;
    vector<cow_t> cowe;

    for (int i = 0 ; i < n ; i++) {
        char c;
        int x,y;
        cin >> c >> x >> y;
        cows.push_back({x,y,c == 'N',i});
        if (c=='N') {
            cown.push_back({x,y,c == 'N',i});
        } else {
            cowe.push_back({x,y,c == 'N',i});
        }
    }

    sort(cown.begin(), cown.end(), [](cow_t& a, cow_t& b) -> int { 
        return a.x < b.x;
    });
    sort(cowe.begin(), cowe.end(), [](cow_t& a, cow_t& b) -> int { 
        return a.y < b.y;
    });

    bool hasBeenStopped[1000] = {false};
    for (int i = 0 ; i < cowe.size() ; i++) {
        cow_t a = cowe[i];
        for (int j = 0 ; j < cown.size() ; j++) {
            cow_t b = cown[j];
            if (!hasBeenStopped[a.ind] && !hasBeenStopped[b.ind] && a.y > b.y && b.x > a.x) {
                if (a.y - b.y > b.x - a.x) {
                    //e stops n
                    hasBeenStopped[b.ind] = true;
                    ans[a.ind] += ans[b.ind] + 1;
                } else if (a.y - b.y < b.x - a.x){
                    hasBeenStopped[a.ind] = true;
                    ans[b.ind] += ans[a.ind] + 1;
                }
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        cout << ans[i] << endl;
    }
}