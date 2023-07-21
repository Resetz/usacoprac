#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, qn;
    cin >> n >> qn;


    vector<pair<string,int>> v(n, {"", 0});
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(), v.end(), [](pair<string,int> a, pair<string,int> b) -> int {
        return a.first < b.first;
    });



    for (int i = 0 ; i < qn ; i++) {
        int p;
        string q;
        cin >> p >> q;
        p--;

        int low = 0;
        int high = n-1;
        int middle = -1;
        int good = -1;
        while (high >= low) {
            middle = low + (high - low)/2;

            //cout << middle << " " << q << " " << (q > v[middle].first) << " " << v[middle].first << endl;
            if (q <= v[middle].first) {
                //cout << q << " >= " << v[middle].first << endl;
                good = middle;
                high = middle-1;
            } else {
                low = middle+1;
            }
            //cout << high << "-" << low << endl;
        }
        //cout << "G " << good << " " << v[good].first << endl;

        int ans = -1;
        good += p;
        if (good < n && good >= 0) {
            bool works = true;
            for (int j = 0 ; j < q.size() ; j++) {
                if ( v[good].first[j] != q[j] ) {
                    works = false;
                    break;
                }
            }
            if (works) {
                ans = v[good].second;
            } 
        } else if (good == -1) ans = -1;
        cout << ans << endl;
    }
}