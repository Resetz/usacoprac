#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;



typedef struct {
    int l,r,mid;
    int sizel, sizer;
} point;

string tolower(string s) {
    string ret = s;
    for (int i = 0 ; i < s.size() ; i++) {
        ret[i] = tolower(s[i]);
    }
    return ret;
}

/*
 * Complete the 'findARow' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING original
 *  2. STRING unused
 *  3. STRING rows
 */

string findARow(string original, string unused, string rows) {
    stringstream o(original);
    vector<string> v;
    while (true) {
        string s;
        o >> s;
        if (!o) break;
        string other = "";
        if (!(s[s.size()-1] >= 'A' && s[s.size()-1] <= 'Z' || s[s.size()-1] >= 'a' && s[s.size()-1] <= 'z')) {
            other = s[s.size()-1];
            s.pop_back();
        }
        v.push_back(s);
        if (other != "") v.push_back(other);
        
    }
    o.clear();
    o = stringstream(unused);
    set<string> unim = {".","!","?",",",";",":"};
    while (true) {
        string s;
        o >> s;
        if (!o) break;
        unim.insert(tolower(s));
    }

    int f,t;
    o = stringstream(rows);
    o >> f >> t;
    
    int l, r;
    l = 0; r = 0;
    int n = v.size();
    vector<point> table;

    int maxl, maxr;
    int maxcur;
    maxl = maxr = maxcur = 0;

    vector<int> pf(n+1);
    for (int i = 0 ; i < n ; i++) {
        pf[i+1] = pf[i] + v[i].size()+1;
        ////cout << pf[i+1] << endl;
    }
    ////cout << "here" << endl;
    for (int i = 0 ; i < n ; i++) {
        if (unim.find(tolower(v[i])) != unim.end()) {
            l = i+1;
            r = i+1;
            ////cout << "skipped " << v[i] << " at " << i << endl;
            continue;
        }
        while (r < n-1 && r < i+3) {
            if (unim.find(tolower(v[r+1])) != unim.end()) {
                break;
            }
            r++;
        }
        if (l < i-3) l++;
        int szl = pf[i]-pf[l]-1;
        int szr = pf[r+1]-pf[i+1]-1;
        table.push_back({l,r,i, max(0,szl), max(0,szr)});
        maxl = max(maxl, max(0,szl));
        maxcur = max(maxcur, (int)v[i].size());
        maxr = max(maxr, max(0,szr));
    }
    sort(table.begin(), table.end(),
    [&v](point a, point b) -> int {
        if (tolower(v[a.mid]) == tolower(v[b.mid])) {
            return a.mid < b.mid;
        }
        return tolower(v[a.mid]) < tolower(v[b.mid]);
    });
    f--;t--;

    auto val = [&v, &maxl, &maxr, &maxcur](point p) -> int {
        return maxl - p.sizel + maxr - p.sizer + maxcur - v[p.mid].size();
    };

    point best = table[f];
    int ind = f;
    for (int i = f+1 ; i <= t ; i++) {
        if (val(table[i]) < val(best)) {
            best = table[i];
            ind = i;
        }
    }

    stringstream ret;
    stringstream cur;
    for (int i = best.l ; i < best.mid ; i++) {
        cur << v[i];
        if (i != best.mid-1) {
            cur << " ";
        }
    }
    
    std::ios_base::fmtflags ff;
    ret << right << setw(maxl) << setfill('-') << cur.str() << resetiosflags(ff) << " ";
    ret << "<" << left << setw(maxcur) << v[best.mid] << resetiosflags(ff) << "> ";
    cur = stringstream();
    for (int i = best.mid+1 ; i < best.r+1 ; i++) {
        cur << v[i];
        if (i != best.r) {
            cur << " ";
        }
    } 
    ret << left << setw(maxr) << setfill('-') << cur.str();
    return ret.str();

}
int main()
{
    

    string original;
    getline(cin, original);

    string unused;
    getline(cin, unused);

    string rows;
    getline(cin, rows);

    string result = findARow(original, unused, rows);

    //cout << result << "\n";
    return 0;
}
