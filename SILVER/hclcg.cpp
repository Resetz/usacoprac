#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> cards(2*n, false);
    vector<int> b;
    vector<int> e;

    int ans = 0 ;
    for (int i = 0 ; i < n ; i++) {
        int num;
        cin >> num;
        cards[num-1] = true;
        b.push_back(num);
    }

    for (int i = 0 ; i < 2*n ; i++) {
        if (!cards[i]) {
            e.push_back(i+1);
        }
    }
    sort(e.rbegin(), e.rend());



    vector<int> t1;
    vector<int> t2;
    for (int i = 0 ; i < n/2 ; i++) { 
       t1.push_back(e[i]);
    }
    sort(t1.begin(), t1.end());

    for (int i = 0 ; i < n/2 ; i++) { 
        t2.push_back(b[i]);
    }
    sort(t2.begin(), t2.end());


    //count
    //part 1 : count lower half (higher card wins)
    int p1;
    int p2;
    p1 = p2 = 0;
    while (p1 < n/2 && p2 < n/2 ) {
        while ( p1 < n/2 && t1[p1] < t2[p2] ) {
            p1++;
        }
        if (p1 == n/2) {
            break;
        }
        p1++;
        p2++;
        ans++;
    }

    //part 2 : count upper half (lower card wins)
    t1.clear();
    t2.clear();
    for (int i = n/2 ; i < n ; i++) { 
        t1.push_back(e[i]);
    }
    sort(t1.rbegin(), t1.rend());

    for (int i = n/2 ; i < n ; i++) { 
        t2.push_back(b[i]);
    }
    sort(t2.rbegin(), t2.rend());

    p1 = p2 = 0;
    while (p1 < n/2 && p2 < n/2 ) {
        while ( p1 < n/2 && t1[p1] > t2[p2] ) {
            p1++;
        }
        if (p1 == n/2) {
            break;
        }
        p1++;
        p2++;
        ans++;
    }
    cout << ans << endl;
}