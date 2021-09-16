#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <iomanip>
#define all(n) n.begin(), n.end()
using namespace std;

//#define comp
bool used[100000];
int main() {
    #ifdef comp
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<bool> used(n*2);
    vector<int> elise(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> elise[i];
        used[elise[i]-1] = true;
    }

    vector<int> bessie(n);
    int cnt = 0;
    for (int i = 0 ; i < n*2 ; i++) {
        if (!used[i]) {
            bessie[cnt] = i+1;
            cnt++;
        }
    } 
     //sort(all(elise));

    sort(elise.begin(), elise.begin() + n/2);
    sort(elise.begin() + n/2, elise.end(), [](int i, int j) -> int {
        return i > j;
    });

    sort(all(bessie), [](int i, int j) -> int {
        return i > j;
    });
    sort(bessie.begin(), bessie.begin() + n/2);
    long long pts = 0;
    
    int cur = 0;
    int eli = 0;
    do {
        if (bessie[cur] > elise[eli]) {
            pts++;
            cur++;
            eli++;
        } else {
            cur++;
        }
    } while (cur < n/2);
    cur = n/2;
    eli = n/2;
    do {
        if (bessie[cur] < elise[eli]) {
            pts++;
            cur++;
            eli++;
        } else {
            cur++;
        }
    } while (cur < n);
    cout << pts << endl;

}