#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int highest = 0;
    for (int i = 0 ; i < n; i++) {
        cin >> v[i];
        highest = max(v[i], highest);
    }

    sort(v.begin(), v.end());

    int most3s = 0;
    int taketwos = 0;
    int takeones = 0;

    int ans = -1;
    for (int threes = max(highest/3-2, 0) ; threes < highest/3+2; threes++) {
        for (int twos = 0 ; twos <= 2 ; twos++) {
            for (int ones = 0 ; ones <= 2 ; ones++) {
                bool no = false;
                for (int i = 0 ; i < n; i++) {
                    if (v[i] == 1) {
                        if (ones >= 1) {
                            continue;
                        } else {
                            no = true;
                            break;
                        }
                    }
                    //case woooooooooooork
                    // we need to make threes twos and ones
                    int mod = v[i] % 3;
                    if (mod == 1) {
                        //use twos
                        if (threes >= v[i]/3-1 && twos >= 2 && v[i]/3-1 >= 0) {
                            continue;
                        } else if (threes >= v[i]/3 && ones >= 1) {
                            //use ones
                            continue;
                        } else if (threes >= v[i]/3-1 && twos >= 1 && ones >= 2 && v[i]/3-1 >= 0) {
                            continue;
                        } else {
                            no = true;
                            break;
                        }
                    } else if (mod == 2) {
                        if (threes >= v[i]/3-1 && twos >= 2 && ones >= 1 && v[i]/3-1 >= 0) {
                            continue;
                        } else if (threes >= v[i]/3 && twos >= 1) {
                            continue;
                        } else {
                            no = true;
                            break;
                        }
                    } else {
                        if (threes >= v[i]/3) {
                            continue;
                        } else if (threes >= v[i]/3-1 && twos >= 1 && ones >= 1 && v[i]/3-1 >= 0) {
                            continue;
                        } else if (threes >= v[i]/3-2 && twos >= 2 && ones >= 2 && v[i]/3-2 >= 0) {
                            continue;
                        } else {
                            no = true;
                            break;
                        }
                    }
                } 
                if (no) {
                    continue;
                } else {
                    //cout << threes << " " << twos << " " << ones << endl;
                    if (ans == -1) {
                        ans = threes + twos + ones;
                    }  else {
                        ans = min(threes + twos + ones, ans);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
int main() {
    int n;
    cin >> n;
    while (n--) solve();
}
