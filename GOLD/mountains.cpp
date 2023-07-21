#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cfloat>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }

    int q;
    cin >> q;
    for (int i = 0 ; i < q;  i++ ){
        int a,b;
        cin >> a >> b;
        a--;
        v[a] += b;
        long long ans = 0;
        stack<int> s;
        for (int j = 0 ; j < n ; j++) {
            s.push(j);
            double slope = DBL_MAX;
            int total = 0;
            if (v[s.top()] < v[j]) {
                while (s.size() > 0) {
                    double cur = (v[s.top()]-v[j])/((double)s.top()-j);
                    if (cur > slope) {
                        s.pop();
                        total++;
                    }
                    
                }
            }
            for (int k = j-1 ; k >= 0 ; k--) {
                if (cur <= slope) {
                    //cout << j << " " << k << " " << cur << endl;
                    ans++;
                    slope = cur;
                }
            }
            //cout << endl;
        }
        cout << ans << endl;
    }
}