#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;



/*
 * Complete the 'findLastOctal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int findLastOctal(string s) {
    stringstream b;
    for (int i = 0 ; i < s.size() ; i++) {
        for (int j = 7 ; j >= 0 ; j--) {
            b << (bool)(((int)s[i]) & (1<<j));
        }
    }
    
    s = b.str();
    int num = 0;
    while (true) {
        stringstream ss;
        for (int i = num; i > 0; i >>= 1) {
            ss << (i&1);
        }
        string nstr = ss.str();
        if (num == 0) nstr = "0";
        reverse(nstr.begin(), nstr.end());
        pair<int,int> ind = {-1,-1};
        if (nstr.size() > s.size()) break;
        for (int i = 0 ; i <= s.size()-nstr.size(); i++) {
            bool good = true;
            for (int j = 0 ; j < nstr.size() ; j++) {
                if (s[i+j] != nstr[j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ind.first = i;
                break;
            }
        }
        for (int i = s.size()-nstr.size(); i >= 0 ; i--) {
            bool good = true;
            for (int j = 0 ; j < nstr.size() ; j++) {
                if (s[i+j] != nstr[j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ind.second = i;
                break;
            }
        }
        if (ind.first == -1) break;
        s.erase(ind.second, nstr.size());
        if (ind.first != ind.second) {
            s.erase(ind.first, nstr.size());
        }
        //cout << nstr << endl;
        //cout << s << endl;
        num++;
    }
    //cout << s << endl;
    stringstream o;
    for (int i = s.size()-1 ; i >= 0 ; i -= 3) {
        int val = 0;
        for (int j = i ; j >= max(0, i-2) ; j--) {
            //cout << s[j];
            val += (s[j] == '1') << (i-j);
        }
        //cout << " -> " << val << endl;
        o << val;
    }
    s = o.str();
    for (int i = s.size()-1 ; i >= 0 ; i--) {
        if (s[i] == '0') s.erase(i, 1);
        else break;
    }
    reverse(s.begin(), s.end());
    num = 0;
    while (true) {
        stringstream ss;
        for (int i = num; i > 0; i >>= 3) {
            ss << (i & (7));
        }
        string nstr = ss.str();
        if (num == 0) nstr = "0";
        reverse(nstr.begin(), nstr.end());
        pair<int,int> ind = {-1,-1};
        if (nstr.size() > s.size()) break;
        for (int i = 0 ; i <= s.size()-nstr.size(); i++) {
            bool good = true;
            for (int j = 0 ; j < nstr.size() ; j++) {
                if (s[i+j] != nstr[j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ind.first = i;
                break;
            }
        }
        for (int i = s.size()-nstr.size(); i >= 0 ; i--) {
            bool good = true;
            for (int j = 0 ; j < nstr.size() ; j++) {
                if (s[i+j] != nstr[j]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ind.second = i;
                break;
            }
        }
        if (ind.first == -1) break;
        s.erase(ind.second, nstr.size());
        if (ind.first != ind.second) {
            s.erase(ind.first, nstr.size());
        }
        //cout << nstr << endl;
        //cout << s << endl;
        num++;
    }
    //cout << s << endl;
    return num-1;
}

int main()
{
    string s;
    getline(cin, s);
    cout << findLastOctal(s) << endl;

    return 0;
}
