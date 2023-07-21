#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Compare
{
public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
        if (a.second > b.second) {
            return a.first > b.first;
        } else {
            return false;
        }
    }
};

int main() {
    int n; cin >> n;

    vector<pair<int,int>> v(n);
    vector<pair<int,int>> vx(n);
    vector<pair<int,int>> vy(n);
    for (int i = 0 ; i < n ; i++) {
        int a, b;
        cin >> a >> b;

        vx[i] = {a,b};
        vy[i] = {a,b};
    }

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end(), [](pair<int,int> a, pair<int,int> b) { return a.second < b.second; });

    multiset<pair<int,int>, Compare> l;
    multiset<pair<int,int>, Compare> r;
    r.insert(vx.begin(), vx.end());
    unsigned long long ans = n;
    for (int i = 0 ; i < n ; i++) {
        l.insert(vx[i]);
        r.erase(vx[i]);
        cout << vx[i].first << " " << vx[i].second << endl;
        /*while (i < n && vx[i].first == vx[i+1].first) {
            i++;
            l.insert(vx[i]);
            r.erase(vx[i]);
        }*/
        unsigned long long lsplit = 0;
        unsigned long long rsplit = 0;
        auto rptr = r.begin();
        int prev = -1;
        cout << l.size() << endl;
        for (auto cur : l) {
            //cout << prev << " " << cur.first << " " << cur.second << endl;
            /*if (prev == cur.second) {
                lsplit++; continue;
            }*/
            while (rptr != r.end() && (*rptr).second < cur.second) {
                rptr++;
                rsplit++;
            }
            cout << l.size() << " " << lsplit << " | " << r.size() << " " << rsplit << endl; 
            ans = min(ans, max(max(lsplit, l.size() - lsplit), max(rsplit, r.size() - rsplit)));
            lsplit++;
            prev = cur.second;
        }

        lsplit = rsplit = 0;
        prev = -1;
        auto lptr = l.begin();
        for (auto cur : r) {
            //cout << prev << " " << cur.second << endl;
            /*if (prev == cur.second) {
                rsplit++; continue;
            }*/
            while (lptr != l.end() && (*lptr).second < cur.second) {
                lptr++;
                lsplit++;
            }
            ans = min(ans, max(max(lsplit, l.size() - lsplit), max(rsplit, r.size() - rsplit)));
            rsplit++;
            prev = cur.second;
        }
        cout << endl;
    }
    cout << ans << endl;




}