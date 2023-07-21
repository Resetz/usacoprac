#include <iostream>
#include <vector>

using namespace std;

int n;


vector<vector<pair<int,string>>> precalc;

string s;

inline string conv(string from) {
    string res = from;
    if (res == "OW") {
        res = "C";
    } else if (res == "WO") {
        res = "C";
    } else if (res == "CO") {
        res = "W";
    } else if (res == "OC") {
        res = "W";
    } else if (res == "WC") {
        res = "O";
    } else if (res == "CW") {
        res = "O";
    } else if (res == "WW" || res == "CC" || res == "OO") {
        res = "";
    }
    return res;
}
int calls = 0;
string calc(int l, int r) {
    //calls++;
    if (l == r) {
        //cout << l << " to " << r << " is " << string(1, s[l]) << endl;
        precalc[l].push_back({r, string(1, s[l])});
        return string(1, s[l]);
    }
    string res = calc(l, (l+r)/2) + calc((l+r)/2+1, r);

    res = conv(res);
    //cout << l << " to " << r << " is " << res << endl;
    precalc[l].push_back({r, res});
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n = s.size();

    precalc.resize(n, vector<pair<int,string>>());

    calc(0, n-1);

    //cout << calls << endl;
    int q;
    cin >> q;
    for (int i = 0 ; i < q; i++) {
        string current = "";

        int f, t;
        cin >> f >> t;
        f--; t--;
        //cout << "here" << endl;
        int timesran =0 ;
        while (f <= t) {
            int l = 0;
            pair<int, string> good;
            while (l < precalc[f].size()) {
                if (precalc[f][l].first <= t) {
                    good = precalc[f][l];
                } else {
                    break;
                }
                l++;
            }
            //cout << f << " = {" << good.first << " " << good.second << "}" << endl;
            current += good.second;
            current = conv(current);
            f = good.first;
            f++;
        }
        if (current[0] == 'C') {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    cout << endl;
}